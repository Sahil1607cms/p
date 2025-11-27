#include <stdio.h>

int main() {
    int pages[50], frames[10], ref_bit[10];
    int n_pages, n_frames;
    int pointer = 0, page_faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &n_frames);

    printf("Enter number of pages: ");
    scanf("%d", &n_pages);

    printf("Enter page reference string:\n");
    for (int i = 0; i < n_pages; i++)
        scanf("%d", &pages[i]);

    for (int i = 0; i < n_frames; i++) {
        frames[i] = -1;
        ref_bit[i] = 0;
    }

    for (int i = 0; i < n_pages; i++) {
        int page = pages[i];
        int hit = 0;

        for (int j = 0; j < n_frames; j++) {
            if (frames[j] == page) {
                ref_bit[j] = 1;   // give second chance
                hit = 1;
                break;
            }
        }

        if (!hit) {
            while (1) {
                if (ref_bit[pointer] == 0) {
                    frames[pointer] = page;
                    ref_bit[pointer] = 1;
                    pointer = (pointer + 1) % n_frames;
                    page_faults++;
                    break;
                } else {
                    ref_bit[pointer] = 0;
                    pointer = (pointer + 1) % n_frames;
                }
            }
        }
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
