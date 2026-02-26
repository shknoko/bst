#include "bst.h"

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BstNode {
    int data;
    struct BstNode* leftChild;
    struct BstNode* rightChild;
} BstNode;

typedef struct Tree {
    BstNode* root;
} Tree;

BstNode* newNode(int data)
{
    BstNode* node = (BstNode*)malloc(sizeof(BstNode));
    if (node == NULL) {
        return NULL;
    }

    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

Tree* newTree()
{
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if (tree == NULL) {
        return NULL;
    }

    tree->root = NULL;
    return tree;
}

int label(BstNode* node)
{
    if (node == NULL) {
        return INT_MIN;
    }

    return node->data;
}

void freeNode(BstNode* node)
{
    if (node == NULL) {
        return;
    }

    freeNode(node->leftChild);
    freeNode(node->rightChild);
    free(node);
}

bool bstContain(Tree* tree, int value)
{
    BstNode* current = tree->root;

    while (current != NULL) {
        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            current = current->leftChild;
        } else if (value > current->data) {
            current = current->rightChild;
        }
    }

    return false;
}

void bstInsert(Tree* tree, int value)
{

    if (tree->root == NULL) {
        tree->root = newNode(value);
    }

    BstNode* current = tree->root;

    while (true) {
        if (value == current->data) {
            return;
        }

        if (value < current->data) {
            if (current->leftChild = NULL) {
                current->leftChild = newNode(value);
                return;
            }

            current = current->leftChild;
        }

        else {
            if (current->rightChild == NULL) {
                current->rightChild = newNode(value);
                return;
            }

            current = current->rightChild;
        }
    }
}

void bstFree(Tree* tree)
{
}

static void bstInorderNode(BstNode* node)
{
    if (node == NULL) {
        return;
    }

    bstInorderNode(node->leftChild);
    printf("%d\n", label(node));
    bstInorderNode(node->rightChild);
}

void bstInorder(Tree* tree)
{
    if (tree == NULL) {
        return;
    }

    bstInorderNode(tree->root);
}

static void bstPreorderNode(BstNode* node)
{
    if (node == NULL) {
        return;
    }

    printf("%d\n", label(node));
    bstPreorderNode(node->leftChild);
    bstPreorderNode(node->rightChild);
}

void bstPreorder(Tree* tree)
{
    if (tree == NULL) {
        return;
    }

    bstPreorderNode(tree->root);
}

static void bstPostorderNode(BstNode* node)
{
    if (node == NULL) {
        return;
    }

    bstPostorderNode(node->leftChild);
    bstPostorderNode(node->rightChild);
    printf("%d\n", label(node));
}

void bstPostorder(Tree* tree)
{
    if (tree == NULL) {
        return;
    }

    bstPostorderNode(tree->root);
}
