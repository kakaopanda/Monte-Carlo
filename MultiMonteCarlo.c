#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10000000
DWORD hit[4];

DWORD WINAPI MonteCarlo1(LPVOID Param) {
    DWORD i = 0;
    FLOAT x, y;
    srand(time(NULL));

    printf("Monte Carlo Simulation<1>(Multi Thread Program)\n");
    printf("LOOP COUNT = %d\n", COUNT);

    for (i = 0; i < COUNT; i++) {
        x = (FLOAT)rand() / RAND_MAX;
        y = (FLOAT)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            hit[0]++;
        }
    }
    printf("HIT[0] = %d\n", hit[0]);
    return 0;
}

DWORD WINAPI MonteCarlo2(LPVOID Param) {
    DWORD i = 0;
    FLOAT x, y;
    srand(time(NULL));

    printf("Monte Carlo Simulation<2>(Multi Thread Program)\n");
    printf("LOOP COUNT = %d\n", COUNT);

    for (i = 0; i < COUNT; i++) {
        x = (FLOAT)rand() / RAND_MAX;
        y = (FLOAT)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            hit[1]++;
        }
    }
    printf("HIT[1] = %d\n", hit[1]);
    return 0;
}

DWORD WINAPI MonteCarlo3(LPVOID Param) {
    DWORD i = 0;
    FLOAT x, y;
    srand(time(NULL));

    printf("Monte Carlo Simulation<3>(Multi Thread Program)\n");
    printf("LOOP COUNT = %d\n", COUNT);

    for (i = 0; i < COUNT; i++) {
        x = (FLOAT)rand() / RAND_MAX;
        y = (FLOAT)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            hit[2]++;
        }
    }
    printf("HIT[2] = %d\n", hit[2]);
    return 0;
}

DWORD WINAPI MonteCarlo4(LPVOID Param) {
    DWORD i = 0;
    FLOAT x, y;
    srand(time(NULL));

    printf("Monte Carlo Simulation<4>(Multi Thread Program)\n");
    printf("LOOP COUNT = %d\n", COUNT);

    for (i = 0; i < COUNT; i++) {
        x = (FLOAT)rand() / RAND_MAX;
        y = (FLOAT)rand() / RAND_MAX;
        if (x * x + y * y <= 1) {
            hit[3]++;
        }
    }
    printf("HIT[3] = %d\n", hit[3]);
    return 0;
}

int main()
{
    FLOAT result = 0;
    DWORD total = 0;
    clock_t start = clock();

    DWORD ThreadId[4];
    HANDLE ThreadHandle[4];

    ThreadHandle[0] = CreateThread(
        NULL,
        0,
        MonteCarlo1,
        NULL,
        0,
        &ThreadId[0]
    );
 
    ThreadHandle[1] = CreateThread(
        NULL,
        0,
        MonteCarlo2,
        NULL,
        0,
        &ThreadId[1]
    );

    ThreadHandle[2] = CreateThread(
        NULL,
        0,
        MonteCarlo3,
        NULL,
        0,
        &ThreadId[2]
    );

    ThreadHandle[3] = CreateThread(
        NULL,
        0,
        MonteCarlo4,
        NULL,
        0,
        &ThreadId[3]
    );

    WaitForMultipleObjects(4, ThreadHandle, TRUE, INFINITE);
    total = hit[0] + hit[1] + hit[2] + hit[3];
    result = (FLOAT) (4 * total) / (4 * COUNT);
    printf("hit = %d\n", total);
    printf("pi = (4 * %d) / 40000000 \n", total);
    printf("pi = %f\n", result);
    printf("Total Hit = %d\n", total);

    clock_t end = clock();
    printf("실행시간: %f초\n", (FLOAT)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
