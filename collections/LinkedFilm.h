//
// Created by 项鹏乐 on 2022/12/8.
//

#ifndef _XPL_C_LINKEDFILM_H
#define _XPL_C_LINKEDFILM_H

/**
 * 链表
 */
// 建立抽象 ADT
// 【类型名】
//     简单链表
// 【类型属性】
//     可以存储一系列项
// 【类型操作】
//     初始化一个空链表
//     在链表末尾添加一个新项
//     确定链表是否为空
//     确定链表是否已满
//     确定链表的项数
//     访问链表中每一项执行某些操作，如显示该项。
//     在链表的任意位置插入一个项
//     移除链表中的一个项
//     在链表中检索一个项（不改变链表）
//     用另一个项替换链表中的一个项
//     在链表中搜索一个项

enum bool {
    false, true
};

#define FILM_SIZE 45 /*片名长度*/
struct Movie {
    char title[FILM_SIZE];
    int rating;
};

typedef struct Movie Item;

typedef struct node {
    Item item;
    struct node *next;
} Node;

//typedef struct list {
//    Node *head;
//    int size;
//} * LikedList;
typedef Node *LikedList;

/**
 * 操作：初始化一个链表
 * 前提条件（precondition）：plist指向一个链表
 * 后置条件(postcondition)：该链表初始化为空
 * @param plist 指向一个链表
 */
void LinkedInitialize(LikedList *plist);

/**
 * 操作：确定链表是否为空定义
 * 前提条件（precondition）：plist指向一个已初始化的链表
 * 后置条件(postcondition)：如果链表为空，该函数返回true，否则返回false
 * @param plist 指向一个链表
 * @return enum bool
 */
enum bool LinkedListIsEmpty(const LikedList *plist);

enum bool LinkedListIsFull(const LikedList *plist);

unsigned int LinkedListCount(const LikedList *plist);

enum bool LinkedListAdd(Item item, LikedList *plist);

/**
 * 把函数作用于链表中的每一项
 * @param plist
 * @param pfun
 */
void LinkedListTraverse(const LikedList *plist, void(*pfun)(Item item));

void LinkedListClear(LikedList *plist);


#endif //_XPL_C_LINKEDFILM_H
