/*
    RB-Tree: 结合算法导论P179,P186
*/
#include <stdio.h>

#include "defineType.h"
#include "arrayqueue.h"
#include "rbtree.h"

RBTree InitRBT(){
    RBTree T = (RBTree)malloc(sizeof(struct RBPoints));
    T->root = (Position)malloc(sizeof(struct RBNode));
    T->NIL =  (Position)malloc(sizeof(struct RBNode));
    T->NIL->Color = Black;
    T->NIL->Left = T->NIL->Right = T->NIL->Parent = NULL;
    T->NIL->elem = INT_MAX;//可以不设定NIL的值
    T->root = T->NIL;//root的初始化为NIL;
    return T;
}

Position FindMin(Position P, Position NIL){//find the mininum of tree
    if (P == NIL){return NIL;}
    Position locPtr = NIL;
    while (P!= NIL){
        locPtr = P;
        P = P->Left;
    }
    return locPtr;
}

RBTree _Zig(RBTree T, Position *X){//LL: rotate at position X, and change root if possible

    Position Y = (*X)->Left;
    Position B = Y->Right;
    Position P = (*X)->Parent;
    (*X)->Left = B;//proces X<->B
    if (B!=T->NIL) B->Parent = (*X);
    Y->Right = (*X);//process Y<->X  
    (*X)->Parent = Y;
    Y->Parent = P;//process Y<->P
    if (P==T->NIL){//P is null
        T->root = Y;//change the root
    }
    else if (P->Left == (*X)){//left link
        P->Left = Y;
    }
    else{//right Link
        P->Right = Y;
    }
    return T;
}

RBTree _Zag(RBTree T, Position *X){//RR: rotate at position X, and change root if possible
    Position Y = (*X)->Right;
    Position B = Y->Left;
    Position P = (*X)->Parent;
    (*X)->Right = B;//Process X<->B
    if (B!=T->NIL) B->Parent = (*X);
    (*X)->Parent = Y;//Process X<->Y
    Y->Left = (*X);
    Y->Parent = P;//Proces Y<->P
    if (P==T->NIL) {//P is null
        T->root = Y;
    }
    else if (P->Left == (*X)){//left link
        P->Left = Y;
    }
    else{//right link
        P->Right = Y;
    }
    return T;
}

RBTree RB_insert_fixup(RBTree T, Position *X){// fix-up in insert Process from add point X
    Position P = NULL;//parent
    Position G = NULL;//grandparent
    Position S = NULL;//uncle
    while ((*X)!=T->root && (*X)->Color==Red && (*X)->Parent->Color==Red){//上滤的条件：非根节点且与父节点同为红色
        P = (*X)->Parent;
        G = P->Parent;
        if (P == G->Left){//父节点在爷爷节点的左侧，即判断叔节点的位置在爷爷节点的右侧
            S = G->Right;//叔父节点
            if (S!=T->NIL && S->Color == Red){//叔节点为Red(!NULL),则翻转爷爷节点和父辈节点，并上滤到爷爷节点
                G->Color = Red;
                P->Color = Black;
                S->Color = Black;
                (*X) = G;//更新X节点
            }
            else{//当叔节点为黑节点(NULL为黑)时，根据X节点是父节点的右孩子（RL）还是左孩子（LL）绕爷爷节点进行旋转
                if ((*X) == P->Right){//X节点为父节点的右孩子，即LR形式，比LL形式多了Zag
                    T = _Zag(T, &P);//LR的R步
                    (*X) = P;//更新R步的X节点<最下的节点>和父节点(爷爷节点没有改变)
                    P = (*X)->Parent;
                }
                T = _Zig(T, &G);//LL和LR的L步
                P->Color = Black;
                G->Color = Red;
                (*X) = P;//更新X节点为<最上的节点>
            }
        }
        else{//如果父节点是爷爷节点的右孩子，即叔节点是爷爷节点的左孩子（与if部分对称）
            S = G->Left;
            if (S!=T->NIL && S->Color==Red){//叔节点为红，父辈与祖辈节点翻转颜色
                S->Color = Black;
                P->Color = Black;
                G->Color = Red;
                (*X) = G;//更新X节点
            }
            else{//叔节点为黑色
                if ((*X) == P->Left){//X节点是父节点的左孩子 RL
                    T = _Zig(T, &P);//RL的L步旋转
                    (*X) = P;//更新X和P (G未改变)
                    P = (*X)->Parent;
                }
                T = _Zag(T, &G);//RR和RL的R步旋转
                P->Color = Black;//更新父辈和祖辈的颜色
                G->Color = Red;
                (*X) = G;//更新X节点
            }
        }
    }
    T->root->Color = Black;//更新祖节点颜色为黑
    return T;
}
RBTree RB_insert(RBTree T,ElemType data){// Insert Process = BST's insert + fix-up
    Position N = (Position)malloc(sizeof(struct RBNode));//建立新节点
    N->Color = Red;
    N->Left = T->NIL;
    N->Right = T->NIL;
    N->elem = data;
    N->Parent = T->NIL;
    /*查找待插入节点的父节点*/
    Position traPtr = T->root;//从根节点到叶子节点的遍历节点(最后为NULL)
    Position locPtr = T->NIL; //寻找待插入节点的父节点位置(双指针:locPtr定位到前一节点，traPtr定位到当前节点)
    while(traPtr!=T->NIL){
        locPtr = traPtr;//保存父节点
        if (data<traPtr->elem){// 进入左子树查找
            traPtr = traPtr->Left;
        }
        else{//进入右子树查找
            traPtr = traPtr->Right;
        }
    }
    /*插入并更新节点*/ 
    N->Parent = locPtr;
    if (locPtr == T->NIL){//待插入的树为空，更新树根节点
        T->root = N;
    }
    else if (data < locPtr->elem){//插入的节点为父节点的左孩子
        locPtr->Left = N;
    }
    else{//插入的节点为父节点的右孩子
        locPtr->Right = N;
    }
    T = RB_insert_fixup(T, &N);//从插入节点进行上滤
    return T;
}

