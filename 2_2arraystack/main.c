#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
/*
    使用数组实现栈结构：需要提前设定栈区长度（数组长度）   FILO
*/
/*声明部分*/
struct StackRecord;
typedef struct StackRecord *Stack;
typedef int ElementType;

bool isEmpty(Stack S);//确认栈区是否为空
bool isFull(Stack S);//确认栈区是否已满
Stack createStack(int maxElements);//创建栈区
void disposeStack(Stack S);//释放栈区
void makeEmpty(Stack S);//清空栈区
void push(ElementType X, Stack S);//压入栈
ElementType peek(Stack S);//找到栈区首元素
ElementType pop(Stack S);//弹出首元素

/*定义部分*/
#define EmptyTOS (-1)//Empty Top of Stack
#define MinStackSize (5)
struct StackRecord{
    int Capicity;//栈区的容量
    int TopOfStack;//指向的栈区首元素的位置（添加的最后一个元素的索引）
    ElementType *array;//栈区元素数组
};

bool isEmpty(Stack S){//确认栈区是否为空
    return S->TopOfStack == EmptyTOS ? true : false;
}

bool isFull(Stack S){//确认栈区是否已满
    return S->Capicity == (S->TopOfStack+1) ? true : false;
}

Stack createStack(int maxElement){//创建栈区
    int maxElements = maxElement>MinStackSize ? maxElement : MinStackSize;
    Stack S = (Stack)malloc(sizeof(struct StackRecord));//创建栈区
    S->Capicity = maxElements;//栈区容量为输入参数
    S->TopOfStack = EmptyTOS;//栈区的首元素位置初始化为-1
    S->array = (ElementType*)malloc(maxElements*sizeof(ElementType));//栈区数组进行动态分配空间
    return S;
}

void disposeStack(Stack S){//释放栈区
    if (S != NULL){//S和S->array都是分配动态内存的，所以对这两个要进行释放内存操作
        free(S->array);
        free(S);
    }
}

void makeEmpty(Stack S){//清空栈区，只需将栈区的首元素索引进行复位即可
    S->TopOfStack = EmptyTOS;
}

void push(ElementType X, Stack S){//压入栈:首元素索引加一，添加元素
    if (!isFull(S)){
        S->TopOfStack++;
        S->array[S->TopOfStack] = X;        
    }
}

ElementType peek(Stack S){//找到栈区首元素
    if (isEmpty(S)){
        perror("peek Error: Empty Stack");
    }
    return S->array[S->TopOfStack];
}

ElementType pop(Stack S){//弹出首元素
    if (isEmpty(S)) {
        perror("pop Error: Empty Stack");
        return -1;
    }
    ElementType tmp = S->array[S->TopOfStack];
    S->TopOfStack--;
    return tmp;
}
void printStack(Stack S){
    if (isEmpty(S)) return;
    for (size_t i = 0; i < S->TopOfStack-1; i++){
        printf("%d->",S->array[i]);
    }
    printf("%d\n",S->array[S->TopOfStack]);
}

int main(int argc, char const *argv[])
{
    Stack S = createStack(30);
    push(2,S);
    push(4,S);
    push(6,S);
    push(20,S);
    push(40,S);
    push(60,S);
    printStack(S);
    pop(S);
    printStack(S);

    return 0;
}
