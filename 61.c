#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[100][100] = {0};

    int u, v;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        // edge from u to v
        adj[u][v] = 1;

        // for undirected graph, also add reverse
        adj[v][u] = 1;
    }

    // print matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}

