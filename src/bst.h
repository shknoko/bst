#pragma once

#include <stdbool.h>

typedef struct BstNode BstNode;
typedef struct Tree Tree;

BstNode* newNode(int);
Tree* newTree();
void freeNode(BstNode*);
void bstInsert(Tree*, int);
bool bstContains(Tree*, int);
void bstFree(Tree*);
int label(BstNode*);

void bstInorder(Tree*);
void bstPreorder(Tree*);
void bstPostorder(Tree*);

int bstHeight(Tree*);
int bstSize(Tree*);
// bstMin и bstMax возвращают 0 на пустом дереве
int bstMin(Tree*);
int bstMax(Tree*);