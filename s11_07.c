//
// Created by 项鹏乐 on 2022/11/7.
//
#include "Utils.h"

int main() {



    int i = 1;
    int aa = (++i) + (++i) + (++i);
    printf("a=%d,i=%d \n", aa, i);

    // ,表达式
    // LR  + -
    // 是否控制执行 && ｜| ,

    int a = 11;
    printf("a=%d\n", a);
    a = a | (1 << 2);
    printf("a=%d\n", a);
    a = a & (~(1 << 2));
    printf("a=%d\n", a);
    FenGeXian();
    int num = 123;
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if (1 == ((num >> i) & 1))
            count++;
    }
    printf("%d补码中右几个1：%d\n", num, count);
    count = 0;
    while (num) {
        if (num % 2 == 1)
            count++;
        num = num / 2;
    }
    printf("%d补码中右几个1：%d\n", num, count);

    FenGeXian();
    // 算数右移位 补原符号
    // 逻辑右移位 直接丢弃

    // 原码 反码 补码
    // 存储的是补码
    // -1
    // 1000 0000 0000 0000 0000 0000 0000 0001 【原码】
    // 1111 1111 1111 1111 1111 1111 1111 1110 【反码】原码 符号不变 其他取反
    // 1111 1111 1111 1111 1111 1111 1111 1110 【补码】反码+1
    printf("%d", -1 >> 1);
    return 0;
}
