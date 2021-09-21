#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#include "arrayqueue.h"
#include "defineType.h"
#include "searchTree.h"

int main()
{
    SearchTree T = NULL;
    T = Insert(6,T);
    T = Insert(2,T);
    T = Insert(8,T);
    T = Insert(1,T);
    T = Insert(5,T);
    T = Insert(3,T);
    T = Insert(4,T);
    // BFS(T);
    // T = Delete(6,T);
    BFS(T);
    Position P1 = FindMax(T);
    Position P2 = FindMin(T);
    printf("maxinum in Tree: %d\n",P1->elem);
    printf("mininum in Tree: %d\n",P2->elem);
    printf("==========\n");
    preorderTraversal(T);printf("\n");
    inorderTraversal(T);printf("\n");
    postorderTraversal(T);printf("\n");
    // printf("=======\n");
    // printf("%d ",T->Left->elem);
    // printf("%d ",T->Right->elem);
    // printf("%d ",T->Left->Right->Left->Right->elem);
    printf("\n=======\n");
    printf("the tree's height: %d",Height(T,Max));

    return 0;
}

