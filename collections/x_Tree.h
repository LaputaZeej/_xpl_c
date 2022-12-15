//
// Created by 项鹏乐 on 2022/12/13.
//

/* 二叉查找树 */

#ifndef _XPL_C_X_TREE_H
#define _XPL_C_X_TREE_H

#define SLEN 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 根据具体情况重新定义 */
typedef struct {
    char pet_name[SLEN];
    char pet_kind[SLEN];
} XItem;

typedef struct x_tree_node {
    XItem item;
    struct x_tree_node *left; /* 指向左分支的指针 */
    struct x_tree_node *right; /* 指向右分支的指针 */
} XNode;

#define MAX_ITEMS  10

typedef struct x_tree {
    XNode *root; /* 指向跟节点的指针 */
    unsigned int size; /* 树的项数 */
} XTree;

enum bool {
    false, true
};

typedef struct x_pair {
    XNode *parent;
    XNode *child;
} XPair;

/* 函数原型 */

/* 比较原型 */
typedef enum bool (*XItem_cmp)(const XItem *, const XItem *);

/* 操作           : 把树初始化为空 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 树被初始化为空 */
void XTreeInitialize(XTree *xTree);

/* 操作           : 确定树为空 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 如果树为空，返回true，否则返回false */
enum bool XTreeIsEmpty(const XTree *xTree);

/* 操作           : 确定树已满 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 如果树已满，返回true，否则返回false */
enum bool XTreeIsFull(const XTree *xTree);

/* 操作           : 确定树的项数 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 返回树的项数 */
unsigned int XTreeCount(const XTree *xTree);

/* 操作           : 从树中添加一个项 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 如果可以添加，该函数将在树中添加一个项并返回true，否则返回false */
enum bool XTreeAdd(XTree *xTree, const XItem *pi);

/* 操作           : 从树中查找一个项 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : ???? */
enum bool XTreeInTree(const XTree *xTree, const XItem *pi);

/* 操作           : 从树中删除一个项 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 从树中成功删除一个项，该函数返回true，否则返回false */
enum bool XTreeDelete(XTree *xTree, const XItem *pi);

/* 操作           : 把函数pFun应用于树的每一项 */
/* 前置条件       : xTree指向一个树；pFun指向一个函数 */
/* 后置条件       : 把函数pFun应用于树的每一项 */
void XTreeTraverse(const XTree *xTree, void(*pFun)(XItem));

/* 操作           : 删除数中的所有内容*/
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 树为空*/
void XTreeUnInitialize(XTree *xTree);


#endif //_XPL_C_X_TREE_H
