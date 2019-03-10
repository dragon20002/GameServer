#pragma once
#include "stdafx.h"

class SessionMonitor : public Work
{
public:
	SessionMonitor()
	{
		static bool init = false;
		if (init) {
			return;
		}
		init = true;

		const int MONITOR_REPORTING_SEC = 1;
		TaskManager::getInstance().add(this, MONITOR_REPORTING_SEC, TICK_INFINITY);
	}

	void tick()
	{
		// 10초 간 클라이언트가 세션의 Hearbeat를 갱신하지 않으면 접속을 끊는다.
#ifdef _DEBUG
		const int MAX_HEART_BEAT = 10000;
#else
		const int MAX_HEART_BEAT = 10;
#endif
		auto list = SessionManager::getInstance().sessionList();
		tick_t now = CLOCK.systemTick();

		for (auto session : list) {
			if (session->type() != SESSION_TYPE_CLIENT) {
				continue;
			}

			tick_t lastTick = session->heartBeat();
			if (now - lastTick > MAX_HEART_BEAT) {
				SLog(L"* [%S] Closing by heartBeat", session->clientAddress().c_str());
				session->onClose();
			}
		}
	}
};

static SessionMonitor *sessionMonitor = new SessionMonitor();