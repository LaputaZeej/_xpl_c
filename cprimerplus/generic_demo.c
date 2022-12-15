//
// Created by 项鹏乐 on 2022/12/8.
//

#include <stdio.h>

int add_int(int a, int b) {
    int c = a + b;
    printf("%d + %d = %d\n", a, b, c);
    return c;
}

float add_float(float a, float b) {
    float c = a + b;
    printf("%f + %f = %f\n", a, b, c);
    return c;
}

void unSupport(){
    printf("unSupport type \n");
}

