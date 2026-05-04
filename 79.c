#include <stdio.h>
#include <limits.h>

#define MAX 100

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];

int minNode(int n)
{
    int min = INT_MAX, index = -1;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // init
    for(int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;

        for(int j = 1; j <= n; j++)
            adj[i][j] = INT_MAX;
    }

    int u, v, w;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove if directed
    }

    int source;
    scanf("%d", &source);

    dist[source] = 0;

    for(int i = 1; i <= n; i++)
    {
        int u = minNode(n);
        visited[u] = 1;

        for(int v = 1; v <= n; v++)
        {
            if(!visited[v] && adj[u][v] != INT_MAX)
            {
                if(dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    // print
    for(int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}
