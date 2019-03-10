// LoginServer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class SystemReport :public Work
{
	void tick()
	{
		Monitoring &moniter = Monitoring::getInstance();
		SLog(L"### cpu usage : %2.2f%%, memory usage : %uMbyte", moniter.processCpuUsage(), moniter.processMemUsage() / 1024 / 1024);
	}
};

void serverProcess()
{
	shared_ptr<Server> server(new IOCPServer(new LoginProcess()));

	SystemReport systemReport;
	const int MONITOR_REPORTING_SEC = 1;
	TaskManager::getInstance().add(&systemReport, MONITOR_REPORTING_SEC, TICK_INFINITY);

	if (!server->run()) {
		SLog(L"! error: server start fail");
		return;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	shared_ptr<Thread> serverThread(new Thread(new thread_t(serverProcess), L"Server"));
    return 0;
}

