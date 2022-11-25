//
// Created by 项鹏乐 on 2022/11/17.
//

#include "Utils.h"

void case01() {
    char attr[] = "abcdef";
    char *ptr_attr = attr;
    char *ptr = "abcdef";

    printf("%s \n", attr);
    printf("%c \n", *ptr_attr);
    printf("%s \n", ptr_attr);
    printf("%c \n", *ptr);
    printf("%s \n", ptr);
    FenGeXian();
}

void case02() {
    char *ptr = "abcdef"; // "abcdef"是一个常量字符串
    // const char *ptr = "abcdef"; // 解决
    printf("start\n");
    *ptr = 'W'; // error
    printf("end\n");
    printf("%s\n", ptr);

    FenGeXian();

}

void case03() {
    char attr0[] = "abcdefg";
    char attr1[] = "abcdefg";
    char *ptr0 = "abcdefg";
    char *ptr1 = "abcdefg";
    printf("attr0 = attr1 %d\n", (attr0 == attr1));
    printf("ptr0 = ptr1 %d\n", (ptr0 == ptr1));

    FenGeXian();
}

void case04() {
    // 指针数组
    int arr[10] = {0};
    char ch[5] = {0};

    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int *ptr_atts[] = {&a, &b, &c, &d};
    for (int i = 0; i < 4; ++i) {
        printf("%d\n", *(ptr_atts[i]));
    }

    int attr01[] = {1, 2, 3, 4, 5};
    int attr02[] = {11, 22, 33, 44, 55};
    int attr03[] = {111, 222, 333, 444, 555};
    int *ptr_attrs[] = {attr01, attr02, attr03};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%d ", *(ptr_attrs[i] + j));
        }
        printf("\n");
    }
    FenGeXian();
}

void case05() {
    // 数组指针 -> 指针
    int *arr = NULL;  //整形指针 可以存放整形
    char *ch = NULL;  // 字符指针 可以存放字符
    // 那么数组指针 存放数组的指针（ps:这个数组还可能是指针数组)
    int attr[10] = {1, 2, 3, 4, 5};
    // 【如何写？】
    // 错误写法：
    // int *ptr[10] = &attr; // 错误写法 会判断是一个整形指针数组 []首先会和ptr结合 判断成一个数组
    // 理解：
    // 先得到 整形数组指针
    // 先写出类型整形数组int[10]
    // 加上指针变量名
    // int（*ptr)[]
    int (*ptr)[10] = &attr; // ok
    printf("%p\n", attr);
    printf("%p\n", ptr);

    // vs java
    // int[10] attr;
    // int [10](*ptr) = &attr;

    // 【指针数组的数组指针】
    int *ptr_int[20] = {0}; // ptr_int 是int指针数组
    // 这个指针数组的（数组）指针是：
    &ptr_int;
    // 类型是：？
    // 先写类型 int*[20]
    // 加上指针 *ptrs
    int *(*ptr_s)[20] = &ptr_int; // ok
    // int **ptrs01[10] = &ptr_int; // error 会判定成为一个int**的指针数组
    printf("%p\n", ptr_int);
    printf("%p\n", ptr_s);
    printf("---\n");

    // 总结
    // 指针数组的数组指针
    int *attr_abc[10] = {0};
    int *attr_abcd[9] = {0};
    int *(*ptr_a)[10] = &attr_abc;
    int *(**ptr_b)[10] = &ptr_a; // 如何理解ptr_b 指针数组的数组指针的 指针？
    int *(**ptr_c)[10] = ptr_b;  // 如何理解ptr_c 指针的指针？存的指针？实际上是int* ？
    int *ptr_d = ptr_c;       // 这样吗？不是。warning: Incompatible pointer types initializing 'int *' with an expression of type 'int *(**)[]'

    int *(*cccc)[9] = &attr_abcd;
    ptr_b = &cccc; // warning:Incompatible pointer types assigning to 'int *(**)[10]' from 'int *(**)[9]'

    printf("%p %lu\n", attr_abc, sizeof(attr_abc));
    printf("%p %lu\n", ptr_a, sizeof(*ptr_a));
    printf("%p %lu\n", ptr_b, sizeof(ptr_b));
    printf("%p %lu\n", ptr_c, sizeof(ptr_c));
    printf("%p %lu\n", ptr_d, sizeof(ptr_d));

    // 以上理解可能有错误

    int test_a[5];              // 是一个数组，数组元素的类型为int
    int *test_b[10];            // 是一个数组，数组元素的类型为指针，指针的类型为：int*
    int (*test_c)[10];          // 是一个数组指针，该指针指向了一个数组 数组元素有10个 每个元素的类型是int
    // 新的理解
    // 先取变量名称
    // 看[]一起就是一个数组 其他的都是类型
    int (*test_d[3])[10];       // 是一个数组 该数组的元素有3个，每个元素为一个数组指针,类型为：【int(*)[10]】，每个数组指针指向一个长度为10的数组，数组的元素类型为int

    // 解释下这个类型：int(*attr[10])[20]
//    int(*t_a[10])[20] ; // ??????
//    int(*t_b)[20] ;
    FenGeXian();
}


