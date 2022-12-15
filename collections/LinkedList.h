//
// Created by 项鹏乐 on 2022/12/12.
//

#ifndef _XPL_C_LINKEDLIST_H
#define _XPL_C_LINKEDLIST_H


#include <stdlib.h>
#include <stdio.h>

struct x_int {
    int value;
    int index;
    char *extra;
};

enum bool {
    false, true
};

typedef void(*x_Mapper)(const void *);

struct x_node {
    void *value;
    struct x_node *next;
};

//typedef struct x_node XNode;

struct x_linked_list {
    unsigned int size;
    struct x_node *head;
};

//typedef struct x_linked_list XList;

/**
 * 操作                 : 初始化一个链表
 * 前提条件precondition  : pList指向一个链表，链表数据为struct x_node「值的引用+数据大小」
 * 后置条件postcondition : 该链表初始化为空，head为NULL size=0
 * @param pList
 */
void XListInitialize(struct x_linked_list *pList);

enum bool XListIsEmpty(const struct x_linked_list *pList);

/**
 * 操作                 : 添加一个数据 添加的数据的指针的指针 因为数据不确定。
 * 前提条件precondition  : pList指向一个链表，且已初始化
 * 后置条件postcondition : 链表结尾加一个新的数据，size加1
 * @param pList
 * @param item
 */

enum bool XListAdd(struct x_linked_list *pList, void **item);

void *XListRemove(struct x_linked_list *pList, void *item);

/**
 * 操作                 : 对每个数据进行操作
 * 前提条件precondition  : pList指向一个链表，且已初始化
 * 后置条件postcondition : 每个数据调了一遍x_Mapper函数
 * @param pList
 * @param mapper
 */
void XListMapper(struct x_linked_list *pList, x_Mapper mapper);

/**
 * 操作                 : 反初始化
 * 前提条件precondition  : pList指向一个链表，且已初始化
 * 后置条件postcondition : 将链表初始化为空，head为NULL size=0，清理内存（包括数据void*）。
 * @param pList
 * @param mapper
 */
void XListUnInitialize(struct x_linked_list *pList, void (*pUnInit)(const void *));

#endif //_XPL_C_LINKEDLIST_H
