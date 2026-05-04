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

void bfs(struct node* adj[], int n, int start)
{
    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int queue[100];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        struct node* temp = adj[v];

        while(temp != NULL)
        {
            if(!visited[temp->data])
            {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    struct node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    for(int i = 0; i < m; i++)
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

    int s;
    scanf("%d", &s);

    bfs(adj, n, s);

    return 0;
}