void print2d1(int attr[][5], int x, int y) {}
//void print2d2(int attr[][], int x, int y) {}
//void print2d2(int attr[3][], int x, int y) {}

void print2d(int attr[3][5], int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d ", attr[i][j]);
        }
        printf("\n");
    }
}

// 参数是指针数组
void print2d_prt(int (*attr)[5], int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
//            printf("%d ", attr[i][j]);
            printf("%d ", *(*(attr + i) + j));
//            printf("%d ", (*(attr+i))[j]);
        }
        printf("\n");
    }
}

void case06() {
    int attr[3][5] = {{1, 2, 3, 4, 5},
                      {2, 3, 4, 5, 6},
                      {3, 4, 5, 6, 7}};
    print2d(attr, 3, 5);
    print2d_prt(attr, 3, 5); // 第一个数组的指针，数组指针
    FenGeXian();


}

int add(int x, int y) {
    return x + y;
}

int minus(int x, int y) {
    return x - y;
}

int vid(int x, int y) {
    return x / y;
}

int mul(int x, int y) {
    return x * y;
}

//typedef void(*)(int) my_fun_t; // error
typedef void(*my_fun_t)(int); // yes

void (*signal(int, void(*)(int)))(int);

void (*signal02(int, my_fun_t))(int);

my_fun_t signal03(int, my_fun_t);

//  34课
void case07() {
    // 函数指针
    int (*ptr)(int, int) = add;
    int a = (*ptr)(2, 3);
//    int a = ptr(2,3);
    printf("a=%d\n", a);
    // int (*ptr)(int, int)    // 函数指针
    //                  ⬇️
    // int (*ptr[4])(int, int) // 函数指针数组
    //                  ⬇️
    // int ((*ptr)[4])(int, int) // 函数指针数组的指针
    int (*ptr_mes[4])(int, int) ={add, minus, mul, vid};
    for (int i = 0; i < 4; ++i) {
        printf("%d\n", ptr_mes[i](10, 2));
    }

    // 函数指针数组的指针
    int (*(*ptr_p)[4])(int, int) = &ptr_mes;
    // ptr_p是一个数组指针，是函数指针数组的指针，指针指向的数组有4个元素，元素的类型是int(*)(int,int)。

    // 转仪表
    //
    // (*(void(*)())0)(); // 强制0转换为void(*) , 0地址上调用 函数地址为：void（*）的函数
    // void(*signal(int,void(*)(int)))(int);
    //                   函数名          参数：
    //                              整型 ，函数指针
    //                   signal(    int , void(*)(int) )
    //       返回值：函数指针
    //       void(*                                              )(int)
    //       组合起来
    //       void(*      signal(    int , void(*)(int) )         )(int)

    // void(*)(int) signal(int,void(*)(int)) // java思想 x
    FenGeXian();
}

char *my_strcpy(char *dest, const char *src) {
    printf("my_strcpy\n");
    char *ret = dest;
//    char p1= *dest++;
//    char p2 = *src++;
//    p1=p2;
    while ((*dest++ = *src++)) {
    }
    printf("my_strcpy end\n");
    return ret;
}

void case08() {

    char *(*ptr)(char *, const char *) = my_strcpy;
//    char*(*ptrs[10])(char*,const char*) = {0};
    char *str = "hello";
    char dest[] = "";
//    char *dest = "";
    char *ret = ptr(dest, str);
    printf("%s\n", ret);


    FenGeXian();
}

void qsort(){

}

void bubble_sort(int *arr,int sz){
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz-1-i; ++j) {
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void case09(){
    int arr[] = {9,8,1,2,6,5};
    int sz = sizeof(arr)/sizeof (arr[0]);
    printf("sz=%d\n",sz);
    bubble_sort(arr,sz);
    for (int i = 0; i < sz; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    FenGeXian();
}


int main() {
    case09();
    case08();
    case07();
    case06();
    case05();
    case04();
    case03();
    //case02();
    case01();
    return 0;
}