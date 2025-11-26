#include <stdio.h>

#define FRAMES 4

int main() {
int pages[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
int n = sizeof(pages)/sizeof(pages[0]);
int frames[FRAMES];
int f_index = 0;
int page_faults = 0;

for (int i = 0; i < FRAMES; i++) {
    frames[i] = -1;
}

for (int i = 0; i < n; i++) {

    int page = pages[i];
    int hit = 0;
    for (int j = 0; j < FRAMES; j++) {
        if (frames[j] == page) {
            hit = 1;
             break;
           }
    }

    if (hit == 0) {
        frames[f_index] = page;           
        f_index = (f_index + 1) % FRAMES;
        page_faults++;
    }
}

printf("\ttotal fifo page faults = %d\n", page_faults);

return 0;
}
