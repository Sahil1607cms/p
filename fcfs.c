#include <stdio.h>
#include <stdlib.h>

int main() {
int queue[] = {45, 180, 90, 12, 150, 38, 60, 170};
int n = sizeof(queue) / sizeof(queue[0]);
int head = 55;

int total_movement = 0;

for (int i = 0; i < n; i++) {
    total_movement += abs(queue[i] - head);
    head = queue[i];
}

float time_per_track = 0.07;   // ms
float avg_time = (total_movement * time_per_track);

printf("total head movement - %d\n", total_movement);
printf("average seek time in ms - %.3f\n", avg_time);

return 0;
}
