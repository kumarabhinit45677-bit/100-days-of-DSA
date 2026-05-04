#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int x)
{
    queue[++rear] = x;
}

int dequeue()
{
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int N, x;

    scanf("%d", &N);

    // enqueue elements
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    // move queue → stack
    for(int i = 0; i < N; i++)
    {
        push(dequeue());
    }

    // move stack → queue
    front = 0;
    rear = -1;

    while(top != -1)
    {
        enqueue(pop());
    }

    // print reversed queue
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
