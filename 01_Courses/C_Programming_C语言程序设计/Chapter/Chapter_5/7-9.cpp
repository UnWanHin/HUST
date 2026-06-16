#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct StackNode {
    float value;
    struct StackNode *next;
} StackNode;
StackNode *createNode(float value) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void push(StackNode **top, float value) {
    StackNode *newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}
float pop(StackNode **top) {
    if (*top == NULL) {
        exit(1);
    }
    StackNode *temp = *top;
    float value = temp->value;
    *top = (*top)->next;
    free(temp);
    return value;
}
int isEmpty(StackNode *top) {
    return top == NULL;
}
float evaluateRPN() {
    StackNode *top = NULL;
    char input[100];
    float operand1, operand2, result;
    while (scanf("%s", input)!= EOF) {
        if (isdigit(input[0]) || (input[0] == '-' && isdigit(input[1]))) {
            push(&top, atof(input));
        } else {
            operand2 = pop(&top);
            operand1 = pop(&top);
            switch (input[0]) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0) {
                    exit(1);
                }
                result = (int)(operand1 / operand2);
                break;
            default:
                exit(1);
            }
            push(&top, result);
        }
    }
    if (!isEmpty(top)) {
        result = pop(&top);
        if (isEmpty(top)) {
            return result;
        } else {
            exit(1);
        }
    } else {
        exit(1);
    }
}
int main() {
    float result = evaluateRPN();
    printf("%.0f\n", result);
    return 0;
}
