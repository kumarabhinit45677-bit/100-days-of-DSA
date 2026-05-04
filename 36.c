#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

void enqueue(int value, int capacity) {
    if(size == capacity)
        return;

    rear = (rear + 1) % capacity;
    queue[rear] = value;
    size++;
}

void dequeue(int capacity) {
    if(size == 0)
        return;

    front = (front + 1) % capacity;
    size--;
}

void display(int capacity) {
    int i = front;
    int count = 0;

    while(count < size) {
        printf("%d ", queue[i]);
        i = (i + 1) % capacity;
        count++;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        enqueue(value, n);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        dequeue(n);
    }

    display(n);

    return 0;
}
