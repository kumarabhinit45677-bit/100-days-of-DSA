#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Zigzag traversal
void zigzag(struct node* root)
{
    if(root == NULL)
        return;

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 0;

    while(front < rear)
    {
        int size = rear - front;

        int temp[size];   // store current level

        for(int i = 0; i < size; i++)
        {
            struct node* curr = queue[front++];

            int idx;
            if(level % 2 == 0)
                idx = i;
            else
                idx = size - 1 - i;

            temp[idx] = curr->data;

            if(curr->left)
                queue[rear++] = curr->left;

            if(curr->right)
                queue[rear++] = curr->right;
        }

        // print level
        for(int i = 0; i < size; i++)
            printf("%d ", temp[i]);

        level++;
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    if(arr[0] == -1)
        return 0;

    struct node* root = newNode(arr[0]);

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    // Build tree
    while(i < N)
    {
        struct node* curr = queue[front++];

        if(arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < N && arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    zigzag(root);

    return 0;
}
