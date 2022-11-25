//
// Created by 项鹏乐 on 2022/11/21.
//

#include "Utils.h"

void case01() {
    int a[3][2] = {(0, 1), (2, 3), (4, 5)};
    int *p;
    p = a[0];
    printf("%d\n", p[0]); // 1?
    FenGeXian();
}

void case02() {
    // a                                                                   a[4][2]
    // ⬇               1               2               3               4     ⬇
    // [0][0][0][0][0] [0][0][0][0][0] [0][0][0][0][0] [0][0][0][0][0] [0][0][0][0][0]
    // ⬆           1            2            3            4     ⬆      5           6
    // p                                                        p[4][2] ️
    //
    int a[5][5]; // 5行5列数组
    int (*p)[4]; // 数组指针，数组元素有4个。
    p = a; //a:int(*p)[5]
    printf("%d\n", sizeof(a[0][0]));
    printf("%d\n", sizeof(a[0]));
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(*p));
    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); //？（-4的补码） ，-4个字节  p[4][2] =  *(*(p+4)+2)
    FenGeXian();
}

void case03() {
    int a[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[2][5] = {{1, 2, 3, 4, 5}, 6, 7, 8, 9, 10};
    int c[2][5] = {{1, 2, 3, 4, 5},
                   {6, 7, 8, 9}};
    int d[2] = {1};

    int *ptr1 = (int *) (&a + 1); //
    //  12345[⬅]
    //  67890
    int *ptr2 = (int *) (*(a + 1));// *（a+1） = a[1]
    printf("%d，%d\n", *(ptr1 - 1), *(ptr2 - 1)); // 10,5
    FenGeXian();
}

void case04() {


    char *a[] = {"work", "at", "alibaba"}; // char * a[] 是一个数组，是一个指针数组，是一个char*指针数组
    // work  at  alibaba
    // w o r k \0 a t \0 a l i b a b a \0
    // |
    // a
    // char *(*ptr)[3] = a; // 省略的过程：a是char*指针数组指针，类型为 char*（*ptr）[3] // error
    char **pa = a; // char **p  是二级指针；*p是指针，我的电脑是8个字节；**p++ 移动八个字节？// error

    // 再次分析
    char *(*ptr)[3] = &a; // 这才是char*指针数组指针
    // a是第一个元素地址，即a[0]，为一个指针char*
    char **ptr_a = a;
    // 所以ptr_a++ 是加ptr_a的字节数
    printf("%s\n", *pa);
    int size01 = my_strLen(*pa);
    printf("pa %p ,size = %d\n", *pa, size01);

    pa++; // 【跳过char* 大小】！！！
    printf("%s\n", *pa); // alibaba？//error   2。at // at
    // 按照这个说法pa ++2次 就是alibaba
    int size02 = my_strLen(*pa);
    printf("pa %p ,size = %d\n", *pa, size02);        // 3

    pa++; // 【跳过char* 大小】！！！
    printf("%s\n", *pa);
    int size03 = my_strLen(*pa);
    printf("pa %p ,size = %d\n", *pa, size03);    //  alibaba
    FenGeXian();
}

void case05() {
    // 分析见./img/s1121_case05.jpg
    char *c[] = {"ENTER", "NEW", "POINT", "FIRST"}; // c:char*指针数组
    char **cp[] = {c + 3, c + 2, c + 1, c}; // char**指针数组
    char ***cpp = cp; // cp[0]的指针，类型为**p
    printf("%s\n", **++cpp);
    printf("%s\n", *--*++cpp + 3);
    printf("%s\n", *cpp[-2] + 3);
    printf("%s\n", cpp[-1][-1] + 1);

}


int main() {
    case05();
    case04();
    case03();
    case02();
    case01();
    return 0;
}