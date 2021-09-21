#ifndef _BHEAP_H_
#define _BHEAP_H_
#include <stdbool.h>
#include "defineType.h"
PriorityQueue Init(int MaxElement);//优先队列的初始化
void Destroy(PriorityQueue H);//释放堆
void MakeEmpty(PriorityQueue H);//清空二叉堆
void Insert(ElemType X, PriorityQueue H);//将元素X插入到优先队列H中（上滤）
ElemType DeleMin(PriorityQueue H);//删除最小值（下滤）
ElemType FindMin(PriorityQueue H);//找到最小值
bool isEmpty(PriorityQueue H);//判断H是否为空
bool isFull(PriorityQueue H);//判断H是否已满
void buildHeap(ElemType *list, int sz,PriorityQueue H);//Floyd Algorithm
#endif