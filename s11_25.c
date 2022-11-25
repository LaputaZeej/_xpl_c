//
// Created by 项鹏乐 on 2022/11/24.
//

// 预处理
//源文件     编译-----链接                                                                    执行文件

//    翻译环境              ｜                                                               运行环境
//   目标文件obj + obj+链接库

// 【编译期】
//    编译            链接
//    预编译  ： gcc -E s11_24_02.c > a1.i  // a1.i 1。头文件包含2。注释删除3。
//    编译    ： gcc -S a1.i                // a1.s 把c语言代码翻译成汇编代码 1。语法分析 词法分析 语义分析 符号汇总 （编译原理）
//    汇编    ： gcc -c a1.s                // a1.o 汇编代码->二进制指令   1。形成符号表

// gcc -o s11_24_02.c test

// 【连接期】
//          目标文件obj + obj+链接库                        =      执行文件exe
//            elf  1。合并段表 2。符号表的合并和重定位



// 【预处理】

// 预处理指令
// #define
// #include
// #if
// #endif
#include <stdio.h>
#include "Utils.h"
#include <stdlib.h>

#define MAX 100
#define STR "xp"
#define MY_POW(X)  ((X)*(X))

void case01() {
    // 预定义符号
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%s\n", __FUNCTION__);


}

#define MY_TEST(x)  printf("hello, "#x"=%d \n",x);

#define MY_MAX(X, Y) ((X)>(Y)) ?(X):(Y)

void case02() {
    int r = MY_POW(5 + 1);
    printf("%d\n", r);

    MY_TEST(r)

    int a = 10;
    int b = 11;
    printf("%d,%d,%d\n", MY_MAX(a, b), a, b);
    printf("%d,%d,%d\n", MY_MAX(a++, b++), a, b);// ((a++)>(b++)?(a++):(b++)) //副作用参数a++
    FenGeXian();
}

// 函数                             宏
// 函数调用和返回有开销
//                                  宏预处理直接替换。
//                                  长度 、无法调试、类型无关、优先级问题

#define MY_MALLOC(NUM, TYPE) (TYPE*)malloc((NUM)*sizeof(TYPE))


void case03() {
    int *ptr = MY_MALLOC(10, int);
    printf("%p\n", ptr);
    free(ptr);
    ptr = NULL;
    FenGeXian();
#undef MY_MAX
    // 移除了宏定义
}

// 命令行定义 (预编译)
// gcc test.c -D SZ=5

// 条件编译
#define MY_DEBUG 1

void case04() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
#ifdef MY_DEBUG
    printf("%d\n", arr[1]);
#endif


#if MY_DEBUG == 1
    printf("1");
#elif MY_DEBUG == 2
    printf("2");
#else
     printf("0");
#endif

    // 是否被定义
#if !defined(MY_DEBUG)
    printf("MY_DEBUG 已定义");
#endif

#ifdef MY_DEBUG
    printf("\nMY_DEBUG 已定义");
#endif

#ifndef MY_DEBUG
    printf("\nMY_DEBUG 已定义");
#endif

    // 嵌套条件定义

    printf("\n");
    FenGeXian();
}

// include
// <>  标准头文件（usr/include）
// ""  源头文件 - 标准头文件

// ifndef define endif
// #pragma once

//#include stddef.h

struct CCC {
    char a;
    int b;
    char c;
};

#define OFFSET_OF(struct_name, member_name) (int)&(((struct_name*)0)->member_name) // 从0偏移
#include <stddef.h>
void case05() {

    printf("%d,%d,%d\n", offsetof(struct CCC, a), offsetof(struct CCC, b), offsetof(struct CCC, c));
    printf("%d,%d,%d\n", OFFSET_OF(struct CCC, a), OFFSET_OF(struct CCC, b), OFFSET_OF(struct CCC, c));
    FenGeXian();
}


int main() {
    case05();
    case04();
    case03();
    case02();
    case01();
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
    }

    return 0;
}
