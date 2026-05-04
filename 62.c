#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int v)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct node* adj[n];

    // initialize all lists
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        // add v to u
        struct node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // for undirected graph, also add u to v
        struct node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    // print adjacency list
    for(int i = 0; i < n; i++)
    {
        printf("%d: ", i);

        struct node* temp = adj[i];

        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }

    return 0;
}
