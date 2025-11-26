#include <stdio.h>

#define FRAMES 4

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int pages[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int n = sizeof(pages) / sizeof(pages[0]);

    int frames[FRAMES];
    int time[FRAMES];
    int counter = 0;
    int page_faults = 0;

    for (int i = 0; i < FRAMES; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int hit = 0;

        for (int j = 0; j < FRAMES; j++) {
            if (frames[j] == page) {
                hit = 1;
                time[j] = ++counter;   
                break;
            }
        }
        if (hit == 0) {
            int pos = findLRU(time, FRAMES);  

            frames[pos] = page;
            time[pos] = ++counter;

            page_faults++;
        }
    }

    printf("\total LRU page faults = %d\n", page_faults);
    return 0;
}
