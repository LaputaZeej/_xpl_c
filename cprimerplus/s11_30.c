//
// Created by 项鹏乐 on 2022/11/30.
//

// chapter_11 字符串
// 字符串面量string literal
// 字符串常量 string constant
#include  <stdio.h>
#include <string.h>

void case11_01(char str[]) {
    int len = (int) strlen(str);
    printf("长度：%d\n", len);
    for (int i = 0; i < len; ++i) {
        printf("%c ", str[i]);
        *(str + i) = 'x';
    }
    printf("\n");
    for (int i = 0; i < len; ++i) {
        printf("%c ", str[i]);
    }
    printf("\n");
    printf("---------\n");
}

void case11_02(char *str) {
    int len = (int) strlen(str);
    printf("长度：%d\n", len);
    for (int i = 0; i < len; ++i) {
        printf("%c ", str[i]);
        *(str + i) = 'x';//怎么保证str传入的实参是一个数组
    }
    printf("\n");
    for (int i = 0; i < len; ++i) {
        printf("%c ", str[i]);
    }
    printf("\n");
    //printf("---------\n");
}



int main() {
    char a[] = "hello c";
    const char *b = "hello c"; // 用const指明b指定的内容不可以改变
    case11_02(a);
//    case11_02(b); // error // 在这里就有提示Passing 'const char *' to parameter of type 'char *' discards qualifiers

    // a=b; //error
    // b=a; // ok

    const char *aar1[5] = {0}; // 指针数组，每个元素为char数组指针，指针指向的元素是长度为5的char数组
    char aar2[5][10] = {0}; // 二级数组；存放了5个char数组，每个char数组的长度为10

//    char *input;
//    scanf("%s", input); // 可能error input 未分配空间 未定义

    char input1[88];
    //scanf("%s", input1); // ok

    puts("plz 输入>:");
    gets(input1);
    printf("this is : \n");
    printf("%s\n",input1);
    puts(input1);
    puts("Done.");
}
