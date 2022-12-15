//
// Created by 项鹏乐 on 2022/12/7.
//

#include <limits.h>
#include <stdbool.h>
#include "../Utils.h"

#define BYTE_MASK_  0xff

void case01() {
    unsigned long color = 0x00ff9988;
    unsigned char blue, green, red;
    blue = color & BYTE_MASK_; //
    green = (color >> 8) & BYTE_MASK_; //
    red = (color >> 16) & BYTE_MASK_; //

    printf("blue=%x\n", blue);
    printf("green=%x\n", green);
    printf("red=%x\n", red);
    FenGeXian();
}


char *itobs(int n, char *ps) {
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, n >>= 1) {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}

void show_bstr(const char *str) {
    int i = 0;
    while (str[i]) {
        putchar(str[i]);
        if (++i % 4 == 0 && str[i]) {
            putchar(' ');
        }
    }
}

void case02() {
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int number;
    puts("输入数字>:");
    while ((scanf("%d", &number) == 1)) {
        itobs(number, bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("bye!");
    FenGeXian();
}

int invert_end(int num, int bits) {
    int mask = 0;
    int bitval = 1;
    while (bits-- > 0) {
        mask |= bitval;
        bitval <<= 1;
    }
    return mask ^ num;

}

void showNumberBit(int num) {
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    itobs(num, bin_str);
    printf("%d is ", num);
    show_bstr(bin_str);
    printf("\n");
}

void case03() {
    int a = 0b111100001110;
    showNumberBit(a);
    int b = invert_end(a, 4);
    showNumberBit(b);
    FenGeXian();
}

struct box_props {
    bool opaque: 1;
    unsigned int fill_color: 3;
    unsigned int : 4;
    bool show_border: 1;
    unsigned int border_color: 3;
    unsigned int border_style: 2;
    unsigned int : 2;
};

int main() {
    case03();
    case02();
    case01();
    return 0;
}