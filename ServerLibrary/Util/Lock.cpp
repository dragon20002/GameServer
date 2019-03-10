#include "stdafx.h"
#include "Lock.h"
#include "Thread.h"

#ifdef _DEBUG
#define STERN_MODE
#endif
const int INVALID_LINE = -1;

Lock::Lock(WCHAR *name)
{
	lockId_ = LockManager::getInstance().generalId();
	name_ = name;

	lockingFile_.clear();
	lockingLine_ = INVALID_LINE;
}

Lock::~Lock()
{
	name_.clear();
}

const WCHAR* Lock::name()
{
	return name_.c_str();
}

size_t Lock::lockId()
{
	return lockId_;
}

lock_t& Lock::mutex()
{
	return mutex_;
}

void Lock::lock(LPCWSTR fileName, int lineNo)
{
	mutex_.lock();

	lockingFile_ = fileName;
	lockingLine_ = lineNo;
}

void Lock::unlock()
{
	mutex_.unlock();

	lockingFile_.clear();
	lockingLine_ = INVALID_LINE;
}

void Lock::setThreadId(size_t id)
{
	threadId_ = id;
}

size_t Lock::threadId()
{
	return threadId_;
}

/**
생성자에서 락을 걸고, 스코프 빠져나가는 객체 해제 시 락을 푼다.
std::lock_guard<lock_t> guard(lock) 과 같음
데드락 감지를 위해 직접 구현
*/
LockSafeScope::LockSafeScope(Lock *lock, LPCWSTR fileName, int lineNo)
{
	if (lock == nullptr) {
		return;
	}
	if (_shutdown) {
		return;
	}

	lock_ = lock;
	Lock *deadLock = LockManager::getInstance().checkDeadLock(lock_);
	if (deadLock != nullptr) {
#ifdef STERN_MODE
		SErrLog(L"! [%s]lock and [%s]lock is dead detecting!", deadLock->name(), lock->name());
#else
		std::lock(lock_->mutex(), deadLock->mutex());
		SLog(L"!!! [%s]lock and [%s]lock is dead detecting!", deadLock->name(), lock->name());
#endif
		return;
	}

	lock_->lock(fileName, lineNo);
	lock_->setThreadId(GET_CURRENT_THREAD_ID());
}

LockSafeScope::~LockSafeScope()
{
	if (!lock_) {
		return;
	}
	if (_shutdown) {
		return;
	}
	lock_->unlock();
	lock_->setThreadId(0);
}

LockManager::LockManager()
{
	idSeed_ = 0;
}

Lock* LockManager::searchLockCycle(Lock *newLock)
{
	Thread *thread = ThreadManager::getInstance().at(GET_CURRENT_THREAD_ID());
	if (!thread) {
		return nullptr;
	}
	std::vector<Lock*> trace;
	trace.push_back(newLock);

	// list를 따라 lock 이름을 비교
	Lock *deadLock = nullptr;
	while (true) {
		Lock *threadLock = thread->lock();
		if (threadLock == nullptr) {
			break;
		}
		if (threadLock->lockId() == trace[0]->lockId()) {
			deadLock = threadLock;
			break;
		}
		trace.push_back(threadLock);
		thread = ThreadManager::getInstance().at(threadLock->threadId());
		if (!thread) {
			break;
		}
	}
	trace.clear();
	return deadLock;
}

Lock* LockManager::checkDeadLock(Lock *newLock)
{
	Lock *deadLock = this->searchLockCycle(newLock);
	if (deadLock) {
		return deadLock;
	}

	return nullptr;
}

size_t LockManager::generalId()
{
	size_t id = idSeed_++; //lock ID 생성
	return id;
}