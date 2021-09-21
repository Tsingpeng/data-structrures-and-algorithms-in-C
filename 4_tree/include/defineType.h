#ifndef _DEFINETYPE_H_
#define _DEFINETYPE_H_

struct TreeNode;//节点信息用结构体表示
typedef struct TreeNode *PtrToNode;//指向节点的指针
typedef PtrToNode Position;//位置指针即节点的指针
typedef PtrToNode SearchTree;//(子)树的指针即节点的指针
typedef int ElemType;//元素类型定义int型
struct TreeNode{//树的节点信息
    ElemType elem;//当前节点的数值
    SearchTree Left;//该节点的左子树
    SearchTree Right;//该节点的右子树
};

typedef PtrToNode ElementType;

#define MAXQUE 100




#endif