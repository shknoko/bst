#pragma once

#include <stdbool.h>

typedef struct BstNode BstNode;
typedef struct Tree Tree;

BstNode* newNode(int);
Tree* newTree();
void freeNode(BstNode*);
/**
 * @brief Вставляет значение в дерево, если значение уже есть, ничего не делает.
 */
void bstInsert(Tree*, int);
/**
 * @brief Возвращает true, если значение есть в дереве.
 * @return bool
 */
bool bstContains(Tree*, int);
/**
 * @brief Освобождает всю память, занятую деревом.
 */
void bstFree(Tree*);
int label(BstNode*);

void bstInorder(Tree*);
void bstPreorder(Tree*);
void bstPostorder(Tree*);

/**
 * @brief Измеряет высоту дерева.
 * @return Высоту дерева (при пустом дереве 0).
 */
int bstHeight(Tree*);
/**
 * @brief Измеряет количество узлов.
 * @return Количество узлов.
 */
int bstSize(Tree*);
/**
 * @brief Вычисляет Минимальное значение дерева.
 * @return Минимальное значение дерева (при пустом дереве возвращает INT_MIN).
 */
int bstMin(Tree*);
/**
 * @brief Вычисляет Максимальное значение дерева.
 * @return Максимальное значение дерева (при пустом дереве возвращает INT_MIN).
 */
int bstMax(Tree*);

/**
 * @brief Удаляет узел с заданным значением.
 */
void bstDelete(Tree* tree, int value);