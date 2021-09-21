#ifndef _DEFINETYPE_H_
#define _DEFINETYPE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

struct RBNode;//存放节点信息
struct RBPoints;//存放初始节点和NIL节点
typedef struct RBPoints *RBTree;
typedef struct RBNode *Position;
typedef int ElemType;
typedef enum colorType {Red, Black} ColorType;
struct RBNode
{
    ElemType elem;
    Position Left;
    Position Right;
    Position Parent;
    ColorType Color;
};
struct RBPoints{//存放树的初始节点和NIL节点
    Position root;//根节点
    Position NIL;//NIL节点
};
typedef Position ElementType;
#endif