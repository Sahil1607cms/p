#include <stdio.h>
#include <stdlib.h>
#define P 5   // number of processes (aircraft scheduling units)
#define R 3   // resources: Runways, GroundCrews, FuelTrucks

void calculateNeed(int need[P][R], int max[P][R], int alloc[P][R]) {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - alloc[i][j];
}

int isSafe(int processes[], int avail[], int max[][R], int alloc[][R]) {
    int need[P][R];
    calculateNeed(need, max, alloc);

    int finish[P] = {0};
    int safeSeq[P];
    int work[R];

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;

    while (count < P) {
        int found = 0;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[p][k];

                    safeSeq[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("System is NOT in a safe state.\n");
            return 0;
        }
    }

    printf("System is in a SAFE state.\nSafe sequence: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");

    return 1;
}

int main() {
    // Example resource matrices
    int max[P][R] = {
        {2, 1, 2},
        {1, 1, 1},
        {2, 1, 1},
        {1, 1, 2},
        {2, 1, 1}
    };

    int alloc[P][R] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1},
        {1, 0, 1},
        {0, 0, 0}
    };

    int avail[R] = {2, 1, 1};

    int processes[P] = {0,1,2,3,4};

    printf("=== Running Banker's Algorithm ===\n");
    isSafe(processes, avail, max, alloc);

    // Delay calculations
    double deadlocks_per_week = 3;
    double delay_per_deadlock_min = 15;

    double delay_no_avoidance_hours =
        (deadlocks_per_week * delay_per_deadlock_min) / 60.0;

    double delay_with_avoidance_hours = 0.0;  // Banker removes all deadlocks

    printf("\n=== Delay Analysis ===\n");
    printf("Without avoidance: %.2f hours/week delay\n",
            delay_no_avoidance_hours);
    printf("With Banker’s Algorithm: %.2f hours/week delay\n",
            delay_with_avoidance_hours);

    return 0;
}
