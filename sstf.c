#include <stdio.h>
#include <stdlib.h>
int main() {
int queue[] = {45, 180, 90, 12, 150, 38, 60, 170};
int n = sizeof(queue) / sizeof(queue[0]);
int head = 55;

int visited[100] = {0};
int total_movement = 0;
int completed = 0;

while (completed < n) {
    int min_dist = 10000;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i]==0) {
            int dist = abs(queue[i] - head);
            if (dist < min_dist) {
                min_dist = dist;
                index = i;
            }
        }
    }

visited[index] = 1;
total_movement += abs(queue[index] - head);
head = queue[index];
completed++;
}

double seek_time = total_movement * 0.07;

printf("total head movement -  %d \n", total_movement);
printf("average seek time in ms - %.2f \n", seek_time);

    return 0;
}
