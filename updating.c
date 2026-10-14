#include <stdio.h>
#define MAX 3

int q[MAX];
int front = -1, rear = -1;

void update(int oldVal, int newVal) {
    if (front == -1 || front > rear) {
        printf("Queue is empty!!\n");
    } else {
        int found = 0;

        for (int i = front; i <= rear; i++) {
            if (q[i] == oldVal) {
                q[i] = newVal;
                printf("%d has been updated to %d\n",
                       oldVal, newVal);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%d was not found in the queue\n", oldVal);
        }
    }
}

int main() {
    q[0] = 10;
    q[1] = 20;
    q[2] = 30;
    front = 0;
    rear = 2;

    update(20, 25);

    return 0;
}