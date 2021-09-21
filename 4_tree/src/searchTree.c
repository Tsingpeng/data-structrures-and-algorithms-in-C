#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arrayqueue.h"
#include "searchTree.h"
#include "defineType.h"
int Max(int x, int y){
    return x>y?x:y;
}
/* 定义二叉树部分 */
SearchTree MakeEmpty(SearchTree T){//将树结构清空，并返回NULL
    if (T == NULL) return NULL;//递归基：达到叶子节点停止
    MakeEmpty(T->Left);//清空左子树
    MakeEmpty(T->Right);//清空右子树
    free(T);//清空该节点
    return NULL;
}

Position Find(ElemType X, SearchTree T){//根据二叉搜索树的特性查找元素X在树T中的位置
    if (T == NULL) return NULL;//递归基1：没找到X
    if (T->elem < X) {
        return Find(X, T->Right);
    }
    else if (T->elem > X){
        return Find(X, T->Left);
    }
    else {//递归基2：找到X
        return T;
    }
}

Position FindMin(SearchTree T){//找到树T中的最小值所在的节点(树的最左侧)<递归实现>
    if (T==NULL) return NULL;
    if (T->Left == NULL) return T;
    return  FindMin(T->Left); 
}

Position DeleMin(SearchTree T,ElemType *numPtr){//删除树T中的最小值并返回最小值(注意这里对数值numPtr的引出)
    if (T==NULL) return NULL;
    Position tmp;
    if (T->Left == NULL){//递归基
        tmp = T;
        *numPtr = tmp->elem;
        T = T->Right;
        free(tmp);
        return T;
    } 
    T->Left = DeleMin(T->Left,numPtr);
    return T;
}

Position FindMax(SearchTree T){//找到树T中的最大值所在的节点(树的最右侧)<迭代实现>
    if (T==NULL) return NULL;
    // if (T->Right == NULL) return T;
    // return FindMax(T->Right);
    while (T->Right != NULL){
        T = T->Right;
    }
    return T;
}

SearchTree Insert(ElemType X, SearchTree T){//在树T中插入元素X并返回该二叉搜索树
    if (T == NULL){//递归基
        T=(SearchTree) malloc(sizeof(struct TreeNode));
        if (T==NULL) 
        {
            perror("this ptr is NULL");
            return NULL;
        }
        T->elem = X;
        T->Left = T->Right = NULL;
    }
    else if (X<T->elem){//元素值小于当前节点的值，插入到左子树中
        T->Left = Insert(X,T->Left);//并更新左子树
    }
    else if (X>T->elem){//元素值大于当前节点的值，插入到右子树中
        T->Right = Insert(X,T->Right);//并更新右子树
    }
    return T;//每个条件语句都返回T,并且当X==T.elem时不做任何操作
}

SearchTree Delete(ElemType X, SearchTree T){//在树T中删除元素X并返回该二叉搜索树
    //分为2类情况：删除节点的子节点数=2和<2
    Position tmp;
    ElemType *numPtr = (ElemType*)malloc(sizeof(ElemType));
    //static ElemType minnum;
    if (T == NULL){//Special Case
        perror("this tree is NULL to dele." );
        return NULL;
    }
    if (X<T->elem){//进入左子树查找
        T->Left = Delete(X,T->Left);//并更新删除后的左子树
    }
    else if (X>T->elem){//进入右子树查找
        T->Right = Delete(X,T->Right);//并更新删除后的右子树
    }
    else if (T->Left && T->Right){//找到要删除的节点且该节点有两个子节点
        // tmp = FindMin(T->Right);//找到要删除节点的右子树中的最小节点
        // T->elem = tmp->elem;//对要删除节点的数值进行覆盖
        // T->Right = Delete(T->elem,T->Right);//从右子树中删除覆盖值(右子树的最下节点的子节点个数一定小于2)
        
        T->Right = DeleMin(T->Right,numPtr);
        T->elem = *numPtr;
    }
    else{//找到要删除的节点且该节点的子节点个数小于2 <递归基>
        tmp = T;//要删除的节点
        if (T->Left == NULL){T = T->Right;}//左子树为空，返回右子树
        else if (T->Right == NULL){T = T->Left;}//右子树为空，返回左子树
        free(tmp);//释放要删除节点的内存
    }
    return T;

}
void preorderTraversal(SearchTree T){//先序遍历并打印
    if (!T) return;
    printf(" %d",T->elem);
    preorderTraversal(T->Left);
    preorderTraversal(T->Right);
}

void inorderTraversal(SearchTree T){//中序遍历并打印
    if (!T) return;
    inorderTraversal(T->Left);
    printf(" %d",T->elem);
    inorderTraversal(T->Right);
}

void postorderTraversal(SearchTree T){//中序遍历并打印
    if (!T) return;
    postorderTraversal(T->Left);
    postorderTraversal(T->Right);
    printf(" %d",T->elem);
}

void BFS(SearchTree T){//层次遍历
    Queue que =  createQueue(MAXQUE);//建立长度为100的队列
    if (T != NULL) enqueue(T,que);//将根节点值入队
    size_t size = 0;
    ElemType rec[MAXQUE*10];
    ElementType tmp;
    while (!isEmpty(que))
    {
        tmp = dequeue(que);
        rec[size++] = tmp->elem;
        if (tmp->Left != NULL) enqueue(tmp->Left,que);
        if (tmp->Right != NULL) enqueue(tmp->Right,que);
    }
    for (size_t i=0;i<size;++i){
        printf("  %d",rec[i]);
    }printf("\n");
}

int Height(SearchTree T,int (*max)(int x,int y)){//树的高度
    if (T == NULL) return -1;
    return max(Height(T->Left,max),Height(T->Right,max))+1;
}
