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

void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    while(i < N)
    {
        struct node* current = queue[front++];

        if(arr[i] != -1)
        {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if(i < N && arr[i] != -1)
        {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    inorder(root);

    return 0;
}
