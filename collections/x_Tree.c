//
// Created by 项鹏乐 on 2022/12/13.
//

#include "x_Tree.h"

/* 操作           : 把树初始化为空 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 树被初始化为空 */
void XTreeInitialize(XTree *xTree) {
    if (xTree != NULL) {
        xTree->root = NULL;
        xTree->size = 0;
        xTree = NULL;
    }
}

/* 操作           : 确定树为空 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 如果树为空，返回true，否则返回false */
enum bool XTreeIsEmpty(const XTree *xTree) {
    if (xTree == NULL) {
        fprintf(stderr, "xTree为NULL");
        exit(1);
    }
    return xTree->size == 0;
}

/* 操作           : 确定树已满 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 如果树已满，返回true，否则返回false */
enum bool XTreeIsFull(const XTree *xTree) {
    if (xTree == NULL) {
        fprintf(stderr, "xTree为NULL");
        exit(1);
    }
    return xTree->size == MAX_ITEMS;
}

/* 操作           : 确定树的项数 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 返回树的项数 */
unsigned int XTreeCount(const XTree *xTree) {
    if (xTree == NULL) {
        fprintf(stderr, "xTree为NULL");
        exit(1);
    }
    return xTree->size;
}

/* 是否在左边 这个方法根据当前类型XItem变化 */
static enum bool ToLeft(const XItem *cur, const XItem *item) {
    int cmp;
    if ((cmp = strcmp(cur->pet_name, item->pet_name)) < 0) {
        return true;
    } else if (cmp == 0 && strcmp(cur->pet_kind, item->pet_kind) < 0) {
        return true;
    } else {
        return false;
    }
}

/* 是否在右边 这个方法根据当前类型XItem变化 */
static enum bool ToRight(const XItem *cur, const XItem *item) {
    int cmp;
    if ((cmp = strcmp(cur->pet_name, item->pet_name)) > 0) {
        return true;
    } else if (cmp == 0 && strcmp(cur->pet_kind, item->pet_kind) > 0) {
        return true;
    } else {
        return false;
    }
}

/* 是否相等 这个方法根据当前类型XItem变化 */
static enum bool ToSame(const XItem *cur, const XItem *item) {
    return strcmp(cur->pet_name, item->pet_name) == 0 && (strcmp(cur->pet_kind, item->pet_kind) == 0);
}

/* 查找 如果找到则放到child，父节点放到parent。当时root时，parent为NULL;如果找不到则child为NULL。 */
static XPair SeekItem(const XTree *xTree, const XItem *pi) {
    if (xTree == NULL) { /* 说明此树还没有初始化 */
        fprintf(stderr, "xTree为NULL");
        exit(1);
    }
    XPair xPair;
    xPair.parent = NULL;
    xPair.child = xTree->root;
    if (xPair.child == NULL) { /* 说明此树也为空 还没有数据 */
        return xPair;
    }
    XItem_cmp isLeft = &ToLeft;
    // XItem_cmp isRight =  &ToRight;
    while (xPair.child != NULL) {
        if (isLeft(pi, &(xPair.child->item))) { /* 在左边 */
            xPair.parent = xPair.child;
            xPair.child = xPair.child->left;
        } else if (ToRight(pi, &(xPair.child->item))) {
            xPair.parent = xPair.child;
            xPair.child = xPair.child->right;
        } else {
            /* 没有匹配的 */
            break;
        }
    }
    return xPair;
}

static void AddNode(XNode *newNode, XNode *root) {
    if (ToLeft(&(newNode->item), &(root->item))) {
        if (root->left == NULL)
            root->left = newNode; /* 等于NULL 说明没有左节点 直接添加 */
        else
            AddNode(newNode, root->left); /* 不等于NULL 说明有左节点 递归添加 root变为左节点 */
    } else if (ToRight(&(newNode->item), &(root->item))) {
        if (root->right == NULL)
            root->right = newNode;
        else
            AddNode(newNode, root->right);
    } else {
        fprintf(stderr, "禁止添加相同的项");
        exit(1);
    }

}

static XNode *MakeNode(const XItem *pi) {
    XNode *xNode;
    xNode = (XNode *) malloc(sizeof(XNode));
    if (xNode == NULL) {
        return NULL;
    }
    if (pi == NULL) {
        return NULL;
    }
    xNode->item = *pi;
    xNode->left = NULL;
    xNode->right = NULL;
    return xNode;
}

/* 操作           : 从树中添加一个项 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 如果可以添加，该函数将在树中添加一个项并返回true，否则返回false */
enum bool XTreeAdd(XTree *xTree, const XItem *pi) {

