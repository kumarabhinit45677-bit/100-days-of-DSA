#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
struct Meeting {
    int start, end;
};

// Compare by start time
int cmp(const void* a, const void* b) {
    return ((struct Meeting*)a)->start - ((struct Meeting*)b)->start;
}

// Min-heap functions
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

// Push into heap
void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

// Pop min
void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Meeting arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Sort by start time
    qsort(arr, n, sizeof(struct Meeting), cmp);

    int heap[n];
    int size = 0;

    // First meeting
    push(heap, &size, arr[0].end);

    for (int i = 1; i < n; i++) {
        // If room free
        if (arr[i].start >= heap[0]) {
            pop(heap, &size);
        }
        // Allocate room
        push(heap, &size, arr[i].end);
    }

    printf("%d", size); // number of rooms

    return 0;
}