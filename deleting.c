#include <stdio.h>
#define MAX 3

int q[MAX];
int front = -1, rear = -1;

void insert(int val) {
    if (rear == MAX - 1) {
        printf("Queue is full!!\n");
    } else {
        if (front == -1) {
            front = 0;
        }

        rear++;
        q[rear] = val;
    }
}

void deleteElement(int val) {
    if (front == -1) {
        printf("Queue is empty!!\n");
        return;
    }

    int pos = -1;

    for (int i = front; i <= rear; i++) {
        if (q[i] == val) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("%d not found in queue\n", val);
        return;
    }

    for (int i = pos; i < rear; i++) {
        q[i] = q[i + 1];
    }

    rear--;

    if (rear < front) {
        front = rear = -1;
    }

    printf("%d has been deleted\n", val);
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
    insert(10);
    insert(20);
    insert(30);

    printf("Original queue: ");
    display();

    deleteElement(20);

    printf("Updated queue: ");
    display();

    return 0;
}