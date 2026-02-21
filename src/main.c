#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    BST tree = { .root = NULL};

    bstInsert(&tree, 30);
    bstInsert(&tree, 50);
    bstInsert(&tree, 70);
    bstInsert(&tree, 20);
    bstInsert(&tree, 40);

    printf("Тест:\n");
    printf("Есть 30? %s\n", bstContains(&tree, 30)? "Да" : "Нет");
    printf("Есть 70? %s\n", bstContains(&tree, 70)? "Да" : "Нет");
    printf("Есть 50? %s\n", bstContains(&tree, 50)? "Да" : "Нет");
    printf("Есть 100? %s\n", bstContains(&tree, 100)? "Да" : "Нет");
    printf("Есть 20? %s\n", bstContains(&tree, 20)? "Да" : "Нет");

    bstInsert(&tree, 50);
    printf("Вставка повторно\n");
    printf("Есть 50? %s\n", bstContains(&tree, 50)? "Да" : "Нет");

    bstFree(&tree);

    return 0;
}