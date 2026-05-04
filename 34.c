#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node for stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    struct Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);
    return value;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for(int i = 0; exp[i] != '\0'; i++) {

        if(exp[i] == ' ')
            continue;

        // Operand
        if(isdigit(exp[i])) {
            int num = 0;
            while(isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(&stack, num);
            i--;
        }

        // Operator
        else {
            int b = pop(&stack);
            int a = pop(&stack);

            int result;

            if(exp[i] == '+')
                result = a + b;
            else if(exp[i] == '-')
                result = a - b;
            else if(exp[i] == '*')
                result = a * b;
            else if(exp[i] == '/')
                result = a / b;

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char expression[100];

    fgets(expression, sizeof(expression), stdin);

    int result = evaluatePostfix(expression);

    printf("%d", result);

    return 0;
}
