//
// Created by 项鹏乐 on 2022/11/15.
//

#include "Utils.h"
#include <string.h>

struct Stu {
    char name[20];
    short age;
    char tel[12];
    char sex[5];
} s1, s2, s3;

typedef struct Stu stu_t;

struct School {
    char name[20];
    stu_t stu;
};

typedef struct School school_t;

/**
 * 浪费空间 实惨->形参 copy
 * @param school
 */
void SchoolPrint(struct School school) {
    printf("%s\n", school.stu.name);
}

void SchoolPrint2(struct School *school) {
    printf("%s\n", school->stu.name);
}

void SchoolPrint3(school_t *school) {
    printf("%s\n", school->stu.name);
}

void test(void) {
    printf("test !\n");
}

void case01() {
    // 注意char = '\0'
    char a[1000];
    for (int i = 0; i < 1000; ++i) {
        a[i] = -1 - i;
    }
    printf("%d == %d? = %d\n",0,'\0',0=='\0');
    printf("a的长度%d\n", strlen(a));
    printf("a的长度%d\n", my_strLen(a));
}

void case02(){
    int n = 9;
    float *ptr = (float *)&n;
    printf("%d\n",n);
    printf("%f\n",*ptr);
    *ptr = 9.0;
    printf("%d\n",n);
    printf("%f\n",*ptr);

}


int main() {
    // 浮点数存储
    // 9.0
    // 1001.0000
    // (-1)^0 *1.001 *2^3
    // (-1)^S * M * 2^E    // ieee754
    // S 0
    // M 1.001
    // E 3
    //        S  E                  M
    // float  1  8（无符号+127）     23
    // double 1  11（无符号+1203）   52
    case02();
    FenGeXian();
    case01();
    FenGeXian();
//    unsigned int x;
//    for (x = 9; x >= 0; x--) {
//        printf("x=%u\n", x);
//    }
    FenGeXian();
    // 错误的思想
    // 1111_1111
    // 1000 0000
    // 1000 0001 // 补码
    // 1111 1111 1111 1111 1111 1111 1000 0001 // 提升到int 补符号位1
    // 1000 0001 // 无符号位截断

    // 正确的思路
    // -128
    // 1000 0000 0000 0000 0000 0000 1000 0000 // 原码 -128
    // 1111 1111 1111 1111 1111 1111 0111 1111 // 反码
    // 1111 1111 1111 1111 1111 1111 1000 0000 // 补码
    // %u = 1111 1111 1111 1111 1111 1111 1000 0000 无符号
    // %d = 1000 0000 // 128
    char abc = -128;
//    char abc = 128; // unsigned char 127+1 = -128 ； -1+1=0
    unsigned char abcd = -128;
    printf("%u\n", abc); // 打印十进制无符号数字
    printf("%d\n", abcd);// 打印十进制有符号数字

    // -1
    // 原码 1000 ... 00000001
    // 反码 1111 ... 11111110
    // 补码 1111 ... 11111111
    // a  1111_1111
    // b  1111_1111
    // c  1111_1111
    // 打印 类型提升
    // a 有符号补符号 1111 ... 1111_1111  = -1
    // b 有符号补符号 1111 ... 1111_1111  = -1
    // c 五符号补0   0000 ... 1111_1111  = 255

    char a = -1;
    signed char b = -1;
    unsigned char c = -1;
    printf("%d,%d,%d \n", a, b, c);

    //  0x00000001
    // 大端模式 大端字节序    00 00 00 01
    // 低--------------------->高
    // 小端模式 小端字节序    10 00 00 00
    if (sys_check() == 1) {
        printf("小端\n");
    } else {
        printf("大端\n");
    }

//    int a = 1;
//    char *ptr_c = (char *) &a;
//    if (*ptr_c == 1) {
//        printf("小端\n");
//    } else {
//        printf("大端\n");
//    }
    FenGeXian();

    // 原码
    // 反码 = 原码->符号位不变，其他位取反
    // 补码 = 反码+1


//   test(11);
    test();

    FenGeXian();
    int num = 10;
    int *p = &num;
    *p = 20;

    //指针常量
    const int *ptr1 = &num; // 在int*前，修饰指针变量里面的值*ptr1？
    // *ptr1 = 20; // 内容const了
    ptr1 = &num; // 指针可变

    //常量指针
    int *const ptr2 = &num; // 在int*后，修饰指针变量本身ptr2？
    *ptr2 = 20; //内容可变
    // ptr2 = &num; // 指针const了

    // 结婚前，不给钱可以换人；结婚后，不换人可以给钱。

    FenGeXian();
    char str1[] = "hello world";
    char str2[] = {0};
    char *ptr = str2;
    my_strCpy(ptr, str1);
    printf("str2=%s,len=%ld\n", str2, my_strLen(str2));

//    char str3[] = {0};
//    ptr = str3;
//    printf("ptr=%p\n", ptr);
    FenGeXian();
    struct Stu stu1 = {"zee", 20, "132213131131", "男"};
    stu_t stu2 = {"lap", 18, "1322131311134", "女"};
    struct School school = {"xxxx", stu1};
    school_t school2 = {"xxxx", stu1};
    printf("%s\n", school.stu.name);

    SchoolPrint(school);
    SchoolPrint2(&school);
    SchoolPrint3(&school2);

    return 0;
}
