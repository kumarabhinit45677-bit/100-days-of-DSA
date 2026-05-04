#include <stdio.h>

// Check if possible within given maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currentSum + arr[i] <= maxTime) {
            currentSum += arr[i];
        } else {
            painters++;
            currentSum = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int minTime(int arr[], int n, int k) {
    int max = arr[0], sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }

    int left = max, right = sum;
    int ans = sum;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1; // try smaller time
        } else {
            left = mid + 1;  // need more time
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", minTime(arr, n, k));

    return 0;
}