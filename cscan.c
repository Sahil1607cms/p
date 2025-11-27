#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int queue[] = {45, 180, 90, 12, 150, 38, 60, 170};
    int n = sizeof(queue) / sizeof(queue[0]);
    int head = 55;

    qsort(queue, n, sizeof(int), compare);

    int total_movement = 0;

    int i;
    for (i = 0; i < n; i++) {
        if (queue[i] >= head)
            break;
    }

    int pos = i;

    for (i = pos; i < n; i++) {
        total_movement += abs(queue[i] - head);
        head = queue[i];
    }

    total_movement += abs(199 - head);
    head = 199;

    total_movement += 199;
    head = 0;

    for (i = 0; i < pos; i++) {
        total_movement += abs(queue[i] - head);
        head = queue[i];
    }

    double seek_time = total_movement * 0.07;

    printf("Total head movement (CSCAN): %d tracks\n", total_movement);
    printf("Average seek time: %.2f ms\n", seek_time);

    return 0;
}
