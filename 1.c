#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n + 1];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos, x;
    
    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &pos);
    printf("Enter the element to be inserted: ");
    scanf("%d", &x);

    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;

    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
