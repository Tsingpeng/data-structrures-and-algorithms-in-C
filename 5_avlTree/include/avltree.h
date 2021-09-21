#ifndef _AVLTREE_H_
#define _AVLTREE_H_

#include "defineType.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
int Balance(AvlTree T);//get the balance factor of BBST T
AvlTree MakeEmpty(AvlTree T);//clear the AVL tree
Position Find(ElemType X, AvlTree T);//find element X in tree T
Position FindMin(AvlTree T);//find minimum of T
Position DeleMin(AvlTree T,ElemType *numPtr);//delete the minimum in the AVL tree and return the update tree and delete data
Position FindMax(AvlTree T);//find maximum of T
AvlTree Insert(ElemType X, AvlTree T);//insert element X in the AVL tree T
AvlTree Delete(ElemType X, AvlTree T);//delete the element X in the AVL tree T
ElemType Retrive(Position P);// retrive the elemnt of the position P

void preorderTraversal(AvlTree T);//  pre-order traversal
void inorderTraversal(AvlTree T);//   in-order traversal
void postorderTraversal(AvlTree T);// post-order traversal
void BFS(AvlTree T);//                level traversal



#endif