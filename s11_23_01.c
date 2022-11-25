//
// Created by 项鹏乐 on 2022/11/23.
//

#include <stddef.h>
#include "Utils.h"

// 声明一个结构体
struct Man {
    char name[20];
    char tel[12];
    char sex[10];
    int age;
} s4, s5, s6; // 全局

struct Man s3; // 全局

struct {
    int a;
    char c;
} niming_c; // 匿名结构体

struct {
    int a;
    char c;
} *niming_pc;

// 结构体的自引用

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct List {
    int data;
    struct List *next;
} List;

typedef struct Maps map_t;

struct Maps {
    int data;
    struct Maps *next;
    map_t *pre;
};


void case01() {
    struct Man m1;
    struct Man m2;

    Node node1;
    Node node2;

    struct Maps map1;
    map_t map2;
    FenGeXian();

}

struct S1 {
    char c1;
    char c2;
    int a;
};
struct S2 {
    char c1;
    int a;
    char c2;
};

struct S3 {
    double d;
    char c;
    int i;
};

struct S4 {
    char c1;//1
    struct S3 s3; //16
    double d;// 8
};

#pragma pack(4) // 设置默认对齐数
struct S5 {
    char c1;//1
    struct S3 s3; //16
    double d;// 8
};
#pragma pack()

// 结构体 内存对齐
// 空间-》时间
// 小的尽量一起
void case02() {
    struct S1 s1 = {0};
    printf("%d\n", sizeof(s1)); // 8
    struct S2 s2 = {0};
    printf("%d\n", sizeof(s2)); // 12
    printf("%d\n", sizeof(struct S3)); // 16
    printf("%d\n", sizeof(struct S4)); // 32
    printf("%d\n", sizeof(struct S5)); // 28


    // offsetof hong
    printf("%d\n", offsetof(struct S4, c1));
    printf("%d\n", offsetof(struct S4, s3));
    printf("%d\n", offsetof(struct S4, d));

    FenGeXian();
}

// 位段
// int
// :n 小于32
// 不跨平台
// 1。符号不确定
// 2。位数不确定
// 3。分配不确定
// 4。
struct AA {
    int _a: 2; // 2位
    int _b: 5; // 5位
    int _c: 10;// 10位 // 拿出一个int
    int _d: 30;// 30位   // 上面的int放不下了，再拿出int
};

// 0111 1111 0001 1111 0000 1111
//      b  a         c         d
//
struct CC {
    char _a: 3; //       111
    char _b: 4; // 0111 1
    char _c: 5;//  0001 1111
    char _d: 4;//  0000 1111
};

void case03() {
    struct AA a1;
    printf("%d\n", sizeof(struct AA)); // 8
    printf("%d\n", sizeof(struct CC)); // 3
    struct CC c1;
    c1._a = 10;
    c1._b = 20;
    c1._c = 3;
    c1._d = 4;
    FenGeXian();
}

// 枚举
enum Day {
    Mon,
    Tues,
    Wed,
    Fu,
    Fri,
    Sat,
    Sun

};

enum Color {
    RED = 2,
    GREEN = 4,
    BLUE = 8
};

void case04() {
    enum Day day = Mon;
    enum Day day1 = 2;
    printf("%d\n", sizeof(Mon));
    printf("%d\n", sizeof(day1));
    printf("%d %d %d\n", RED, GREEN, BLUE);
    FenGeXian();

}

// 联合体-共同体
// 0x11223344
// 低... [][][][][11][22][33][44][][][][] ...高 // 小   10 00 00 00
// 低... [][][][][44][33][22][11][][][][] ...高 // 大   00 00 00 10
// int a = 1 ; (char*)&a  == 1 ? 小端 : 大端
union Hey {
    char c;
    int a;
};

int check_sys_old() {
    int a = 1;

    return (char *) &a;
}

int check_sys() {
    union Un {
        char c;
        int i;
    } u;
    u.i = 1;
    return u.c;
}

void case05() {
    union Hey u;
    printf("%d\n", sizeof(u));
    printf("%p\n", &(u));
    printf("%p\n", &(u.a));
    printf("%p\n", &(u.c));
    if (check_sys_old()) {
        printf("小端\n");
    } else {
        printf("大端\n");
    }
    FenGeXian();
}

// 通讯录
void case06(){

}

// 动态内存
// 堆区
// malloc（size
// calloc（size，sizeof
// realloc（ptr，size
// free 动态内存

// 1。对NULL *
// 2。动态内存越界访问
// 3。对非动态内存free
// 4。使用free释放动态内存的一部分
// 5。多次free
// 6。忘记释放 内存泄漏

int main() {
    case06();
    case05();
    case04();
    case03();
    case02();
    case01();
    return 0;
}