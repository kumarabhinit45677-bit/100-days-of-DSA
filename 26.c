#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create doubly linked list
struct Node* createList(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    head->prev = NULL;

    struct Node* current = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        newNode->prev = current;

        current->next = newNode;
        current = newNode;
    }

    return head;
}

// Traverse forward
void traverseForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createList(arr, n);

    traverseForward(head);

    return 0;
}