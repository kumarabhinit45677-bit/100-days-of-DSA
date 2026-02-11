#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
   
    int arr[n];

    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int pos;
    
    printf("Enter the position of the element to be deleted: ");
    scanf("%d", &pos);

    for(int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    for(int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);

    }

    return 0;
}
