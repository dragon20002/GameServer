#pragma once
#include "stdafx.h"

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mswsock.lib")
#pragma comment(lib, "Winmm.lib")

#include <WS2tcpip.h>
#include <WinSock2.h>
#include <mswsock.h>
#include <mmsystem.h>
#include <WS2spi.h>
#include <Mstcpip.h>

#include <windows.h>
#include <iostream>
#include <io.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdint>

#include <assert.h>
#include <fcntl.h>
#include <algorithm>
#include <functional>

#include <thread>
#include <mutex>
#include <memory>

#include <string>
#include <tchar.h>

#include <ctime>
#include <random>
#include <typeinfo>

// TODO: 공용 매크로
#if _DEBUG
#define CONTEXT_SWITCH Sleep(1) //전체 스레드를 대상으로 스위칭
#else
#define CONTEXT_SWITCH ::SwitchToThread() //스위칭 대상에서 OS 로부터 호출된 스레드는 제외
#endif

typedef void (*Function)(void *);

// 기타 유틸
#include "./Util/csv_parser/csv_parser.hpp"
#include "./Util/tinyXml/tinyxml.h"

// TODO: 필수 헤더
//#include "./Net/WinSocket.h"
#include "./Util/Type.h"
#include "./Util/Util.h"

#include "./Util/GameObject.h"
#include "./Util/Singleton.h"
#include "./Util/RandomMT.h"

#include "./Util/Clock.h"
#include "./Util/Logger.h"
#include "./Util/Assert.h"

#include "./Util/Table.h"
#include "./Util/Thread.h"
#include "./Util/Lock.h"
#include "./Util/ThreadJobQueue.h"
#include "./Util/Task.h"

#include "./Util/MemoryLeak.h"
#include "./Util/Memory_LowFragmentationHeap.h"
#include "./Util/Minidump.h"

#include "./Util/SMTPMail.h"
#include "./Util/Config.h"
#include "./Util/Monitoring.h"

// 패킷
//#include "./Net/Packet/Stream.h"
//#include "./Net/Packet/PacketHeader.h"
//#include "./Net/Packet/PacketClass.h"
//#include "./Net/Packet/PacketAnalyzer.h"
//#include "./Net/Packet/PacketFactory.h"
//#include "./Net/Packet/Package.h"

// 콘텐츠
//#include "./Contents/ContentsProcess.h"

// 서버
//#include "./Net/Session.h"
//#include "./Net/SessionManager.h"
//#include "./Net/Server.h"

//#include "./Net/Iocp/IOCPServer.h"
//#include "./Net/Iocp/IOCPSession.h"
//#include "./Net/SessionMonitor.h"

// 터미널
//#include "./Net/Terminal/TerminalSession.h"
//#include "./Net/Terminal/Terminal.h"
//#include "./Net/Terminal/TerminalManager.h"

// DB
//#include "./Database/ADODatabase.h"
//#include "./Database/Query.h"
//#include "./Database/DBManager.h"

// 전역변수
#include <Shutdown.h>
