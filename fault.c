#include <stdio.h>
#include <stdlib.h>

#define FRAMES 4

int main() {
int pages[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
int n = sizeof(pages) / sizeof(pages[0]);
int frames_fifo[FRAMES];
int frames_lru[FRAMES];
int fifo_index = 0;

int used[FRAMES] = {0}; // For LRU tracking

int page_faults_fifo = 0;
int page_faults_lru  = 0;

    // Initialize frames
for (int i = 0; i < FRAMES; i++) {
    frames_fifo[i] = -1;
    frames_lru[i] = -1;
}

printf("Simulating FIFO and LRU with 4 frames...\n");
  
    // Loop through each page
    for (int i = 0; i < n; i++) {

        int page = pages[i];
        int hit = 0;

        // --------------------
        // FIFO Algorithm
        //---------------------
        hit = 0;
        for (int j = 0; j < FRAMES; j++) {
            if (frames_fifo[j] == page) {
                hit = 1;
                break;
            }
        }
        if (!hit) {
            frames_fifo[fifo_index] = page;
            fifo_index = (fifo_index + 1) % FRAMES;
            page_faults_fifo++;
        }

        // --------------------
        // LRU Algorithm
        //---------------------
        hit = -1;
        for (int j = 0; j < FRAMES; j++) {
            if (frames_lru[j] == page) {
                hit = j;
                break;
            }
        }

        if (hit != -1) {
            used[hit] = i;  // Update last-used time
        } else {
            int lru_index = 0;
            for (int j = 1; j < FRAMES; j++) {
                if (used[j] < used[lru_index]) {
                    lru_index = j;
                }
            }
            frames_lru[lru_index] = page;
            used[lru_index] = i;
            page_faults_lru++;
        }
    }

    printf("\nTotal FIFO page faults = %d\n", page_faults_fifo);
    printf("Total LRU page faults  = %d\n", page_faults_lru);

    return 0;
}
