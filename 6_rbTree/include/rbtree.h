#ifndef _RBTREE_H_
#define _RBTREE_H_
#include "defineType.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

RBTree InitRBT();//Initialize the RBT
Position RB_find(Position root, ElemType X, Position NIL);//找到X在树中的位置
Position FindMin(Position P, Position NIL);//find the mininum of tree
RBTree _Zig(RBTree T, Position *X);//LL
RBTree _Zag(RBTree T, Position *X);//RR
// void _ZagZig(Position root, Position X);//LR
// void _ZigZag(Position root, Position X);//RL
RBTree RB_insert_fixup(RBTree T, Position *X);// fix-up in insert Process
RBTree RB_insert(RBTree T,int data);// Insert Process
RBTree RB_transplant(RBTree T, Position *u, Position *v);//change the Node u with v
RBTree RB_delete_fixup(RBTree T, Position X);// fix-up in insert Process
RBTree RB_delete(RBTree T, Position X);
RBTree RB_deleteNum(RBTree T, ElemType X);
void BFS(RBTree T);//level-order traversal
#endif