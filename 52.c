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

// Find LCA in Binary Tree
struct node* findLCA(struct node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct node* left = findLCA(root->left, n1, n2);
    struct node* right = findLCA(root->right, n1, n2);

    if(left && right)
        return root;

    return (left != NULL) ? left : right;
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

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct node* lca = findLCA(root, n1, n2);

    if(lca != NULL)
        printf("%d", lca->data);

    return 0;
}
