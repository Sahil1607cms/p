#include <stdio.h>

int main() {
    int requests[50], n, head, disk_size;
    int i, j, temp;
    int total_movement = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the requests:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    int index = 0;
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            index = i;
            break;
        }
    }

    printf("\nOrder of service (C-SCAN):\n");

    for (i = index; i < n; i++) {
        printf("%d ", requests[i]);
        total_movement += requests[i] - head;
        head = requests[i];
    }

    total_movement += (disk_size - 1) - head;
    head = 0;
    total_movement += (disk_size - 1);

    for (i = 0; i < index; i++) {
        printf("%d ", requests[i]);
        total_movement += requests[i] - head;
        head = requests[i];
    }

    printf("\n\nTotal Head Movement = %d\n", total_movement);

    return 0;
}
