#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include <defineType.h>
#include "avltree.h"
#include"arrayqueue.h"

int main()
{
    AvlTree T = NULL;
    // T = Insert(5,T);
    // T = Insert(3,T);
    // T = Insert(7,T);
    // T = Insert(2,T);
    // T = Insert(4,T);
    // T = Insert(6,T);
    // T = Insert(8,T);
    // T = Insert(1,T);
    // T = Insert(9,T);
    T = Insert(1,T);
    T = Insert(2,T);

    printf("%d\n",T->elem);
    BFS(T);
    printf("======\n");
    T = Delete(1,T);
    printf("======\n");
    BFS(T);
    printf("%d",T->height);
    return 0;
}
