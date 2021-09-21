#ifndef _DEFINETYPE_H_
#define _DEFINETYPE_H_

#include <stddef.h>

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef int ElemType; 
struct AvlNode
{
    ElemType elem;//元素值
    AvlTree Left;//左子树
    AvlTree Right;//右子树
    int height;//树的高度,注意不要将高度的类型设为size_t(unsigned ll),否则会出现比值错误
};
typedef AvlTree ElementType;//队列中元素使用的是节点指针
#define MAXQUE 100
#endif