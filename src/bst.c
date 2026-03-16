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

static BstNode* newNode(int data)
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

static int label(const BstNode* node)
{
    if (node == NULL) {
        return INT_MIN;
    }

    return node->data;
}

static void freeNode(BstNode* node)
{
    if (node == NULL) {
        return;
    }

    freeNode(node->leftChild);
    freeNode(node->rightChild);
    free(node);
}

bool bstContains(Tree* tree, int value)
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

bool bstInsert(Tree* tree, int value)
{
    if (tree == NULL) {
        return false;
    }

    if (tree->root == NULL) {
        tree->root = newNode(value);
        return tree->root != NULL;
    }

    BstNode* current = tree->root;

    while (true) {
        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            if (current->leftChild == NULL) {
                current->leftChild = newNode(value);
                return current->leftChild != NULL;
            }

            current = current->leftChild;
        } else {
            if (current->rightChild == NULL) {
                current->rightChild = newNode(value);
                return current->rightChild != NULL;
            }

            current = current->rightChild;
        }
    }
}

void bstFree(Tree* tree)
{
    if (tree == NULL) {
        return;
    }

    freeNode(tree->root);

    free(tree);
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

static int maxInt(int a, int b)
{
    return (a > b) ? a : b;
}

static int bstHeightNode(BstNode* node)
{
    if (node == NULL) {
        return 0;
    }

    return 1 + maxInt(bstHeightNode(node->leftChild), bstHeightNode(node->rightChild));
}

int bstHeight(Tree* tree)
{
    if (tree == NULL) {
        return 0;
    }

    return bstHeightNode(tree->root);
}

static int bstSizeNode(BstNode* node)
{
    if (node == NULL) {
        return 0;
    }

    return 1 + bstSizeNode(node->leftChild) + bstSizeNode(node->rightChild);
}

int bstSize(Tree* tree)
{
    if (tree == NULL) {
        return 0;
    }

    return bstSizeNode(tree->root);
}

int bstMin(Tree* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return INT_MIN; // при пустом дереве возвращает код ошибки INT_MIN
    }

    BstNode* current = tree->root;

    while (current->leftChild != NULL) {
        current = current->leftChild;
    }

    return current->data;
}

int bstMax(Tree* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return INT_MIN; // при пустом дереве возвращает код ошибки INT_MIN
    }

    BstNode* currtent = tree->root;

    while (currtent->rightChild != NULL) {
        currtent = currtent->rightChild;
    }

    return currtent->data;
}

static BstNode* getMinNode(BstNode* node)
{
    BstNode* current = node;
    while (current != NULL && current->leftChild != NULL) {
        current = current->leftChild;
    }
    return current;
}

static BstNode* bstDeleteNode(BstNode* root, int value)
{
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->leftChild = bstDeleteNode(root->leftChild, value);
    }

    else if (value > root->data) {
        root->rightChild = bstDeleteNode(root->rightChild, value);
    }

    else {
        if (root->leftChild == NULL) {
            BstNode* temp = root->rightChild;
            free(root);
            return temp;
        } else if (root->rightChild == NULL) {
            BstNode* temp = root->leftChild;
            free(root);
            return temp;
        }

        BstNode* temp = getMinNode(root->rightChild);

        root->data = temp->data;

        root->rightChild = bstDeleteNode(root->rightChild, temp->data);
    }

    return root;
}

void bstDelete(Tree* tree, int value)
{
    if (tree == NULL || tree->root == NULL) {
        return;
    }

    tree->root = bstDeleteNode(tree->root, value);
}

static bool bstMergeNode(const BstNode* node, Tree* tree)
{
    if (node == NULL) {
        return true;
    }

    return bstMergeNode(node->leftChild, tree) && bstInsert(tree, label(node)) && bstMergeNode(node->rightChild, tree);
}

Tree* bstMerge(const Tree* tree1, const Tree* tree2)
{
    if (tree1 == NULL && tree2 == NULL) {
        return NULL;
    }

    Tree* tree3 = newTree();
    if (tree3 == NULL) {
        return NULL;
    }

    if (tree1 != NULL) {
        if (!bstMergeNode(tree1->root, tree3)) {
            bstFree(tree3);
            return NULL;
        }
    }

    if (tree2 != NULL) {
        if (!bstMergeNode(tree2->root, tree3)) {
            bstFree(tree3);
            return NULL;
        }
    }

    return tree3;
}