RBTree RB_transplant(RBTree T, Position *u, Position *v){
    /*
        功能： 对于给定的红黑树，其根节点为root,将节点u的位置替换为节点v
        输入： root:输入根节点  u：被替换的节点  v: 替换的节点
        输出： void
    */
   // 更改 父->子 关系
   if ((*u)->Parent == T->NIL){//被替换的节点为根节点
        T->root = (*v);
   } 
   else if((*u) == (*u)->Parent->Left){//被替换节点为其父节点的左孩子
        (*u)->Parent->Left = (*v);
   }
   else{//被替换节点为其父节点的右孩子
        (*u)->Parent->Right = (*v);
   }
   //更改 子->父 关系
   //if ((*v)!=T->NIL){
       (*v)->Parent = (*u)->Parent;//包含v为NIL的情况
   //}
   //free((*u));//应该回收内存
   return T;
}

RBTree RB_delete_fixup(RBTree T, Position X){//删除中的上滤操作
    /*
    功能：删除节点的上滤过程
    X: 上滤的起始节点，是在删除过程中的标记点（检测节点的孩子节点）
    */
   while (X!=T->root && X->Color == Black)
   {
       if (X == X->Parent->Left){//X为左儿子节点
            Position W = X->Parent->Right;//兄弟节点
            //case1:兄弟节点的颜色为红时，更换W和W.Parent的颜色，并Zag(W.Parent),从而转换为case2/3/4
            if (W->Color == Red){
                W->Color = Black;
                W->Parent->Color = Red;
                T = _Zag(T,&(W->Parent));
                W = X->Parent->Right;//更新兄弟节点
            }
            //兄弟节点的颜色为黑色，分为case2,3,4
            //case2:兄弟节点的两个儿子节点的颜色都为黑色，更改兄弟节点的颜色，并上滤
            if (W->Left->Color == Black && W->Right->Color == Black){
                W->Color = Red;
                X = X->Parent;//上滤
            }
            //case3,4: 兄弟节点的两个儿子节点的颜色不同为黑色，case3可以转换为case4
            else{
                //case3: 兄弟节点的右孩子为黑色，RL的L步，更换W和W.left的颜色，并Zig(W)
                if (W->Right->Color == Black){
                    W->Color = Red;
                    W->Left->Color = Black;
                    T = _Zig(T,&W);
                    W = X->Parent->Right;//更新兄弟节点
                }
                //case4: 兄弟节点的右孩子为红色，RR/RL的R步，更换W为W.p的颜色，W.p和W.r变黑，再Zag(W.p),上滤
                W->Color = W->Parent->Color;
                W->Parent->Color = Black;
                W->Right->Color = Black;
                T = _Zag(T,&(W->Parent));
                X = T->root;//上滤
            }
       }
       else{//X为右儿子节点
            Position W = X->Parent->Left;//兄弟节点
            //case1: 兄弟节点的颜色为红时，更换W和W.Parent的颜色，并Zig(W.Parent),从而转换为case2/3/4
            if (W->Color == Red){
                W->Color = Black;
                W->Parent->Color = Red;
                T = _Zig(T,&(W->Parent));
                W = X->Parent->Left;//更新兄弟节点
            }
            //兄弟节点的颜色为黑色，分为case2,3,4
            //case2:兄弟节点的两个儿子节点的颜色都为黑色，更改兄弟节点的颜色，并上滤
            if (W->Left->Color == Black && W->Right->Color == Black){
                W->Color = Red;
                X = X->Parent;
            }
            //case3,4: 兄弟节点的两个儿子节点的颜色不同为黑色，case3可以转换为case4
            else{
                //case3: 兄弟节点的左孩子为黑色，LR的L步，更换W和W.Right的颜色，并Zag(W)
                if (W->Left->Color == Black){
                    W->Color = Red;
                    W->Right->Color = Black;
                    T = _Zag(T,&W);
                    W = X->Parent->Left;//更新兄弟节点
                }
                //case4: 兄弟节点的左孩子为红色，LL/LR的L步，更换W为W.p的颜色，W.p和W.r变黑，再Zig(W.p),上滤
                W->Color = W->Parent->Color;
                W->Color = Black;
                W->Parent->Color= Black;
                T = _Zig(T, &(W->Parent));
                X = T->root;
            }
       }
   }
   X->Color = Black;//当X的颜色为红色时，直接修改颜色即可
   return T;
}

