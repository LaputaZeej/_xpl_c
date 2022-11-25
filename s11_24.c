//
// Created by 项鹏乐 on 2022/11/24.
//


#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include <errno.h>

void GetGetMalloc(char **ptr) {
    *ptr = malloc(80);
}

void case01() {

    char *str = NULL;
    char *src = "hello world";

    GetGetMalloc(&str);
    if (str == NULL) {
        printf("%s\n", strerror(errno));
        return;
    }
    memcpy(str, src, strlen(src));
    printf("%s\n", str);

    free(str);
    str = NULL;
    FenGeXian();
}

void case02() {
    int i, n;
    char *buffer;
    printf("请输入长度>:");
    scanf("%d", &i);
    buffer = (char *) malloc(i + 1);
    if (buffer == NULL)return;
    for (n = 0; n < i; ++n) {
        buffer[n] = rand() % 26 + 'a';
    }
    buffer[i] = '\0';
    printf("随机字符串：%s \n", buffer);
    free(buffer);
    buffer = NULL;
}

char *GetMem() {
    char p[] = "hello world";
    return p; // 返回栈空间地址的问题。
}

void case03() {
    char *str = NULL;
    str = GetMem();
    printf(str);
    FenGeXian();
}

// 柔性数组 flexible array c99
struct S {
    int n;
    int arr[0];
};

void case04() {
    struct S s;
    printf("%d\n", sizeof(s)); // 都是4
    struct S *ptr;
    printf("%d\n", sizeof(*ptr)); // 都是4
    printf("malloc\n");
    ptr = (struct S *) malloc(sizeof(struct S) + 5 * sizeof(int));
    if (ptr == NULL)return;
    printf("%d\n", sizeof(*ptr)); // 都是4
    ptr->n = 100;
    for (int i = 0; i < 5; ++i) {
        ptr->arr[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", ptr->arr[i]);
    }
    printf("扩容 realloc \n");
    struct S *ptr_real = realloc(ptr, 44);
    printf("%d\n", sizeof(*ptr)); // 都是4
    if (ptr_real == NULL) {
        free(ptr);
        ptr = NULL;
        return;
    }
    ptr = ptr_real;
    for (int i = 5; i < 10; ++i) {
        ptr->arr[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", ptr->arr[i]);
    }
    free(ptr);
    ptr = NULL;
}

struct SB {
    int n;    //4_4
    int *arr; // 8
};

// 多次malloc 内存碎片
//
void case05() {
    struct SB *ptr = (struct SB *) malloc(sizeof(struct SB));
    if (ptr == NULL)return;
    printf("%d\n", sizeof(*ptr)); // 都是4
    printf("创建 malloc \n");
    int *p1 = (int *) malloc(5 * sizeof(int));
    if (p1 == NULL) {
        free(ptr);
        ptr = NULL;
        return;
    }
    ptr->arr = p1;
    printf("%d\n", sizeof(*ptr)); // 都是4

    ptr->n = 100;
    for (int i = 0; i < 5; ++i) {
        ptr->arr[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", ptr->arr[i]);
    }
    printf("扩容 realloc \n");
    int *ptr_real = (int *) realloc(ptr->arr, 44);
    if (ptr_real == NULL) {
        free(ptr->arr);
        ptr->arr = NULL;
        free(ptr);
        ptr = NULL;
        return;
    }
    ptr->arr = ptr_real;
    for (int i = 5; i < 10; ++i) {
        ptr->arr[i] = i;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", ptr->arr[i]);
    }
    free(ptr->arr);
    ptr->arr = NULL;
    free(ptr);
    ptr = NULL;
    FenGeXian()
}

// 寄存器
// cache
// memory
// disk

// 局部性原理，寄存器未命中-cache-memory； 连续性就访问速度高

// 柔性数组C99
// 方便内存释放
// 利于访问速度




int main() {
    case05();
//    case04();
//    case03();
//    case02();
//    case01();
    return 0;

}