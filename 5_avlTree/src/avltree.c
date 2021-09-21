#include "defineType.h"
#include "avltree.h"
#include "arrayqueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

AvlTree MakeEmpty(AvlTree T){//clear the AVL tree, use the post-order traversal<SAME WITH TREE.C>
    if (!T) return NULL;
    MakeEmpty(T->Left);
    MakeEmpty(T->Right);
    free(T);
    return NULL;
}

Position Find(ElemType X, AvlTree T){//find element X in tree T <SAME WITH TREE.C>
    if (!T) return NULL;
    if (X == T->elem){return T;}
    else if (X < T->elem){return Find(X, T->Left);}
    else if (X > T->elem){return Find(X,T->Right);}
}

Position FindMin(AvlTree T){//find minimum of T: find the leftest num.
    if (!T) perror("No data to find minimum!");
    if (!T->Left) return T;
    else return FindMin(T->Left);
}

Position DeleMin(AvlTree T,ElemType *numPtr){//delete the min. and return update subtree and delete data
    if (!T) return NULL;
    if (!T->Left){//base
        *numPtr = T->elem;
        Position tmp = T;
        T = T->Right;
        free(tmp);
    }
    else{
        T->Left = DeleMin(T->Left,numPtr);
    }
    //T->height = _Max(_Height(T->Left),_Height(T->Right))+1;
    return T;
}

Position FindMax(AvlTree T){//find maximum of T
    if (!T) return NULL;
    if (!T->Right) return T;
    return T->Right;
}

ElemType Retrive(Position P){// retrive the elemnt of the position P
    return P->elem;
}

static int _Height(Position P){//return the tree's height 
    if (P == NULL) return -1;
    return P->height;
}

static int _Max(int x, int y){//return the maximum of (x,y)
    return x>y?x:y;
}

int Balance(AvlTree T){//get the balance factor of BBST T, using it in the delete func.
    if (T==NULL) return 0;
    return _Height(T->Left)-_Height(T->Right);
}

static Position _Zig(Position P){//zig at the position P to get the right rotate(case 1:LL)
    Position N = P->Left;//the new node of zig
    Position Y = N->Right;//the changed son
    N->Right = P;
    P->Left = Y;
    
    P->height = _Max(_Height(P->Left),_Height(P->Right))+1;
    N->height = _Max(_Height(N->Left),_Height(N->Right))+1;
    return N;
}

static Position _Zag(Position P){//zag at the position P to get the left roate(case2: RR)
    Position N = P->Right;// the new node of zag
    Position Y = N->Left;// the changed son
    P->Right = Y;
    N->Left = P;

    P->height = _Max(_Height(P->Left),_Height(P->Right))+1;
    N->height = _Max(_Height(N->Left),_Height(N->Right))+1;
    return N;
}

static Position _ZagZig(Position P){//zagzig at the position P to get the left-right rotate(case3:LR)
    Position N = P->Left;
    Position S = _Zag(N);//zag
    P->Left = S;
    return _Zig(P);//zag-zig
}

static Position _ZigZag(Position P){//zigzag at the position P to get hte right-left rotate(case4:RL)
    Position N = P->Right;
    Position S = _Zig(N);//zig
    P->Right = S;
    return _Zag(P);//zag
}

AvlTree Insert(ElemType X, AvlTree T){//insert element X in the AVL tree T
    if (T==NULL){//base
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if (T==NULL) {perror("no spare space!");return NULL;}
        T->elem = X;
        T->height = 0;
        T->Left = T->Right = NULL;
    }
    else if (X<T->elem){// go left
        T->Left = Insert(X,T->Left);
        if (Balance(T) > 1){//unbalanced case(LL or LR)
            if (X<T->Left->elem){//case(LL)
                T = _Zig(T);
            }
            else{//case(LR)
                T = _ZagZig(T);
            }
        }        
    }
    else if (X>T->elem){//go right
        T->Right = Insert(X,T->Right);
        if (Balance(T) < -1){//unbalanced case(RR or RL)
            if (X>T->Right->elem){//case(RR)
                T = _Zag(T);
            }
            else{//case(RL)
                T = _ZigZag(T);
            }
        }
    }
    T->height = _Max(_Height(T->Left), _Height(T->Right)) + 1;
    return T;
}

AvlTree Delete(ElemType X, AvlTree T){//delete the element X in the AVL tree T
    if (T==NULL) return NULL;//special case: NO elem. to dele.
    if (X<T->elem){// go left to search X
        T->Left = Delete(X,T->Left);
    }
    else if (X>T->elem){// go right
        T->Right = Delete(X,T->Right);
    }
    else{// find the elem.
        if (T->Left && T->Right){// T has 2 children
            Position tmp = FindMin(T->Right);//it's better to use FindMin 
            T->elem = tmp->elem;
            T->Right = Delete(T->elem, T->Right);//从右子树中删除覆盖值(右子树的最下节点的子节点个数一定小于2)
        }
        else{//T has 0 or 1 children
            Position tmp2 = T;
            if (T->Left == NULL) T = T->Right;
            else if (T->Right == NULL) T = T->Left;
            free(tmp2);
        }
    }
    /* fix the AVL tree rule after delete elem.*/
    if (T==NULL) return NULL;// after dele. there may be nothing left[注意这条语句要放到更新树高之前]
    T->height = _Max(_Height(T->Left) ,_Height(T->Right)) + 1;// update tree's height
    /* rebalance the tree from leaves to root after delete the node*/
    
    if (Balance(T)>1){// LL\LE or LR case
        if (Balance(T->Left)>=0){// LL\LE case
            return _Zig(T);
        }
        else{// LR case 
            return _ZagZig(T);
        }
    }
    else if (Balance(T)<-1){// RR\RE or RL
        if (Balance(T->Right)<=0){// RR and RE
            return _Zag(T);
        }
        else{//RL
            return _ZigZag(T);
        }
    }
    return T;// 不需要调整时
}


void BFS(AvlTree T){//层次遍历
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