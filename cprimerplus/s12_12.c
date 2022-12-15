//
// Created by 项鹏乐 on 2022/12/12.
//

#include <string.h>
#include <errno.h>
#include "../collections/LinkedList.h"

void x_int_uninit(const void *item) {
    struct x_int *temp = (struct x_int *) item;
    free(temp->extra);
    temp->extra = NULL;
    free(temp);
    temp = NULL;
    printf("x_int_uninit\n");
}

void x_int_print(const void *item) {
    struct x_int *temp = (struct x_int *) item;
    printf("%d->%d (%s)\n", (*temp).value, (*temp).index, temp->extra);
}

void int_print(const void *item) {
    int *temp = (int *) item;
    printf("%d\n", *temp);
}

void int_uninit(const void *item) {
    int *temp = (int *) item;
    free(temp);
    temp = NULL;
    printf("int_uninit\n");
}

// C 中怎么测试创建的堆内存被正确释放 了 （或者怎么测试内存泄漏）
// AddressSanitizer Valgrind

void case01() {
    struct x_linked_list xList;
    XListInitialize(&xList);
    int size = 10;
    struct x_int *tmp;
    struct x_int *todo_remove;
    for (int i = 0; i < size; ++i) {
        tmp = malloc(sizeof(struct x_int));
        if (i == 8) {
            todo_remove = tmp;
        }
        struct x_int this_x_int;
        this_x_int.value = i;
        this_x_int.index = i + 1;
        char *str = (char *) malloc(100);
        sprintf(str, "hello kt %d", i);
        this_x_int.extra = str;
        *tmp = this_x_int;
        printf("---->%p\n", tmp);
        XListAdd(&xList, (void **) &tmp);
    }

    if (XListIsEmpty(&xList)) {
        printf("XList为空\n");
    } else {
        printf("XList 打印\n");
        XListMapper(&xList, &x_int_print);
    }
    unsigned int sz = xList.size;
    printf("XList一共%d条数据*****************************\n", sz);

    void *removed = XListRemove(&xList,todo_remove);
    struct x_int * removed_x_int = (struct x_int *) removed;
    printf("%p->%p removed : %d %d %s\n",todo_remove,removed,removed_x_int->value,removed_x_int->index,removed_x_int->extra);
    free(removed_x_int->extra);
    free(removed_x_int);

    if (XListIsEmpty(&xList)) {
        printf("XList为空\n");
    } else {
        printf("XList 打印列表\n");
        XListMapper(&xList, &x_int_print);
    }
    unsigned int sz_removed = xList.size;
    printf("XList一共%d条数据\n", sz_removed);
    //printf("XList一共%d条数据\n", XListSize(&xList));


    XListUnInitialize(&xList, &x_int_uninit);
    printf("end...\n");
//    //测试释放？
//    if (tmp != NULL) {
//        printf("%d %d\n", tmp->value, tmp->index);
//    } else {
//        printf("释放完毕\n");
//    }
}

void case02() {
    struct x_linked_list xList;
    XListInitialize(&xList);
    int size = 10;
    int *tmp;
    for (int i = 0; i < size; ++i) {
        tmp = malloc(sizeof(int));
        *tmp = i;
        printf("---->%p\n", tmp);
        XListAdd(&xList, (void **) &tmp);
    }
    if (XListIsEmpty(&xList)) {
        printf("XList为空\n");
    } else {
        printf("XList 打印\n");
        XListMapper(&xList, &int_print);
    }
    unsigned int sz = xList.size;
    printf("XList一共%d条数据\n", sz);
    XListUnInitialize(&xList, &int_uninit);
    printf("end...\n");

}

int main() {
    case02();
    case01();
    return 0;
}