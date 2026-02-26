#include "bst.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int label(bstNode* node)
{
    if (node == NULL) {
        return INT_MIN;
    }

    return node->data;
}

void freeNode(bstNode* node)
{
    if (node == NULL) {
        return;
    }

    freeNode(node->leftChild);
    freeNode(node->rightChild);
    free(node);
    return;
}

bool bstContain(Tree* tree, int value)
{
    bstNode* current = tree->root;

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

    bstNode* current = tree->root;

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

void bstInorder(Tree* tree)
{
    assert(tree != NULL);
    bstInorderNode(tree->root);
    return;
}

static void bstInorderNode(bstNode* node)
{
    if (node == NULL) {
        return;
    }

    bstInorderNode(node->leftChild);
    printf("%d\n", label(node));
    bstInorderNode(node->rightChild);
}

void bstPreorder(Tree* tree)
{
    assert(tree != NULL);
    bstPreorderNode(tree->root);
    return;
}

static void bstPreorderNode(bstNode* node)
{
    if (node == NULL) {
        return;
    }

    printf("%d\n", label(node));
    bstPreorderNode(node->leftChild);
    bstPreorderNode(node->rightChild);
}

void bstPostorder(Tree* tree)
{
    assert(tree != NULL);
    bstPostorderNode(tree->root);
    return;
}

static void bstPostorderNode(bstNode* node)
{
    if (node == NULL) {
        return;
    }

    bstPostorderNode(node->leftChild);
    bstPostorderNode(node->rightChild);
    printf("%d\n", label(node));
}
