#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 40000000

DWORD WINAPI MonteCarlo(LPVOID Param) {
    DWORD i, hit = 0;
    FLOAT x, y, result;
    srand(time(NULL));

    printf("Monte Carlo Simulation(Single Thread Program)\n");
    printf("LOOP COUNT = %d\n", COUNT);

    for (i = 0; i < COUNT; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            hit++;
        }
    }
    result = 4 * (double)hit / COUNT;
    printf("hit = %d\n", hit);
    printf("pi = (4 * %d) / 40000000 \n", hit);
    printf("pi = %f\n", result);
    return 0;
}

int main()
{
    clock_t start = clock();
    DWORD ThreadId;
    HANDLE ThreadHandle;

    ThreadHandle = CreateThread(
        NULL,
        0,
        MonteCarlo,
        NULL,
        0,
        &ThreadId
    );
    
    WaitForSingleObject(ThreadHandle, INFINITE);
    clock_t end = clock();
    printf("실행시간: %f초\n", (FLOAT)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
