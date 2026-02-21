#pragma once

typedef struct bstNode bstNode;
typedef struct Tree Tree;

bstNode* newNode(int);
Tree* newTree();
void bstInsert(Tree*, int);
bool bstContains(Tree*, int);
void bstFree(Tree*);