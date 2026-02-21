#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct bstNode {
    int data;
    struct bstNode* leftChild;
    struct bstNode* rightChild;
} bstNode;

typedef struct Tree {
    bstNode* root;
} Tree;

bstNode* newNode(int data)
{
    bstNode* node = (bstNode*)malloc(sizeof(bstNode));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

Tree* newTree()
{
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

int label(bstNode* node)
{
    if (node == NULL) {
        return 0;
    }

    return node->data;
}

void freeNode(bstNode* node)
{
    if (node == NULL) {
        return 0;
    }

    free(node->leftChild);
    free(node->rightChild);
    free(node);
    return 0;
}