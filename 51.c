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

// Insert into BST
struct node* insert(struct node* root, int val)
{
    if(root == NULL)
        return newNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct node* findLCA(struct node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    return root;
}

int main()
{
    int N;
    scanf("%d", &N);

    struct node* root = NULL;

    for(int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct node* lca = findLCA(root, n1, n2);

    if(lca != NULL)
        printf("%d", lca->data);

    return 0;
}
