#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Rotate list right by k
struct Node* rotateRight(struct Node* head, int k) {

    if(head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find length and last node
    int length = 1;
    struct Node* tail = head;

    while(tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Step 2: Make it circular
    tail->next = head;

    // Step 3: Find new tail position
    k = k % length;
    int steps = length - k;

    struct Node* newTail = head;
    for(int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Step 4: Break circle
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Print list
void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, k;

    scanf("%d", &n);
    struct Node* head = createList(n);

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
