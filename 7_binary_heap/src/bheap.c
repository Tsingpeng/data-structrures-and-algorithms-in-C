#include <stddef.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

#include "defineType.h"
#include "bheap.h"

PriorityQueue Init(int MaxElement){//优先队列的初始化
    MaxElement = MaxElement>MINPQSIZE?MaxElement:MINPQSIZE;
    PriorityQueue H = (PriorityQueue)malloc(sizeof(struct BHeap));
    assert(H!=NULL);
    H->Capacity = MaxElement;//优先队列的总大小
    H->Size = 0;//初始大小为0
    H->Elements = (ElemType*)malloc(sizeof(ElemType)*(MaxElement+1));//数组大小Capacity+1:[0,capacityArray]
    assert(H->Elements!=NULL);
    H->Elements[0] = MINDATA;//Element[0]=-INF
    return H;
}

bool isEmpty(PriorityQueue H){//判断H是否为空
    return !(H->Size); 
}
bool isFull(PriorityQueue H){//判断H是否已满
    return H->Size == H->Capacity;
}

static void _fixUp(int index, PriorityQueue H){//对H中的第i个元素进行上滤操作
    ElemType *tmp = (ElemType*)malloc(sizeof(ElemType));
    while (index/2>0)//存在父节点,则是上滤
    {
        if (H->Elements[index/2]>H->Elements[index]){//如果父节点较大,则进行上滤交换
            (*tmp) = H->Elements[index/2];
            H->Elements[index/2] = H->Elements[index];
            H->Elements[index] = (*tmp);
        }
        index /= 2;
    }
    free(tmp);
    
} 

static void _fixDown(int index, PriorityQueue H){//对H中的第i个元素进行下滤操作
    ElemType *tmp = (ElemType*)malloc(sizeof(ElemType));
    while (index*2 <= H->Size){//下滤：下滤到叶子节点父节点，则最终index指向所需的叶子节点
        //找到左(右)子节点中的最小节点的位置
        int MinChild = index * 2;//单儿子节点或左儿子节点较小时，最小的儿子节点为左儿子节点
        if (MinChild != H->Size && H->Elements[MinChild+1]<H->Elements[MinChild]){//双儿子节点且右儿子节点较小时
            MinChild ++;//最小的儿子节点为右儿子节点
        }
        //下滤
        if(H->Elements[MinChild]<H->Elements[index]){
            (*tmp) = H->Elements[MinChild];
            H->Elements[MinChild] = H->Elements[index];
            H->Elements[index] = (*tmp);
        }
        index = MinChild;
    }
    free(tmp);
    
}

void Insert(ElemType X, PriorityQueue H){//将元素X插入到优先队列H中
    if (isFull(H)) perror("Out of Space");
    // int NewSpace = ++H->Size;//增加一个空位
    // int i = NewSpace;//
    // for (; X<H->Elements[i/2]; i/2){//上滤到合适的位置（从叶子向上进行值覆盖）
    //     H->Elements[i] = H->Elements[i/2];
    // }
    // H->Elements[i] = X;
    H->Elements[++H->Size] = X;
    _fixUp(H->Size, H);
}

ElemType FindMin(PriorityQueue H){//找到最小值
    return H->Elements[1];
}

ElemType DeleMin(PriorityQueue H){//删除最小值（下滤）
    if(isEmpty(H)){
        perror("No Elem. To Dele.");
        return H->Elements[0];
    }
    ElemType minNum = H->Elements[1];
    ElemType lastNum = H->Elements[H->Size--];
    H->Elements[1] = lastNum;
    _fixDown(1,H);
    return minNum;
}

void buildHeap(ElemType *list, int sz, PriorityQueue H){//Floyd Algorithm
    memcpy(H->Elements+1,list,sz*sizeof(ElemType));//将 list数组拷贝给Elements数组的[1:end]部分
    H->Size = sz;
    for (int i = sz/2;i>0;i--){//因叶节点不用下沉，从最后一个节点的父节点开始下沉，依次向上
        _fixDown(i,H);    
    }
}

void MakeEmpty(PriorityQueue H){//清空二叉堆
    H->Size = 0;
}

void Destroy(PriorityQueue H){//释放堆
    free(H->Elements);
    free(H);
}