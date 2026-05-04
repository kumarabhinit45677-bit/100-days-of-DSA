#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct pair
{
    struct node* node;
    int hd;
};

struct node* newNode(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Vertical Order Traversal
void verticalOrder(struct node* root)
{
    if(root == NULL)
        return;

    struct pair queue[100];
    int front = 0, rear = 0;

    int map[200][100];   // store values
    int count[200] = {0};

    queue[rear++] = (struct pair){root, 100}; // offset to avoid negative index

    int min = 100, max = 100;

    while(front < rear)
    {
        struct pair curr = queue[front++];

        struct node* temp = curr.node;
        int hd = curr.hd;

        map[hd][count[hd]++] = temp->data;

        if(hd < min) min = hd;
        if(hd > max) max = hd;

        if(temp->left)
            queue[rear++] = (struct pair){temp->left, hd - 1};

        if(temp->right)
            queue[rear++] = (struct pair){temp->right, hd + 1};
    }

    // Print result
    for(int i = min; i <= max; i++)
    {
        for(int j = 0; j < count[i]; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

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

    verticalOrder(root);

    return 0;
}
