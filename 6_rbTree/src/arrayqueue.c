#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arrayqueue.h"
/*定义部分*/
//extern ElementType;
struct QueueRecord
{
    int Capicity;//队列总容量
    int Size;//当前队列大小
    int Front;//队列首元素位置索引
    int Rear;//队列尾元素位置索引
    ElementType *array;//队列所用数组（模拟）
};

bool isEmpty(Queue Q){//判断是否为空队列
    return Q->Size == 0 ? true : false;
}

bool isFull(Queue Q){//判断是否队列已满
    return Q->Size == Q->Capicity ? true : false;
}

Queue createQueue(int maxElement){//创建队列
    int maxElements = maxElement>MinQueueSize ? maxElement : MinQueueSize;
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    Q->Capicity = maxElements;
    Q->Size = 0;
    Q->array = (ElementType*)malloc(maxElements*sizeof(ElementType));
    Q->Front = 1;
    Q->Rear = 0;
    return Q;
}

static int _succ(int Pos, Queue Q){//Succesor:循环数组的当前位置的下一位置|| 内部链接函数
    if ((Pos+1) == Q->Capicity){//Pos索引的最大值比Capicity的最大值小1。
        return 0;//达到数组的末尾则返回起始位置
    }
    return Pos + 1;
}

void disposeQueue(Queue Q){//销除队列
    free(Q->array);
    free(Q);
}

void makeEmpty(Queue Q){//复位队列
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

void enqueue(ElementType X, Queue Q){//从尾部（Rear）添加队列
    Q->Size ++;//队列大小加1
    Q->Rear = _succ(Q->Rear, Q);//得到Rear指向的待添加元素的位置
    Q->array[Q->Rear] = X;//添加元素
}

ElementType dequeue(Queue Q){//从头部（Front）取出元素
    if (!Q->Size){
        perror("dequeue Error: Empty Queue");
        return NULL;
    }
    Q->Size --;//队列大小减1
    ElementType tmp = Q->array[Q->Front];//取出元素
    Q->Front = _succ(Q->Front, Q);//得到Front取出元素后的位置
    return tmp;//返回取出的元素
}

ElementType front(Queue Q){//查看队首部元素
    if (!Q->Size){
        perror("front error: Empty queue cannot sear. front elem.");
        return NULL;
    }
    return Q->array[Q->Front];
}

ElementType rear(Queue Q){//查看队尾部元素
    if (!Q->Size){
        perror("rear error: Empty queue cannot sear. rear elem.");
        return NULL;
    }
    return Q->array[Q->Rear];
}

void printQue(Queue Q){
    int tmp_F = Q->Front;
    printf("F: ");
    while (Q->Front != Q->Rear+1){
        printf("%d ",front(Q));
        Q->Front = _succ(Q->Front, Q);
    }
    printf(":R\n");
    Q->Front = tmp_F;
}