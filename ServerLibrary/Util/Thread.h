#pragma once
#include "stdafx.h"
#include <map>
#include <sstream>

#define MAKE_THREAD(className, process) (new Thread(new thread_t(&className##::##process, this), L#className))

#define GET_CURRENT_THREAD_ID std::this_thread::get_id().hash //이게 맞는지...

class Lock;
typedef std::function<void(void*)> ThreadFunction;

class Thread
{
	size_t			id_;
	wstr_t			name_;
	thread_t		*thread_;
	Lock			*lock_;		//현재 걸린 락

public:
	Thread(thread_t *thread, wstr_t name);
	~Thread();

	size_t id();
	wstr_t &name();

	void setLock(Lock *lock);
	Lock *lock();
};

//#define THREAD_POOL_HASHMAP
class ThreadManager : public Singleton<ThreadManager>
{
	// HACK: hash_map, unordered_map 에서 get할 때 버켓 index 에러 발생할 수도 있음. map을 사용한다.
#ifdef THREAD_POOL_HASHMAP
	hash_map<size_t, Thread*> threadPool_;
#else
	map<size_t, Thread*> threadPool_;
#endif

public:
	~ThreadManager();

	void put(Thread *thread);
	void remove(size_t id);
	Thread *at(size_t id);
};