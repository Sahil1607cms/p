#include <stdio.h>
#include <stdlib.h>
#define P 3   
#define R 3   

int main() {
int i, j;

int max[P][R] = {{3, 2, 5},{3, 2, 5},{3, 2, 5}};

int allocation[P][R] = {{1, 0, 2},{2, 1, 1},{0, 1, 2}};

int available[R] = {1, 1, 1};  

int need[P][R];

printf("\nNeed matrix\n");
for (i = 0; i < P; i++) {
    for (j = 0; j < R; j++) {
        need[i][j] = max[i][j] - allocation[i][j];
    }
}

for (i = 0; i < P; i++) {
    for (j = 0; j < R; j++) {
        printf("%d ", need[i][j]);
    }
    printf("\n");
}

int finish[P] = {0, 0, 0};
int safeSeq[P];
int count = 0;

int work[R];
for (j = 0; j < R; j++)
    work[j] = available[j];

while (count < P) {
    int found = 0;

    for (i = 0; i < P; i++) {
        if (finish[i] == 0) {
            int canRun = 1;

             for (j = 0; j < R; j++) {
                if (need[i][j] > work[j]) {
                    canRun = 0;
                    break;
                } 
            }

            if (canRun == 1) {
                for (j = 0; j < R; j++)
                   work[j] += allocation[i][j];

                safeSeq[count++] = i;
                finish[i] = 1;
                found = 1;
            }
        }
    }

    if (found == 0) {
        printf("Not in safe statee\n");
        return 0;
    }
}

printf("Safe state.\nSafe sequence: ");
for (i = 0; i < P; i++)
printf("P%d ", safeSeq[i]);
printf("\n");

   
int deadlocks_per_week = 7 / 2;       
int downtime_per_deadlock = 20;       
int no_avoid_downtime = deadlocks_per_week * downtime_per_deadlock;
int avoid_downtime = 0;               

printf("\nDowntime\n");
printf("Without Banker: %d minutes/week\n", no_avoid_downtime);
printf("With Banker: %d minutes/week\n", avoid_downtime);

return 0;
}
