#include "stdafx.h"
#include "Session.h"
#include "Iocp/IOCPServer.h"

Session::Session()
{
	type_ = SESSION_TYPE_CLIENT;
	this->updateHearBeat();
}

Session::~Session()
{
	this->onClose();
}

// 3초 간격으로 세션이 살아있는지 확인하는 옵션 추가
// 3초 마다 체크 패킷을 보내고 응답이 없으면 세션을 닫는다.
bool Session::setSocketOpt()
{
#ifdef linux
	int keepAlive = 1;
	int keepAliveIdle = 1;
	int keepAliveCnt = 3;
	int keepAliveInterval = 3;

	int ret = ::setsockopt(socketData_.socket_, SOL_SOCKET, SO_KEEPALIVE, &keepAlive, sizeof(keepAlive));
	if (ret == SOCKET_ERROR) {
		return false;
	}
	ret = ::setsockopt(socketData_.socket_, SOL_TCP, SO_KEEPIDLE, &keepAliveIdle, sizeof(keepAliveIdle));
	if (ret == SOCKET_ERROR) {
		return false;
	}
	ret = ::setsockopt(socketData_.socket_, SOL_TCP, SO_KEEPCNT, &keepAliveCnt, sizeof(keepAliveCnt));
	if (ret == SOCKET_ERROR) {
		return false;
	}
	ret = ::setsockopt(socketData_.socket_, SOL_TCP, SO_KEEPINTVL, &keepAliveInterval, sizeof(keepAliveInterval));
	if (ret == SOCKET_ERROR) {
		return false;
	}
#else
	tcp_keepalive keepAliveSet = { 0 }, returned = { 0 };
	keepAliveSet.onoff = 1;
	keepAliveSet.keepalivetime = 3000;		// Keep Alive in 3 sec
	keepAliveSet.keepaliveinterval = 3000;	// Resend if No-Reply

	DWORD dwBytes;
	int retval = WSAIoctl(socketData_.socket_, SIO_KEEPALIVE_VALS,
		&keepAliveSet, sizeof(keepAliveSet),
		&returned, sizeof(returned),
		&dwBytes, NULL, NULL
	);
	if (retval != 0) {
		return false;
	}
#endif
	return true;
}

// 세션 내 데이터 세팅, 옵션 설정. IOCPServer의 onAccept에서 호출
bool Session::onAccept(SOCKET socket, SOCKADDR_IN addrInfo)
{
	socketData_.socket_ = socket;
	int addrLen;
	getpeername(socketData_.socket_, (struct sockaddr *)&socketData_.addrInfo_, &addrLen);
	socketData_.addrInfo_ = addrInfo;
	if (!this->setSocketOpt()) {
		return false;
	}

	return false;
}

void Session::onClose()
{
	SessionManager::getInstance().closeSession(this);
}

SOCKET& Session::socket()
{
	return socketData_.socket_;
}

str_t Session::clientAddress()
{
	array<char, SIZE_64> ip;
	inet_ntop(AF_INET, &(socketData_.addrInfo_.sin_addr), ip.data(), ip.size());
	return ip.data();
}

oid_t Session::id()
{
	return id_;
}

void Session::setId(oid_t id)
{
	id_ = id;
}

int8_t Session::type()
{
	return type_;
}

void Session::setType(int8_t type)
{
	type_ = type;
}

tick_t Session::heartBeat()
{
	return lastHeartBeat_;
}

void Session::updateHearBeat()
{
	lastHeartBeat_ = CLOCK.systemTick();
}
