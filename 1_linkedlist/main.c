#include <stdio.h>//使用io接口
#include <stdlib.h>//使用malloc/calloc和free进行动态管理内存
#include <stdbool.h>//使用true和false
#include <stddef.h>//使用标准宏定义NULL、size_t
/*声明部分*/
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;//链表类型为指向链表头节点的指针
typedef PtrToNode Position;//位置类型为指向链表节点的指针
typedef int ElemType;//链表中的元素类型为int类型
struct Node
{
    ElemType Elem;
    Position next;
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
void ReverseList(List L);//翻转列表(原地操作)
List intersect(List L1, List L2);//两个链表取交集
List Union(List L1, List L2);//两个链表取并集
void printList(List L);//打印链表
List fromArray(ElemType* A, size_t N);//从数组中生成链表


/*定义部分*/
bool IsEmpty(List L){//确认列表是否为空，为空则返回true,否则为true
    return L->next == NULL ? true : false; 
}

bool IsLast(Position P, List L){//确认当前位置P是否达到表尾
    return P->next == NULL ? true : false;
}

Position Find(ElemType X, List L){//查找元素X在链表L中的位置，若找不到则返回NULL
    Position P = L->next;//P从首节点开始查询
    while(P != NULL && P->Elem != X){//遍历节点以寻找元素X
        P = P->next;
    }
    return P;//查找到X返回其位置，否则返回NULL
}

Position FindPre(ElemType X, List L){//寻找X的前一个元素的位置，找不到返回NULL
    Position P = L->next;
    if (IsEmpty(L)){//如果是空链表，直接返回NULL
        printf("this is a empty list!");
        return NULL;
    }
    while(P->next != NULL && P->next->Elem != X){
        P = P->next;
    }
    return P;
}

void Insert(ElemType X, List L, Position P){//插入元素     
    Position PNext = P->next;//备份P的下一个节点
    Position NewP = malloc(sizeof(struct Node));//分配新的节点NewP
    if (NewP == NULL){//保证新分配的节点不为NULL
        perror("insert error:Out of space!!");
        return;
    }
    NewP->Elem = X;//赋给新节点新的值
    P->next = NewP;//更改P的链接至NewP
    NewP->next = PNext;//新节点的后续节点
}

void Delete(ElemType X, List L){//将元素X从列表L中删除
    Position Pre = FindPre(X, L);//查找元素X的上一个节点位置
    Position Cur = Pre->next;//当前节点为上一节点的下一个节点
    if (!IsLast(Pre, L)){//只剩header时不删除！！
        Pre->next = Cur->next;//跳过当前节点
        free(Cur);//释放当前节点
    }
}

void MakeEmpty(List L){//将列表L置空，且释放内存空间
    Position P = L->next;//备份首节点
    L->next = NULL;//将头结点（header）指向空指针，列表L置空
    Position tmp;
    while (P != NULL){//释放首节点到末节点的内存空间
        tmp = P->next;
        free(P);//释放P节点
        P = tmp;//P指向下一节点
    }
    //return L;
}

void DeleteList(List L){//清空并删除列表（释放内存）
    MakeEmpty(L);
    free(L);
}

Position Header(List L){//查找头节点的位置
    return L;
}

Position First(List L){//查找首节点的位置
    return L->next;
}

Position Advance(Position P){//（提前知道）该节点的下一个节点
    return P->next;
}

ElemType Retrieve(Position P){//查询该节点的值
    return P->Elem;
}

void ReverseList(List L){//翻转列表（原地操作）,这里不更改头结点
    if (IsEmpty(L)){
        //perror("Empty list cannot reverse!!");
        return; 
    }
    Position pre, cur, nex;//3指针分别指向当前节点和其前后节点，pre节点进行交换，nex节点确定交换的截止位置 
    pre = NULL;//初始化3指针
    cur = L;
    nex = L->next;
    Position tmp_nex = nex;//备份L->next的位置
    while (nex != NULL){//nex节点确定交换的终点：末位置为NULL不交换,将最后一个节点作为头结点
        cur->next = pre;//翻转交换
        pre = cur;//3个指针依次向前推进
        cur = nex;
        nex = nex->next;
    }
    cur->next = pre;//链接首节点
    tmp_nex->next = NULL;//更新头结点
    L->next = cur;
    //return L;
}

List intersect(List L1, List L2){//两个链表取交集（两列表分别以递增顺序排列）
    List L = malloc(sizeof(struct Node));
    L->next = NULL;
    Position P = L;
    Position P1 = L1->next;
    Position P2 = L2->next;
    while (P1!=NULL && P2!=NULL){//交集只对相同长度部分处理
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
    List L = malloc(sizeof(struct Node));
    L->next = NULL;
    Position P = L;
    Position P1= L1->next;
    Position P2= L2->next;
    
    while (P1!=NULL && P2!=NULL){//对相同长度部分处理
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
    while (P1 != NULL){//P1部分有剩余，则添到链表后面即可
        Insert(P1->Elem, L, P);
        P = P->next;
        P1 = P1->next;
    }
    while (P2 != NULL){//P2部分有剩余，则添到链表后面即可
        Insert(P2->Elem, L, P);
        P = P->next;
        P2 = P2->next;
    }
    return L;
}

void printList(List L) {
    if (IsEmpty(L)) return;
    Position P = L->next;
    while (P != NULL && P->next != NULL) {//到倒数第二个不为NULL的节点前
        printf("%d -> ", P->Elem);
        P = P->next;
    }
    if (P != NULL && P->next == NULL) {//倒数第1个不为NULL的节点
        printf("%d\n", P->Elem);
    }
}

List fromArray(ElemType* A, size_t N) {
    List L = malloc(sizeof(struct Node));
    L->next = NULL;//链表的基础形式为:header->NULL
    Position P = L;
    for (int i = 0; i < N; ++i) {
        Insert(A[i], L, P);
        P = P->next;
    }
    return L;
}

int main() {
    /*测试代码*/
    ElemType nums[] = {1,2,3,6,7,8};
    List L = fromArray(nums,6);
    printList(L);
    //ReverseList(L);
    //printList(L);
    ElemType nums2[] = {1,2,3,4,5,6};
    List L2 = fromArray(nums2,6);
    List CL = Union(L,L2);
    printList(CL);
    Delete(4,CL);
    printList(CL);
    //MakeEmpty(CL);
    //if (IsEmpty(CL)) printf("yes");
    Position P = FindPre(2,CL);
    printf("%d",P->Elem);
    return 0;
}
