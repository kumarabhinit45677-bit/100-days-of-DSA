#include <stdio.h>
#include <stdlib.h>

#define MAX 100000


typedef struct Node {
    long long key;
    long long count;
    struct Node* next;
} Node;

#define HASH_SIZE 100003

Node* hashTable[HASH_SIZE];

int hash(long long key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

void insert(long long key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp != NULL) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

long long getCount(long long key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp != NULL) {
        if (temp->key == key)
            return temp->count;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long prefixSum = 0;
    long long result = 0;

    insert(0);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        long long count = getCount(prefixSum);
        result += count;

        insert(prefixSum);
    }

    printf("%lld\n", result);

    return 0;
}