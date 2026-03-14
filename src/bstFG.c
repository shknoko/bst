#include <stdlib.h>
#include "bst.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct StackNode{
    bstNode *treeNode;
    struct StackNode *next;
}StackNode;

void push(StackNode **top, bstNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = node;
    newNode->next = *top;
    *top = newNode;
}

bstNode* pop(StackNode **top) {
    if (*top == NULL) return NULL;
    StackNode* temp = *top;
    bstNode* node = temp->treeNode;
    *top = temp->next;
    free(temp);
    return node;
}

bool bstIsValid(Tree *tree) {
    if(tree == NULL || tree->root == NULL){
        return true;
    }

    StackNode *stack = NULL;
    bstNode *curr = tree->root;
    bstNode *prevNode = NULL;
     while(curr != NULL || stack != NULL) {
        while(curr != NULL) {
            push(&stack, curr);
            curr = curr->leftChild;
        }

        curr = pop(&stack);

        if(prevNode != NULL && curr->data <= prevNode->data) {
            while(stack != NULL) pop(&stack);
            return false;
        }

        prevNode = curr;
        curr = curr->rightChild; 
    }
    return true;
}

static bstNode *kthMinRecursive(bstNode *root, int *k)
{
    if(root == NULL){
        return NULL;
    }
    bstNode *left = kthMinRecursive(root->leftChild, k);
if (left != NULL){
    return left;
}  

(*k)--;
if (*k == 0){
    return root;
}

return kthMinRecursive(root->rightChild, k);
}

int bstKthMin(Tree *tree, int k)
{
    if(tree == NULL || tree->root == NULL || k <= 0 || k > bstSize(tree)){
        return -1;
    }

    bstNode *result = kthMinRecursive(tree->root, &k);
    
    if(result != NULL){
        return result->data;
    } else {
        return -1;
    }
}

