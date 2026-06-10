#include <stdio.h>
#include <Windows.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    int* pNumber = (int*)lpParameter;
    printf("[스레드] main으로부터 전달된 값: %d\n", *pNumber);

    for (int i = 0; i < *pNumber; i++) {
        printf("[스레드] i = %d\n", i);
    }

    printf("Thread done");
    return 0;
}



int main()
{
    // Thread
    HANDLE hThread;
    DWORD dsThreaId;
    int nData = 100;

    printf("스레드를 생성합니다...\n");

    hThread = ::CreateThread(
        NULL,
        0,  // 0으로 지정하면 알아서 만듦
        ThreadProc,
        (LPVOID)&nData,
        0, // Thread 생성하자마자 바로 실행
        &dsThreaId
    );

    if (!hThread)
    {
        printf("Thread가 정상적으로 실행되지 않았습니다.\n");
        return -1;
    }

    for (int i = 0; i < 100; i++)
    {
        printf("[main] i = %d\n", i);
        // ::Sleep(10);    // 잠깐 대기
    }

    // hThread가 종료될 때까지 블로킹됨
    ::WaitForSingleObject(hThread, INFINITE);

    printf("프로그램이 안전하게 종료됩니다.\n");

    return 0;
}