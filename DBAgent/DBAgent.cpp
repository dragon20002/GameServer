// DBAgent.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "DBAgentProcess.h"

void serverProcess()
{
	shared_ptr<Server> server(new IOCPServer(new DBAgentProcess()));
	if (!server->run()) {
		SLog(L"! error: server start fail");
		return;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	DBManager::getInstance().run();

	shared_ptr<Thread> serverThread(new Thread(new thread_t(serverProcess), L"DBAgent"));
    return 0;
}
