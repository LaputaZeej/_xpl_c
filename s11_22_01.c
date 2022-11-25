//
// Created by 项鹏乐 on 2022/11/22.
//


#include <string.h>
#include "Utils.h"

void case01() {
    if (strlen("abc") - strlen("abcdefg") > 0) {
        printf("大于\n");
    } else {
        printf("小于\n");
    }

    char *p1 = "abc";
    char p2[] = {'a', 'b', 'c', '\0','a','c'};
    char *p3 = p2;
    char p4[] = "abc";
    printf("%d\n", strcmp(p1, p2));
    printf("%d\n", strcmp(p1, p3));
    printf("%d\n", strcmp(p1, p4));
    printf("%d\n", strcmp(p3, p4));
    FenGeXian();
}

// 字符串
int main() {
    case01();
    return 0;
}