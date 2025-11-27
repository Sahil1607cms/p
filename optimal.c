#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n_pages, n_frames;
    int page_faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &n_frames);

    printf("Enter number of pages: ");
    scanf("%d", &n_pages);

    printf("Enter page reference string:\n");
    for (int i = 0; i < n_pages; i++)
        scanf("%d", &pages[i]);

    for (int i = 0; i < n_frames; i++)
        frames[i] = -1;

    for (int i = 0; i < n_pages; i++) {
        int page = pages[i];
        int hit = 0;

        for (int j = 0; j < n_frames; j++) {
            if (frames[j] == page) {
                hit = 1;
                break;
            }
        }

        if (hit==0) {
            int replace = -1, farthest = -1;

            for (int j = 0; j < n_frames; j++) {
                if (frames[j] == -1) {
                    replace = j;
                    break;
                }

                int next_use = -1;
                for (int k = i + 1; k < n_pages; k++) {
                    if (frames[j] == pages[k]) {
                        next_use = k;
                        break;
                    }
                }

                if (next_use == -1) {
                    replace = j;
                    break;
                }

                if (next_use > farthest) {
                    farthest = next_use;
                    replace = j;
                }
            }

            frames[replace] = page;
            page_faults++;
        }
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
