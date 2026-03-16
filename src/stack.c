#include "stack.h"

#include <stdbool.h>
#include <stdlib.h>

typedef struct StackNode {
    BstNode* data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* head;
} Stack;

Stack* newStack(void)
{
    Stack* stack = calloc(1, sizeof(Stack));
    return stack;
}

bool isEmpty(const Stack* stack)
{
    return stack == NULL || stack->head == NULL;
}

bool push(Stack* stack, BstNode* data)
{
    StackNode* element = (StackNode*)calloc(1, sizeof(StackNode));

    if (element == NULL || stack == NULL) {
        free(element);
        return false;
    }

    element->data = data;
    element->next = stack->head;
    stack->head = element;

    return true;
}

BstNode* pop(Stack* stack)
{
    if (isEmpty(stack)) {
        return NULL;
    }

    StackNode* oldNode = stack->head;
    BstNode* data = oldNode->data;
    stack->head = stack->head->next;

    free(oldNode);

    return data;
}

BstNode* peek(const Stack* stack)
{
    if (isEmpty(stack)) {
        return NULL;
    }

    return stack->head->data;
}

void freeStack(Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}
