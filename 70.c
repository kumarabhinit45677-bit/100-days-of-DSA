#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int m, struct Edge edges[], int src)
{
    int dist[MAX];

    // Step 1: Initialize
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    // Step 2: Relax edges V-1 times
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Detect negative cycle
    for (int j = 0; j < m; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Step 4: Print distances
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
}
