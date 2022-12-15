//
// Created by 项鹏乐 on 2022/12/8.
//

#include <stdlib.h>
#include <stdio.h>
#include "LinkedFilm.h"

/* 局部函数原型 */
static void Copy2Node(Item item, Node *pnode);

void LinkedInitialize(LikedList *plist) {
    *plist = NULL;
}

enum bool LinkedListIsEmpty(const LikedList *plist) {
    if (*plist == NULL) {
        return true;
    } else {
        return false;
    }
}

enum bool LinkedListIsFull(const LikedList *plist) {
    Node *pt;
    enum bool full;
    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL) {
        full = true;
    } else {
        full = false;
    }
    free(pt);
    return full;
}

unsigned int LinkedListCount(const LikedList *plist) {
    unsigned int count = 0;
    Node *pnode = *plist;
    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

enum bool LinkedListAdd(Item item, LikedList *plist) {
    Node *pnew;
    Node *scan = *plist;
    // 新建
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)return false;
    // 赋值item到节点
    Copy2Node(item, pnew);
    // 放到最后
    pnew->next = NULL;
    if (scan == NULL) {
        *plist = pnew;
    } else {
        while (scan->next != NULL) {
            scan = scan->next;
        }
        scan->next = pnew;
    }
    return true;
}

void LinkedListTraverse(const LikedList *plist, void(*pfun)(Item item)) {
    Node *pnode = *plist;
    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

void LinkedListClear(LikedList *plist) {
    Node *psave;
    while (*plist != NULL) {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

static void Copy2Node(Item item, Node *pnode) {
    pnode->item = item;
}