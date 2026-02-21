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
