/**
TerminalManager
ㄴ Terminal
	ㄴ TerminalSession : Session
*/
/**
서버 종류
- 세션/로그인 관리, 채팅서버 : 클라이언트 전체 세션 관리
- 중계(relay) 서버		 : 클라이언트를 월드에 적절히 분산시킴
- 방 / 월드 서버들		 : 클라이언트 접속 공간. 여러 월드가 중계 서버에 연결됨
- DB 중계 / 캐싱 서버	 : DB 연결 담당
- Billing 서버			 : 주로 외주나 외부 팀 모듈을 사용
- 로그 / 관리 서버		 : 서버 감시 프로그램. CPU, 메모리, CCU 등을 모니터링하거나 임의시간에 서버 재시작 기능
*/
#pragma once
#include "stdafx.h"

class TerminalSession :public Session
{
public:
	bool	connectTo(char *ip, int port);
	void	onSend(size_t transferSize);
	void	sendPacket(Packet* packet);
	Package* onRecv(size_t transferSize);
};