    // 1。检查空间
    if (XTreeIsFull(xTree)) {
        fprintf(stderr, "树满了\n");
        return false;
    }
    // 2。检查项：所有的项不能重复
    if (SeekItem(xTree, pi).child != NULL) {
        fprintf(stderr, "不能重复添加！\n");
        return false;
    }
    // 3。新建项
    XNode *newNode;
    newNode = MakeNode(pi);
    if (newNode == NULL) {
        fprintf(stderr, "不能创建新的节点\n");
        return false;
    }
    // 4。size++
    /* 成功创建了一个新节点 */
    xTree->size++;
    if (xTree->root == NULL) /* 根节点为空 */
        xTree->root = newNode;
    else
        AddNode(newNode, xTree->root); /* 在树中添加一个节点 */

    return true;
}

/* 操作           : 从树中查找一个项 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : ???? */
enum bool XTreeInTree(const XTree *xTree, const XItem *pi) {
    return SeekItem(xTree, pi).child == NULL ? false : true;
}

// 修改指针 由当前项的地址->转向特定项的地址
static void DeleteNode(XNode **ptr) {
    /* ptr是指向目标节点的父节点指针成员的地址 */
    XNode *tmp;

    if ((*ptr)->left == NULL) { /* 没有左子节点的节点 */
        // 无子节点的节点 是此情况的特例。
        // 如果该节点没有左子节点，就将有子节点的地址赋值给其父节点的指针。 如果右节点为NULL 即是无子节点的情况。
        tmp = *ptr;
        *ptr = (*ptr)->right;
        free(tmp);
    } else if ((*ptr)->right == NULL) { /* 没有右子节点的节点 */
        tmp = *ptr;
        *ptr = (*ptr)->left;
        free(tmp);
    } else { /* 包含2个子节点的节点 */
        for (tmp = (*ptr)->left; tmp->right != NULL; tmp = tmp->right) // 要沿着左子树的右支一只找
            continue;
        tmp->right = (*ptr)->right; //找到了重新链接右子树的位置了。 左子节点的最右子节点 的地址 更改为当前节点的右子节点
        tmp = *ptr; // 保存当前节点
        *ptr = (*ptr)->left; // 把当前节点的地址更改为左子节点
        free(tmp);
    }
}

/* 操作           : 从树中删除一个项 */
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 从树中成功删除一个项，该函数返回true，否则返回false */
enum bool XTreeDelete(XTree *xTree, const XItem *pi) {


    // 情况1。被删除的节点为叶节点

    // 叶节点 leaf
    // 没有子节点的节点
    // 情况2。被删除的节点带有1个子节点
    // 情况3。被删除的节点带有2个子节点，即带有2个子树的节点。
    //  左子树的父节点 是当前节点的父节点
    //  右子树的父节点 要沿着左子树的右支一只找

    // 任务1：特定项与待删除节点关联
    // 任务2：删除节点
    // 都需要修改待删除项父节点的指针。

    // 注意点1：标识待删除节点的父节点
    // 注意点2：为了修改指针，必须把该指针的地址传递给执行删除任务的函数
    XPair look;
    look = SeekItem(xTree, pi);
    if (look.child == NULL) {
        return false;
    }
    if (look.parent == NULL) { /* 1。根节点 */
        DeleteNode(&xTree->root); // 删除根节点
    } else if (look.parent->left == look.child) { /* 2。左子节点 */
        DeleteNode(&look.parent->left);
    } else {
        DeleteNode(&look.parent->right);/* 3。右子节点 */
    }
    xTree->size--;
    return true;
}

static void InOrder(const XNode *root, void(*pFun)(XItem)) {
    if (root != NULL) {
        InOrder(root->left, pFun);
        (*pFun)(root->item);
        InOrder(root->right, pFun);
    }
}

/* 操作           : 把函数pFun应用于树的每一项 */
/* 前置条件       : xTree指向一个树；pFun指向一个函数 */
/* 后置条件       : 把函数pFun应用于树的每一项 */
void XTreeTraverse(const XTree *xTree, void(*pFun)(XItem)) {
    if (xTree != NULL) {
        InOrder(xTree->root, pFun);
    }
}

static void DeleteAllNodes(XNode *root) {
    XNode *right;
    if (root != NULL) {
        right = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(right);
    }
}

/* 操作           : 删除数中的所有内容*/
/* 前置条件       : xTree指向一个树 */
/* 后置条件       : 树为空*/
void XTreeUnInitialize(XTree *xTree) {
    if (xTree != NULL) {
        DeleteAllNodes(xTree->root);
        //...
    }
}