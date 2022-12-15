//
// Created by 项鹏乐 on 2022/12/1.
//

#include <string.h>
#include <stdio.h>
// &(x++); // Cannot take the address of an rvalue of type 'int'
// &(++x); // Cannot take the address of an rvalue of type 'int'

extern char ch; // 如果ch被定义在另一个文件 必须声明

int LAPUTA = 10;

void test() {
    printf("a=%d\n", LAPUTA);
}

int aaa;
int bbb;

int add();

void testExtern(){

    printf("aaa=%d,bbb=%d\n", aaa,bbb);
}

void case0001() {
    LAPUTA = 20;
    printf("LAPUTA=%d\n", LAPUTA);
    test();

    aaa = 10;
    bbb = 100;
    int r = add();
    printf("R=%d\n", r);
    aaa=111;
    testExtern();
    printf("--------\n");
}

int main() {

    case0001();

    int a = 10;
    printf("a=%d\n", a);
    for (int i = 0; i < 5; ++i) {
        auto int a = 20;
        printf("    a=%d\n", a);
    }
    printf("a=%d\n", a);
    return 0;
}
