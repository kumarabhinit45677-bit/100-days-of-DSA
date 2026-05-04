#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node* root)
{
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    if(arr[0] == -1)
    {
        printf("0");
        return 0;
    }

    struct node* root = newNode(arr[0]);

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

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

    printf("%d", height(root));

    return 0;
}
