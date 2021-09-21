#include <stdio.h>
#include "bheap.h"
int main(int argc, char const *argv[])
{
    printf("start Processing\n");
    PriorityQueue H = Init(100);//[15, 1, 3, 16, 2, 45, -3]
    // Insert(15,H);
    // Insert(1,H);
    // Insert(3,H);
    // Insert(16,H);
    // Insert(2,H);
    // Insert(45,H);
    // Insert(-3,H);
    // int sz = H->Size;
    // for (int i=0;i<sz;++i){
    //     int x = DeleMin(H);
    //     printf("%d ",x);
    // }printf("\n");
    ElemType list[] = {13,14,16,19,21,19,68,65,26,32,31};
    int sz = sizeof(list)/sizeof(ElemType);
    buildHeap(list,sz,H);

    for (int i=0;i<sz+1;++i){
        printf("%d ",H->Elements[i]);
    }printf("\n");
    for (int i=0;i<sz;++i){
        int x = DeleMin(H);
        printf("%d ",x);
    }printf("\n");
    return 0;
}

