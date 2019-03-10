#include "stdafx.h"
#include "LoginProcess.h"

LoginProcess::LoginProcess()
{
	this->registSubPacketFunc();
}

// 패킷을 처리할 함수포인터 등록
void LoginProcess::registSubPacketFunc()
{
	runFuncTable_.insert(make_pair(E_C_REQ_ID_PW, &LoginProcess::Packet_ID_PW));
	runFuncTable_.insert(make_pair(E_I_DB_ANS_ID_PW, &LoginProcess::IDB_Packet_ID_PW));
	runFuncTable_.insert(make_pair(E_C_REQ_CHATTING, &LoginProcess::Packet_Chatting));
}

// 패킷처리 정의
void LoginProcess::Packet_ID_PW(Session * session, Packet * rowPacket)
{
	PK_C_REQ_ID_PW *packet = (PK_C_REQ_ID_PW*)rowPacket;
	SLog(L"* id/pw packet: %S / %S", packet->id_.c_str(), packet->password_.c_str());

	PK_I_DB_REQ_ID_PW dbPacket;
	dbPacket.clientId_ = (UInt64)session->id();
	dbPacket.id_ = packet->id_;
	dbPacket.password_ = packet->password_;

	Terminal *terminal = TerminalManager::getInstance().terminal(L"DBAgent");
	terminal->sendPacket(&dbPacket);
}

void LoginProcess::IDB_Packet_ID_PW(Session * session, Packet * rowPacket)
{
	PK_I_DB_ANS_ID_PW *packet = (PK_I_DB_ANS_ID_PW*)rowPacket;
	SLog(L"id/pw result = %d", packet->result_);

	Session *clientSession = SessionManager::getInstance().session(packet->clientId_);
	if (clientSession == nullptr) {
		return;
	}
	PK_S_ANS_ID_PW ansPacket;
	ansPacket.result_ = packet->result_;
	clientSession->sendPacket(&ansPacket);
}

void LoginProcess::Packet_Chatting(Session * session, Packet * rowPacket)
{
	PK_C_REQ_CHATTING *packet = (PK_C_REQ_CHATTING*)rowPacket;
	SLog(L"* chatting packet: %S", packet->text_.c_str());

	PK_S_ANS_CHATTING retPacket;
	retPacket.id_ = "test";
	retPacket.text_ = "re : ";
	retPacket.text_ += packet->text_;

	SLog(L"* send message %S, %S", retPacket.id_.c_str(), retPacket.text_.c_str());
	session->sendPacket(&retPacket);
}
