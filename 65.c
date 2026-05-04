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

int dfs(struct node* adj[], int visited[], int v, int parent)
{
    visited[v] = 1;

    struct node* temp = adj[v];

    while(temp != NULL)
    {
        int neighbor = temp->data;

        if(!visited[neighbor])
        {
            if(dfs(adj, visited, neighbor, v))
                return 1;
        }
        else if(neighbor != parent)
        {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    struct node* adj[V];

    for(int i = 0; i < V; i++)
        adj[i] = NULL;

    int u, v;

    for(int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);

        // undirected graph
        struct node* n1 = createNode(v);
        n1->next = adj[u];
        adj[u] = n1;

        struct node* n2 = createNode(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    int visited[V];
    for(int i = 0; i < V; i++)
        visited[i] = 0;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(adj, visited, i, -1))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}
