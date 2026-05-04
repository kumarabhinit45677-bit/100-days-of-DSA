#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create circular linked list
struct Node* createCircularList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;

    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        current->next = newNode;
        current = newNode;
    }

    // Make it circular
    current->next = head;

    return head;
}

// Traverse circular list
void traverseCircular(struct Node* head) {
    if (head == NULL) return;

    struct Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createCircularList(arr, n);

    traverseCircular(head);

    return 0;
}