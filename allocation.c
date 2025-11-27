#include <stdio.h>

#define MAX 20

void printAllocation(int alloc[], int blockSize[], int processSize[], int n_blocks, int n_processes) {
    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < n_processes; i++) {
        printf("%d\t%d\t", i + 1, processSize[i]);
        if (alloc[i] != -1)
            printf("%d\n", alloc[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void firstFit(int blockSize[], int processSize[], int n_blocks, int n_processes) {
    int alloc[MAX];
    int blocks[MAX];

    for (int i = 0; i < n_blocks; i++)
        blocks[i] = blockSize[i];

    for (int i = 0; i < n_processes; i++)
        alloc[i] = -1;

    for (int i = 0; i < n_processes; i++) {
        for (int j = 0; j < n_blocks; j++) {
            if (blocks[j] >= processSize[i]) {
                alloc[i] = j;
                blocks[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\n--- First Fit ---\n");
    printAllocation(alloc, blockSize, processSize, n_blocks, n_processes);
}

void bestFit(int blockSize[], int processSize[], int n_blocks, int n_processes) {
    int alloc[MAX], blocks[MAX];

    for (int i = 0; i < n_blocks; i++)
        blocks[i] = blockSize[i];

    for (int i = 0; i < n_processes; i++)
        alloc[i] = -1;

    for (int i = 0; i < n_processes; i++) {
        int best = -1;
        for (int j = 0; j < n_blocks; j++) {
            if (blocks[j] >= processSize[i]) {
                if (best == -1 || blocks[j] < blocks[best])
                    best = j;
            }
        }

        if (best != -1) {
            alloc[i] = best;
            blocks[best] -= processSize[i];
        }
    }

    printf("\n--- Best Fit ---\n");
    printAllocation(alloc, blockSize, processSize, n_blocks, n_processes);
}

void worstFit(int blockSize[], int processSize[], int n_blocks, int n_processes) {
    int alloc[MAX], blocks[MAX];

    for (int i = 0; i < n_blocks; i++)
        blocks[i] = blockSize[i];

    for (int i = 0; i < n_processes; i++)
        alloc[i] = -1;

    for (int i = 0; i < n_processes; i++) {
        int worst = -1;
        for (int j = 0; j < n_blocks; j++) {
            if (blocks[j] >= processSize[i]) {
                if (worst == -1 || blocks[j] > blocks[worst])
                    worst = j;
            }
        }

        if (worst != -1) {
            alloc[i] = worst;
            blocks[worst] -= processSize[i];
        }
    }

    printf("\n--- Worst Fit ---\n");
    printAllocation(alloc, blockSize, processSize, n_blocks, n_processes);
}

int main() {
    int blockSize[MAX], processSize[MAX];
    int n_blocks, n_processes;

    printf("Enter number of blocks: ");
    scanf("%d", &n_blocks);

    printf("Enter block sizes:\n");
    for (int i = 0; i < n_blocks; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n_processes);

    printf("Enter process sizes:\n");
    for (int i = 0; i < n_processes; i++)
        scanf("%d", &processSize[i]);

    firstFit(blockSize, processSize, n_blocks, n_processes);
    bestFit(blockSize, processSize, n_blocks, n_processes);
    worstFit(blockSize, processSize, n_blocks, n_processes);

    return 0;
}
