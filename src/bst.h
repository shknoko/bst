#pragma once

#include <stdbool.h>

typedef struct Tree Tree;
typedef struct Iterator Iterator;

Tree* newTree();
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

Iterator* iteratorInit(Tree*);
bool iteratorHasNext(Iterator*);
/**
 * @note проверять наличие следующего через iteratorHasNext
 * @param next следующий элемент итератора
 * @retval 1 при невозможности записать выходное значение
 * @retval 2 при итерации на пустом итераторе
 * @retval 3 при неудачном заполнении стека итератора
 * @retval 4 при неудачном восстановлении состояния стека итератора
 */
int iteratorNext(Iterator*, int*);
void iteratorFree(Iterator*);
