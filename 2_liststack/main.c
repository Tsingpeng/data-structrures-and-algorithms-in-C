#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
/*
    基于链表的栈结构
*/
/*声明部分*/
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

bool isEmpty(Stack S);//判断栈S是否为空
void makeEmpty(Stack S);//清空栈
Stack createStack(void);//创建空栈
void disposeStack(Stack S);//清空并释放栈区
void push(ElementType X, Stack S);//将元素压入栈顶
ElementType peek(Stack S);//查询栈首元素
ElementType pop(Stack S);//弹出栈顶元素
void printStack(Stack S);//打印栈
/*定义部分*/
struct Node//定义节点
{
    ElementType Elem;
    PtrToNode next; 
};

bool IsEmpty(Stack S){//判断栈是否为空
    return S->next == NULL ? true : false;
}

void makeEmpty(Stack S){//清空栈，与链表的情形一致
    PtrToNode P = S->next;
    S->next = NULL;
    PtrToNode tmp;
    while (P != NULL){
        tmp = P->next;//保存下一节点的位置
        free(P);//释放当前节点
        P = tmp;//P指向下一个节点
    }
}

Stack createStack(void){//创建栈
    Stack S = malloc(sizeof(struct Node));//创建栈区
    if (S == NULL) {
        perror("create stack error!");
    }
    S->next = NULL;
    return S;
}

void disposeStack(Stack S){//清空并消除栈
    makeEmpty(S);
    free(S);
}

void push(ElementType X, Stack S){//将元素压入栈顶
    PtrToNode P = malloc(sizeof(struct Node));//创建新节点并赋值
    P->Elem = X;
    PtrToNode tmp = S->next;//备份原首节点
    S->next = P;//将P设为新首节点
    P->next = tmp;//原首节点向后移
}

ElementType peek(Stack S){//查询栈首元素
    return S->next->Elem;
}

ElementType pop(Stack S){//弹出栈顶元素
    if (S->next == NULL) {
        perror("pop Error:Empty Stack");
        return -1;
    }
    PtrToNode tmp = S->next;
    ElementType res = S->next->Elem;
    S->next = tmp->next;
    free(tmp);
    return res;
}

void printStack(Stack S){//打印栈
    if (S->next == NULL){
        return;
    }
    PtrToNode P = S->next;
    while (P != NULL && P->next != NULL){
        printf("%d->",P->Elem);
        P = P->next;
    }
    if (P != NULL && P->next == NULL){
        printf("%d\n",P->Elem);
    }
}

int main(int argc, char const *argv[])
{
    Stack S = createStack();
    push(2,S);
    push(3,S);
    push(1,S);
    printStack(S);
    printf("%d\n",peek(S));
    printf("%d\n",pop(S));
    printStack(S);
    return 0;
}
