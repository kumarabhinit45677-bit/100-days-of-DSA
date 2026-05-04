#include <stdio.h>

long long merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];

    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // count inversions
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back
    for (int x = 0; x < k; x++) {
        arr[left + x] = temp[x];
    }

    return inv_count;
}

long long mergeSort(int arr[], int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);

        inv_count += merge(arr, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long result = mergeSort(arr, 0, n - 1);

    printf("%lld", result);

    return 0;
}