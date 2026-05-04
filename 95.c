#include <stdio.h>
#include <stdlib.h>

// Node for linked list (bucket)
struct Node {
    float data;
    struct Node* next;
};

// Insert into sorted linked list (for bucket sorting)
void sortedInsert(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    // Create buckets
    struct Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i]; // since arr[i] in [0,1)
        sortedInsert(&buckets[index], arr[i]);
    }

    // Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[k++] = current->data;
            current = current->next;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}