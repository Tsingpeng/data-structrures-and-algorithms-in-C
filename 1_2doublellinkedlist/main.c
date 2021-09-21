#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
/*
    在单链表的基础上实现双端链表（double linked list）
    除了使用header节点，我们也使用tailer节点以使得能够双向查询
*/
/*声明部分*/
struct Node;
struct DList;
typedef struct Node *PtrToNode;
typedef struct DList *PtrToList;//修改链表指针指向头尾节点所示的结构体
typedef PtrToList List;//链表类型为指向链表头节点的指针
typedef PtrToNode Position;//位置类型为指向链表节点的指针
typedef int ElemType;//链表中的元素类型为int类型
struct Node
{
    ElemType Elem;
    Position next;
    Position prev;//比单链表多了一个域用于表示上个节点的指针 
};
struct DList
{
    Position header;
    Position tailer;
};

bool IsEmpty(List L);//确认列表是否为空，为空则返回true,否则为true
bool IsLast(Position P, List L);//确认位置P是否达到表尾
Position Find(ElemType X, List L);//查找元素X在链表L中的位置，若找不到则返回NULL
Position FindPre(ElemType X, List L);//寻找X的前一个元素的位置，找不到返回NULL
void Insert(ElemType X, List L, Position P);//插入元素     
void Delete(ElemType X, List L);//将元素X从列表L中删除
void MakeEmpty(List L);//清空列表并释放内存
void DeleteList(List L);//清空并删除列表（释放内存）
Position Header(List L);//查找头节点的位置
Position First(List L);//查找首节点的位置
ElemType Retrieve(Position P);//查询该节点的值
Position Advance(Position P);//（提前知道）该节点的下一个节点
//void ReverseList(List L);//翻转列表(原地操作),对于双链表是不必要的
List intersect(List L1, List L2);//两个链表取交集
List Union(List L1, List L2);//两个链表取并集
void printListF(List L);//打印链表(顺序)
void printListR(List L);//打印链表(倒序)
List fromArray(ElemType* A, size_t N);//从数组中生成链表

/*定义部分*/
bool IsEmpty(List L){//确认列表是否为空，为空则返回true,否则为true
    return L->header->next == L->tailer ? true : false; 
}

bool IsLast(Position P, List L){//确认当前位置P是否达到表尾
    return P->next == L->tailer ? true : false;
}

Position Find(ElemType X, List L){//查找元素X在链表L中的位置，若找不到则返回NULL
    Position P = L->header->next;//P从首节点开始查询
    while(P != L->tailer && P->Elem != X){//遍历节点以寻找元素X
        P = P->next;
    }
    return P;//查找到X返回其位置，否则返回NULL
}

Position FindPre(ElemType X, List L){//寻找X的前一个元素的位置，找不到返回NULL
    Position P = L->header->next;
    if (IsEmpty(L)){//如果是空链表，直接返回NULL
        printf("this is a empty list!");
        return NULL;
    }
    while(P->next != L->tailer && P->next->Elem != X){
        P = P->next;
    }
    return P;
}

void Insert(ElemType X, List L, Position P){//插入元素     
    Position PNext = P->next;//备份P的下一个节点
    Position NewP = (Position)malloc(sizeof(struct Node));//分配新的节点NewP
    if (NewP == NULL){//保证新分配的节点不为NULL
        perror("insert error:Out of space!!");
        return;
    }
    NewP->Elem = X;//赋给新节点新的值
    P->next = NewP;//更改P的链接至NewP
    NewP->next = PNext;//新节点的后续节点
    PNext->prev = NewP;//重连PNext的前序节点
    NewP->prev = P;//重连NewP的前序节点
}

void Delete(ElemType X, List L){//将元素X从列表L中删除
    Position Pre = FindPre(X, L);//查找元素X的上一个节点位置
    Position Cur = Pre->next;//当前节点为上一节点的下一个节点
    if (!IsLast(Pre, L)){//只剩header和tailer时不删除！！
        Pre->next = Cur->next;//跳过当前节点
        Cur->next->prev = Pre;
        free(Cur);//释放当前节点
    }
}

void MakeEmpty(List L){//将列表L置空，且释放内存空间
    Position P = L->header->next;//备份首节点
    L->header->next = L->tailer;//将头结点（header）指向尾节点（tailer），列表L置空
    Position tmp;
    while (P != L->tailer){//释放首节点到末节点的内存空间
        tmp = P->next;
        free(P);//释放P节点
        P = tmp;//P指向下一节点
    }
    //return L;
}

