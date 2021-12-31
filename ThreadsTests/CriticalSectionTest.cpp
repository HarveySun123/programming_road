#include <list>
#include <string>
#include <iostream>
#include <Windows.h>

CRITICAL_SECTION       g_cs;
int                    g_number = 0;

DWORD __stdcall WorkerThreadProc(LPVOID lpThreadParameter)
{
	DWORD dwThreadID = GetCurrentThreadId();

	while (true)
	{
		EnterCriticalSection(&g_cs);
		std::cout << "EnterCriticalSection, ThreadID: " << dwThreadID << std::endl;
		g_number++;
		SYSTEMTIME st;
		// ��ȡ��ǰϵͳʱ��
		GetLocalTime(&st);
		char szMsg[64] = { 0 };
		sprintf_s(szMsg,
			"[%04d-%02d-%02d %02d:%02d:%02d:%03d]NO.%d, ThreadID: %d.",
			st.wYear, st.wMonth, st.wDay,
			st.wHour, st.wMinute, st.wSecond, st.wMilliseconds,
			g_number, dwThreadID);

		std::cout << szMsg << std::endl;
		std::cout << "LeaveCriticalSection, ThreadID: " << dwThreadID << std::endl;
		LeaveCriticalSection(&g_cs);

		// ˯��1��
		Sleep(1000);
	}

	return 0;
}

int main()
{
	InitializeCriticalSection(&g_cs);

	HANDLE hWorkerThread1 = CreateThread(NULL, 0, WorkerThreadProc, NULL, 0, NULL);
	HANDLE hWorkerThread2 = CreateThread(NULL, 0, WorkerThreadProc, NULL, 0, NULL);

	WaitForSingleObject(hWorkerThread1, INFINITE);
	WaitForSingleObject(hWorkerThread2, INFINITE);

	// �ر��߳̾��
	CloseHandle(hWorkerThread1);
	CloseHandle(hWorkerThread2);

	DeleteCriticalSection(&g_cs);

	return 0;
}