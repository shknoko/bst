#pragma once

#include <stdbool.h>

typedef struct Tree Tree;

Tree* newTree();
void freeNode(BstNode*);
void bstInsert(Tree*, int);
bool bstContains(Tree*, int);
void bstFree(Tree*);

void bstInorder(Tree*);
void bstPreorder(Tree*);
void bstPostorder(Tree*);

int bstHeight(Tree*);
int bstSize(Tree*);
// bstMin и bstMax возвращают 0 на пустом дереве
int bstMin(Tree*);
int bstMax(Tree*);
