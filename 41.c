#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct node *temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        char op[20];
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            dequeue();
        }
    }

    return 0;
}
