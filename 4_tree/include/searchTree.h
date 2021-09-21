#ifndef _SEARCHTREE_H_
#define _SEARCHTREE_H_

#include "defineType.h"
/*
    二叉搜索树的实现
*/
/* 声明部分 */

SearchTree MakeEmpty(SearchTree T);//将树结构清空，并返回NULL
Position Find(ElemType X, SearchTree T);//在查找元素X在树T中的位置
Position FindMax(SearchTree T);//找到树T中的最大值所在的节点
Position FindMin(SearchTree T);//找到树T中的最小值所在的节点
Position DeleMin(SearchTree T,ElemType *num);//删除树T中的最小值并返回更新后的根节点，用指针返回最小值
SearchTree Insert(ElemType X, SearchTree T);//在树T中插入元素X并返回该二叉搜索树
SearchTree Delete(ElemType X, SearchTree T);//在树T中删除元素X并返回该二叉搜索树
void preorderTraversal(SearchTree T);//先序遍历并打印
void inorderTraversal(SearchTree T);//中序遍历并打印
void postorderTraversal(SearchTree T);//后序遍历并打印
void BFS(SearchTree T);//层次遍历
int Height(SearchTree T,int (*max)(int,int));//树的高度
int Max(int, int);

#endif