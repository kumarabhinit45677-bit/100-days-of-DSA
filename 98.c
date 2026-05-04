#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start, end;
};

// Sort by start time
int cmp(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(struct Interval), cmp);

    // Result array
    struct Interval result[n];
    int k = 0;

    // First interval
    result[k++] = arr[0];

    // Step 2: Merge
    for (int i = 1; i < n; i++) {
        struct Interval last = result[k - 1];

        if (arr[i].start <= last.end) {
            // Merge
            if (arr[i].end > last.end) {
                result[k - 1].end = arr[i].end;
            }
        } else {
            // No overlap
            result[k++] = arr[i];
        }
    }

    // Print result
    for (int i = 0; i < k; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}