void DeleteList(List L){//清空并删除列表（释放内存）
    MakeEmpty(L);
    free(L->header);
    free(L->tailer);
    free(L);
}

Position Header(List L){//查找头节点的位置
    return L->header;
}

Position First(List L){//查找首节点的位置
    return L->header->next;
}

Position Advance(Position P){//（提前知道）该节点的下一个节点
    return P->next;
}

ElemType Retrieve(Position P){//查询该节点的值
    return P->Elem;
}

List intersect(List L1, List L2){//两个链表取交集（两列表分别以递增顺序排列）
    List L = (List)malloc(sizeof(struct DList));
    L->header = (Position)malloc(sizeof(struct Node));
    L->tailer = (Position)malloc(sizeof(struct Node));
    L->header->next = L->tailer;
    L->tailer->prev = L->header;
    Position P = L->header;
    Position P1 = L1->header->next;
    Position P2 = L2->header->next;
    while (P1!=L1->tailer && P2!=L2->tailer){//交集只对相同长度部分处理
        if (P1->Elem == P2->Elem){
            Insert(P1->Elem, L, P);
            P = P->next;
            P1 = P1->next;
            P2 = P2->next;
        }
        else if (P1->Elem < P2->Elem){
            P1 = P1->next;
        }
        else{
            P2 = P2->next;
        }
    }
    return L;
}

List Union(List L1, List L2){//两个链表取并集(两个链表以递增顺序排列，使得并集也按递增顺序排列)
    List L = (List)malloc(sizeof(struct DList));
    L->header = (Position)malloc(sizeof(struct Node));
    L->tailer = (Position)malloc(sizeof(struct Node));
    L->header->next = L->tailer;
    L->tailer->prev = L->header;
    Position P = L->header;
    Position P1= L1->header->next;
    Position P2= L2->header->next;
    
    while (P1!=L1->tailer && P2!=L2->tailer){//对相同长度部分处理
        if (P1->Elem == P2->Elem){
            Insert(P1->Elem, L, P);
            P = P->next;
            P1 = P1->next;
            P2 = P2->next;
        }
        else if (P1->Elem < P2->Elem){
            Insert(P1->Elem, L, P);
            P1 = P1->next;
            P = P->next;
        }
        else{
            Insert(P2->Elem, L, P);
            P2 = P2->next;
            P = P->next;
        }    
    }
    while (P1 != L1->tailer){//P1部分有剩余，则添到链表后面即可
        Insert(P1->Elem, L, P);
        P = P->next;
        P1 = P1->next;
    }
    while (P2 != L2->tailer){//P2部分有剩余，则添到链表后面即可
        Insert(P2->Elem, L, P);
        P = P->next;
        P2 = P2->next;
    }
    return L;
}

void printListF(List L) {
    if (IsEmpty(L)) return;
    Position P = L->header->next;
    while (P != L->tailer && P->next != L->tailer) {//到倒数第二个不为NULL的节点前
        printf("%d -> ", P->Elem);
        P = P->next;
    }
    if (P != L->tailer && P->next == L->tailer) {//倒数第1个不为NULL的节点
        printf("%d\n", P->Elem);
    }
}

void printListR(List L) {
    if (IsEmpty(L)) return;
    Position P = L->tailer->prev;
    while (P != L->header && P->prev != L->header) {//到倒数第二个不为NULL的节点前
        printf("%d <- ", P->Elem);
        P = P->prev;
    }
    if (P != L->header && P->prev == L->header) {//倒数第1个不为NULL的节点
        printf("%d\n", P->Elem);
    }
}
List fromArray(ElemType* A, size_t N) {
    List L = (List)malloc(sizeof(struct DList));
    L->header = (Position)malloc(sizeof(struct Node));
    L->tailer = (Position)malloc(sizeof(struct Node));
    L->header->next = L->tailer;//双向链表的基础形式为:header<->NULL
    L->tailer->prev = L->header;
    Position P = L->header;
    for (int i = 0; i < N; ++i) {
        Insert(A[i], L, P);
        P = P->next;
    }
    return L;
}
int main(int argc, char const *argv[])
{
    ElemType nums[] = {1,2,3,4,5,6};
    List L = fromArray(nums,6);
    printListF(L);
    printListR(L);
    Insert(5,L,L->header);
    Delete(4,L);  
    printListF(L);
    return 0;
}
