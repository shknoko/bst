#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool bstContain(Tree* tree, int value)
{
    bstNode* current = tree->root;

    while (current != NULL)
    {
        if (value == current->data){
            return true;
        }
        else if (value < current->data){
            current = current->leftChild;
        }
        else if (value > current->data){
            current = current->rightChild;
        }
    }

    return false;
    
}

void bstInsert(Tree* tree, int value)
{
   

    if (tree->root == NULL){
        tree->root = newNode(value);
    }

     bstNode* current = tree->root;

    while (true)
    {
        if (value == current->data){
            return;
        }

        if (value < current->data){
            if (current->leftChild = NULL){
                current->leftChild = newNode(value);
                return;
            }

            current = current->leftChild;
        }

        else {
            if (current->rightChild == NULL){
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