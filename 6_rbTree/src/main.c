#include <stdio.h>
#include <stddef.h>
#include "defineType.h"
#include "rbtree.h"
// struct strT;
// typedef struct strT Nod;
// typedef Nod *Pos;
// struct strT{
//     int x;
//     Pos P;
// };
// void changeStr(Pos tmp){
//     Pos tmp3 = (Pos)malloc(sizeof(Nod));
//     tmp3->x=3;
//     tmp3->P=NULL;
//     tmp->P->P = tmp3;
// }
// void dele(int *num){
//     free(num);
// }

int main(int argc, char const *argv[])
{
    printf("Ready to start the Process\n");

    // Nod tmp = {.x=1,.P=NULL};
    // Nod tmp2 = {.x=2,.P=NULL};
    // tmp.P = &tmp2;
    // changeStr(&tmp);
    //int x = 1;
    RBTree RBT = InitRBT();
    ElemType nums[] = {11,2,14,1,7,15,5,8};//{5,3,7,1,6,9,8};
    size_t size = sizeof(nums)/sizeof(ElemType);
    for (size_t i=0;i<size;++i){
        RBT = RB_insert(RBT,nums[i]);
    }

    BFS(RBT);
    RBT = RB_deleteNum(RBT,2);
    BFS(RBT);
    // Position xx = (Position)malloc(sizeof(struct RBNode));
    // xx->elem = 1;
    // free(xx);
    printf("\n over \n");
    // int *yy = malloc(sizeof(int));
    // *yy = 1;
    // dele(yy);
    // printf("%d\n",*yy);
    return 0;
}
