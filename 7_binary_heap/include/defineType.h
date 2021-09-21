#ifndef _DEFINETYPE_H_
#define _DEFINETYPE_H_
#include <limits.h>

#define MINPQSIZE 10
#define MINDATA INT_MIN
struct BHeap;//小顶堆
typedef struct BHeap *PriorityQueue;//用小顶堆实现的优先队列
typedef int ElemType;

struct BHeap{
    int Capacity;
    int Size;
    ElemType *Elements;
};

#endif