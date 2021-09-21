#ifndef _ARRAYQUEUE_H_
#define _ARRAYQUEUE_H_
#include <stdbool.h>
#include "defineType.h"
#define MinQueueSize (1)//队列的最小长度
/*
    使用数组的队列实现:使用循环数组进行实现
*/
/*声明部分*/
struct QueueRecord;
typedef struct QueueRecord *Queue;

bool isEmpty(Queue Q);//判断是否为空队列
bool isFull(Queue Q);//判断是否队列已满
Queue createQueue(int maxElements);//创建队列
void disposeQueue(Queue Q);//销除队列
void makeEmpty(Queue Q);//复位队列
void enqueue(ElementType X, Queue Q);//从尾部（Rear）添加队列
ElementType dequeue(Queue Q);//从头部（Front）取出元素
ElementType front(Queue Q);//查看队首部元素
ElementType rear(Queue Q);//查看队尾部元素



#endif