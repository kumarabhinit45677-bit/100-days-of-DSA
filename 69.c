#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int to, weight;
    struct Edge* next;
};

struct Edge* adj[MAX];

// create edge
struct Edge* createEdge(int v, int w)
{
    struct Edge* newNode = (struct Edge*)malloc(sizeof(struct Edge));
    newNode->to = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// add edge
void addEdge(int u, int v, int w)
{
    struct Edge* e = createEdge(v, w);
    e->next = adj[u];
    adj[u] = e;
}

// Min Heap Node
struct HeapNode {
    int vertex, dist;
};

struct HeapNode heap[MAX];
int size = 0;

// swap
void swap(struct HeapNode* a, struct HeapNode* b)
{
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// heapify up
void heapifyUp(int i)
{
    while (i > 0 && heap[(i-1)/2].dist > heap[i].dist)
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// heapify down
void heapifyDown(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// push
void push(int v, int dist)
{
    heap[size].vertex = v;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

// pop min
struct HeapNode pop()
{
    struct HeapNode root = heap[0];
    heap[0] = heap[size-1];
    size--;
    heapifyDown(0);
    return root;
}

// Dijkstra
void dijkstra(int V, int src)
{
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    push(src, 0);

    while (size > 0)
    {
        struct HeapNode node = pop();
        int u = node.vertex;

        struct Edge* temp = adj[u];

        while (temp != NULL)
        {
            int v = temp->to;
            int w = temp->weight;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // print result
    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
}
