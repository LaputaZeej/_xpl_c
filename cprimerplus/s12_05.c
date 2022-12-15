//
// Created by 项鹏乐 on 2022/12/5.
//

#include <stdlib.h>
#include <time.h>
#include "../Utils.h"
#include "laputa.h"

// 存储类别和函数
// 随机函数
void testFunction() {


    int random = rand(); // Clang-Tidy: Rand() has limited randomness

    printf("%d\n", random);

    FenGeXian();
}

static int testShaiZi(int sides) {
    int roll;
    roll = rand() % sides + 1;
    return roll;

}


void case_12_4() {

    double *ptr = malloc(sizeof(double) * 30);
    if (ptr == NULL)return;
    printf("ptr[1] = %f\n", *(ptr + 1));
    free(ptr);
    ptr = NULL;
    FenGeXian();
}

void testStatic(void);

static int num = 20;

void t1(char arr[static num]) {

}

int main() {

    printf("PI = %f\n", PI);
    testStatic();

    case_12_4();

    // Clang-Tidy: Random number generator seeded with a disallowed source of seed value will generate a predictable sequence of values
    srand((unsigned int) time(0));

    srand(((unsigned int) time(0)));

    unsigned int seed = (unsigned int) time(0);


    srand(seed);

    for (int i = 0; i < 5; ++i) {
        testFunction();

        const int sides = 6;
        int roll = testShaiZi(sides);
        printf("骰子：%d\n", roll);
    }


    return 0;
}
