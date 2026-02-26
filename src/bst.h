#pragma once

#include <stdbool.h>

typedef struct bstNode bstNode;
typedef struct Tree Tree;

bstNode* newNode(int);
Tree* newTree();
void freeNode(bstNode*);
void bstInsert(Tree*, int);
bool bstContains(Tree*, int);
void bstFree(Tree*);
int label(bstNode*);

void bstInorder(Tree*);
void bstPreorder(Tree*);
void bstPostorder(Tree*);

int bstHeight(Tree*);
int bstSize(Tree*);
// bstMin и bstMax возвращают 0 на пустом дереве
int bstMin(Tree*);
int bstMax(Tree*);