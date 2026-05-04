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

// Check mirror
int isMirror(struct node* t1, struct node* t2)
{
    if(t1 == NULL && t2 == NULL)
        return 1;

    if(t1 == NULL || t2 == NULL)
        return 0;

    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct node* root)
{
    if(root == NULL)
        return 1;

    return isMirror(root->left, root->right);
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
        printf("YES");
        return 0;
    }

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

    if(isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}
