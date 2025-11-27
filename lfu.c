#include <stdio.h>

#define FRAMES 4

int findLFU(int freq[], int time[], int n) {
int minFreq = freq[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (freq[i] < minFreq) {
            minFreq = freq[i];
            pos = i;
        } else if (freq[i] == minFreq) {
            if (time[i] < time[pos]) {
                pos = i;
            }
        }
    }
return pos;
}

int main() {
int pages[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
int n = sizeof(pages) / sizeof(pages[0]);

int frames[FRAMES];
int freq[FRAMES];
int time[FRAMES];
int counter = 0;
int page_faults = 0;

for (int i = 0; i < FRAMES; i++) {
    frames[i] = -1;
    freq[i] = 0;
    time[i] = 0;
}

for (int i = 0; i < n; i++) {
    int page = pages[i];
    int hit = 0;

    for (int j = 0; j < FRAMES; j++) {
       if (frames[j] == page) {
            hit = 1;
            freq[j]++;
           time[j] = ++counter;
           break;
        }
    }

   if (hit == 0) {
        int pos = findLFU(freq, time, FRAMES);
        frames[pos] = page;
        freq[pos] = 1;
        time[pos] = ++counter;
        page_faults++;
    }
}

printf("\nTotal LFU page faults = %d\n", page_faults);
return 0;
}
