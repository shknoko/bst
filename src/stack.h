#pragma once
#include <stdbool.h>

typedef struct Stack Stack;
typedef struct BstNode BstNode;

Stack* newStack(void);
bool isEmpty(const Stack*);
bool push(Stack*, BstNode*);
BstNode* pop(Stack*);
BstNode* peek(const Stack*);
void freeStack(Stack*);