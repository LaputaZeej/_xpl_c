//
// Created by 项鹏乐 on 2022/12/12.
//

#include "LinkedList.h"

#define DEBUG 0

static void XListPrint(struct x_linked_list *pList) {
    if (~DEBUG)return;
    if (XListIsEmpty(pList))return;
    struct x_node *head = pList->head;
    while (head != NULL) {
        printf("%p ", head);
        head = head->next;
    }
}

void XListInitialize(struct x_linked_list *pList) {
    struct x_linked_list list;
    list.size = 0;
    list.head = NULL;
    *pList = list;
}

enum bool XListIsEmpty(const struct x_linked_list *pList) {
    return pList==NULL || pList->size == 0;
}

static enum bool XListIsFull(const struct x_linked_list *pList, size_t size) {
    if (pList==NULL) return false;
    void *p = malloc(size);
    enum bool result;
    if (p == NULL) {
        result = true;
    } else {
        result = false;
    }
    free(p);
    return result;
}

enum bool XListAdd(struct x_linked_list *pList, void **item) {
    struct x_node *node = NULL;
    printf("p%d-->%p\n", pList->size, *item);
    node = (struct x_node *) malloc(sizeof(struct x_node));
    if (node == NULL){
        fprintf(stderr,"unable to allocate memory!\n");
        exit(1);
    }
    node->value = *item;
    node->next = NULL;
    if (pList->head == NULL) {
        pList->head = node;
        pList->size = pList->size + 1;
    } else {
        struct x_node *cur = pList->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
        pList->size = pList->size + 1;
    }
    XListPrint(pList);
    return true;
}

void *XListRemove(struct x_linked_list *pList, void *item) {
    struct x_node *cur = pList->head;
    struct x_node *nxt = cur->next;
    struct x_node *pre = NULL;
    int index = 0;
    while (nxt) {
        if (cur->value == item) {
            if (pre != NULL) {
                printf("找到了%d  %p->%p->%p \n", index, pre, cur, nxt);
                cur->next = NULL;// 解除自己的next
                pre->next = nxt; //上一个节点的next 指向下一个节点
            } else {
                cur->next = NULL;// 解除自己的next
                pList->head = nxt;//第一个节点
            }
            pList->size--;
            XListPrint(pList);
            return cur->value;
        }
        pre = cur;
        cur = nxt;
        nxt = cur->next;
        index++;
    }

    return NULL;
}


void XListMapper(struct x_linked_list *pList, void (*func)(const void *item)) {

    if (XListIsEmpty(pList))return;
    struct x_node *head = pList->head;
    while (head != NULL) {
        func(head->value);
        head = head->next;
    }
}

void XListUnInitialize(struct x_linked_list *pList, void (*pUnInit)(const void *item)) {
    if (pList == NULL)return;
    printf("XListUnInitialize\n");
    struct x_node *cur = pList->head; // 取出头
    int index = 0;
    while (cur) {
        struct x_node *next = cur->next;
        printf("free %d次\n", ++index);
        //free(cur->value);// 释放值⬇
        pUnInit(cur->value);// 外部决定怎么释放
        free(cur);//释放node
        cur = next;
    }
    pList->size = 0;
    pList->head = NULL;
    pList = NULL;
}