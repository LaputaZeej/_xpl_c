//
// Created by 项鹏乐 on 2022/12/6.
//


// struct

// union

#include <string.h>
#include <stdbool.h>
#include "../Utils.h"

union hold {
    int a1;
    double b;
    char c;
    int a;
};

void case01() {
    union hold valA;
    valA.c = 'c';
    union hold valB = valA;
    union hold valC = {88};
    union hold valD = {.b = 3.14};
    printf("%f\n", valD.b);
    FenGeXian();
}

enum Level {
    low = 100, medium = 200, high = 300
};

enum Fast {
    a, b = 100, c, d
};

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n'); // 查找换行符
        if (find) {                       // 如果地址不是NULL
            *find = '\0';                     //在此处放置一个空字符
        } else {
            while (getchar() != '\n')
                continue;                   // 清理输入行
        }
    }
    return ret_val;
}

enum spectrum {
    red, orange, yellow, green, blue, violet
};
const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

#define LEN 30

void case02() {
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;
    puts("输入一个color 空退出>:");
    while (s_gets(choice,LEN)!=NULL && choice[0]!='\0'){
        for(color=red;color<=violet;color++){
            if(strcmp(choice,colors[color])==0){
                color_is_found = true;
                break;
            }
        }
        if (color_is_found){
            switch (color) {
                case red:
                    puts("红");
                    break;
                case orange:
                    puts("橙");
                    break;
                case yellow:
                    puts("黄");
                    break;
                case green:
                    puts("绿");
                    break;
                case blue:
                    puts("蓝");
                    break;
                case violet:
                    puts("紫");
                    break;

            }
        }else{
            printf("i 不知道 这个颜色%s\n",choice);
        }
        color_is_found=false;
        puts("继续>:");
    }
    puts("再见！");
}

int main() {
    case02();
    case01();
    return 0;
}