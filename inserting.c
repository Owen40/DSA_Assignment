#include <stdio.h>
#define MAX 3

int q[MAX];
int front = -1, rear = -1;

void insert(int val, int pos) {
    if (rear == MAX - 1) {
        printf("Queue is full!!\n");
        return;
    }

    if (pos < 0 || pos > rear - front + 1) {
        printf("Invalid position!!\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
        q[front] = val;
    } else {
        int index = front + pos;

        for (int i = rear; i >= index; i--) {
            q[i + 1] = q[i];
        }

        q[index] = val;
        rear++;
    }

    printf("%d inserted at position %d\n", val, pos);
}

void display() {
    if (front == -1) {
        printf("Queue is empty!!\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    insert(10, 0);
    insert(30, 1);
    insert(20, 1);

    display();

    return 0;
}