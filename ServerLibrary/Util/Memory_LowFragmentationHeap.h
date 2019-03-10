#pragma once
#include "stdafx.h"

// http://msdn.microsoft.com/ko-kr/library/windows/desktop/aa366750(v=vs.85).aspx
class LowFragmentationHeap
{
public:
	// Low-fragmentation Heap ¼³Á¤ On
	LowFragmentationHeap()
	{
		static bool init = false;
		if (init) {
			return;
		}
		init = true;

		ULONG HeapFragValue = 2;
		HANDLE hHeaps[100];
		DWORD dwHeapCount = GetProcessHeaps(100, hHeaps);

		for (DWORD i = 0; i < dwHeapCount; i++) {
			HeapSetInformation(hHeaps[i], HeapCompatibilityInformation, &HeapFragValue, sizeof(HeapFragValue));
		}
		printf("! Low-fragmentation Heap setting\n");
	}
};

static LowFragmentationHeap lfh;


class TestObject
{
	int a[1024];
	char b[1024];

	void test()
	{
		int count = 10080808;
		LARGE_INTEGER startTick, endTick, frequency;
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&startTick);

		for (int i = 0; i < count; i++) {
			TestObject *obj = new TestObject();
			delete obj;
		}

		QueryPerformanceCounter(&endTick);
		printf("Time : %lf\n", (double)(endTick.QuadPart - startTick.QuadPart) / (double)frequency.QuadPart);
	}

	//int _tmain(int argc, _TCHAR* argv[])
	//{
	//  TestObject testObj;
	//	testObj.test();

	//	LowFragmentationHeap lfh;
	//	testObj.test();

	//	return 0;
	//}
};