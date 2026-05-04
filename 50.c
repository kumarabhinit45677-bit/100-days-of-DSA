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

// Search in BST
struct node* search(struct node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main()
{
    int N, key;
    scanf("%d", &N);

    struct node* root = NULL;

    for(int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &key);

    struct node* result = search(root, key);

    if(result != NULL)
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