RBTree RB_delete(RBTree T, Position Z){//在树T中删除X并释放Z
    Position detNode = Z;//point to the detect node:检测到的待删除/移动节点
    ColorType dnc = detNode->Color;// detect node's original color
    Position markPtr;//the child of the detect point 
    if (Z->Left == T->NIL){//要删除的节点的孩子节点少于1个（无左节点时）
        markPtr = Z->Right;//更新后继节点,其父节点由RB_transplant决定
        T = RB_transplant(T, &Z, &(Z->Right));//替换detNode为markPtr节点
    }
    else if(Z->Right == T->NIL){//要删除的节点的孩子节点少于1个（无右节点时）
        markPtr = Z->Left;//更新后继节点,其父节点由RB_transplant决定
        T = RB_transplant(T,&Z,&(Z->Left));//替换detNode为markPtr节点
    }
    else{//要删除的节点的孩子有两个时
        detNode = FindMin(Z->Right,T->NIL);//更新要删除的节点
        dnc = detNode->Color;//更新要删除节点的颜色节点
        markPtr = detNode->Right;//更新后继节点
        if (detNode == Z->Right){//detNode是Z的孩子节点，这时注意要更新markPtr的父节点
            markPtr->Parent = detNode;
        }
        else{//markPtr不是detNode的孩子节点，这时进行局部节点替换，在RB_transplant中已更新markPtr的父节点
            //markPtr和detNode.Parent节点的链接，以及Z.Right和detNode节点的链接
            T = RB_transplant(T,&detNode, &markPtr);//替换节点中包含更新markPtr的父节点的步骤
            detNode->Right = Z->Right;
            detNode->Right->Parent = detNode;//Z.right节点和detNode节点的链接
        }
        //链接detNode和Z.Parent节点，链接Z.left和detNode,并更改detNode的颜色
        T = RB_transplant(T,&Z,&detNode);
        Z->Left->Parent = detNode;
        detNode->Left = Z->Left;
        detNode->Color = Z->Color;
    }
    if (dnc == Black){//从标记节点进行上滤
        T =  RB_delete_fixup(T, markPtr);}
    free(Z);
    return T;
}

Position RB_find(Position root, ElemType X, Position NIL){//find x in T
    if (root == NIL || root->elem ==  X) return root;
    if (X < root->elem){//go left
        return RB_find(root->Left, X, NIL);
    }
    else{//go right
        return RB_find(root->Right, X, NIL);
    }
}

RBTree RB_deleteNum(RBTree T, ElemType X){//从树T中删除元素X，并返回更新后的树T
    Position findNode = RB_find(T->root,X,T->NIL);
    if (findNode != T->NIL)
        T = RB_delete(T,findNode);
    return T;
}

void BFS(RBTree T){//层次遍历
    Queue que =  createQueue(MAXQUE);//建立长度为100的队列
    if (T->root != T->NIL) enqueue(T->root,que);//将根节点值入队
    size_t size = 0;
    ElemType rec[MAXQUE*10];
    ElementType tmp;
    while (!isEmpty(que))
    {
        tmp = dequeue(que);
        rec[size++] = tmp->elem;
        if (tmp->Left != T->NIL) enqueue(tmp->Left,que);
        if (tmp->Right != T->NIL) enqueue(tmp->Right,que);
    }
    for (size_t i=0;i<size;++i){
        printf("  %d",rec[i]);
    }printf("\n");
}