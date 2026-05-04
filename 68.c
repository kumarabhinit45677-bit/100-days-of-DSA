#include <stdio.h>

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[V][V];
    int indegree[V];

    // initialize
    for (int i = 0; i < V; i++)
    {
        indegree[i] = 0;
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    int u, v;

    // input edges (directed)
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // queue
    int queue[V];
    int front = 0, rear = 0;

    // push nodes with indegree 0
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int topo[V];
    int count = 0;

    // BFS
    while (front < rear)
    {
        int node = queue[front++];
        topo[count++] = node;

        for (int i = 0; i < V; i++)
        {
            if (adj[node][i] == 1)
            {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // check cycle
    if (count != V)
    {
        printf("Cycle exists\n");
        return 0;
    }

    // print topo order
    for (int i = 0; i < V; i++)
        printf("%d ", topo[i]);

    return 0;
}
