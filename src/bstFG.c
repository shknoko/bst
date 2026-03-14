#include "bst.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct StackNode {
    bstNode* treeNode;
    struct StackNode* next;
} StackNode;

void push(StackNode** top, bstNode* node)
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = node;
    newNode->next = *top;
    *top = newNode;
}

bstNode* pop(StackNode** top)
{
    if (!*top)
        return NULL;
    StackNode* temp = *top;
    bstNode* node = temp->treeNode;
    *top = temp->next;
    free(temp);
    return node;
}

bool bstIsValid(Tree* tree)
{
    if (!tree || !tree->root)
        return true;

    StackNode* stack = NULL;
    bstNode* curr = tree->root;
    bstNode* prevNode = NULL;

    while (curr || stack) {
        while (curr) {
            push(&stack, curr);
            curr = curr->leftChild;
        }

        curr = pop(&stack);

        if (prevNode && curr->data <= prevNode->data) {
            while (stack)
                pop(&stack);
            return false;
        }

        prevNode = curr;
        curr = curr->rightChild;
    }
    return true;
}

static bstNode* kthMinRecursive(bstNode* root, int* k)
{
    if (!root)
        return NULL;

    bstNode* left = kthMinRecursive(root->leftChild, k);
    if (left)
        return left;

    (*k)--;
    if (*k == 0)
        return root;

    return kthMinRecursive(root->rightChild, k);
}

int bstKthMin(Tree* tree, int k)
{
    if (!tree || !tree->root || k <= 0 || k > bstSize(tree))
        return -1;

    bstNode* result = kthMinRecursive(tree->root, &k);

    if (result)
        return result->data;
    return -1;
}
