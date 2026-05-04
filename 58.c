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

// Build tree
struct node* build(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex)
{
    if(inStart > inEnd)
        return NULL;

    struct node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if(inStart == inEnd)
        return root;

    int pos;
    for(pos = inStart; pos <= inEnd; pos++)
    {
        if(inorder[pos] == root->data)
            break;
    }

    root->left = build(preorder, inorder, inStart, pos - 1, preIndex);
    root->right = build(preorder, inorder, pos + 1, inEnd, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int N;
    scanf("%d", &N);

    int preorder[N], inorder[N];

    for(int i = 0; i < N; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct node* root = build(preorder, inorder, 0, N - 1, &preIndex);

    postorder(root);

    return 0;
}
