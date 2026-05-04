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
struct node* build(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex)
{
    if(inStart > inEnd)
        return NULL;

    struct node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if(inStart == inEnd)
        return root;

    int pos;
    for(pos = inStart; pos <= inEnd; pos++)
    {
        if(inorder[pos] == root->data)
            break;
    }

    // IMPORTANT: build right first
    root->right = build(inorder, postorder, pos + 1, inEnd, postIndex);
    root->left  = build(inorder, postorder, inStart, pos - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct node* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int N;
    scanf("%d", &N);

    int inorder[N], postorder[N];

    for(int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);

    for(int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);

    int postIndex = N - 1;

    struct node* root = build(inorder, postorder, 0, N - 1, &postIndex);

    preorder(root);

    return 0;
}
