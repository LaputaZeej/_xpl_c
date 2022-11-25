//
// Created by 项鹏乐 on 2022/11/24.
//
#include <errno.h>
#include "Utils.h"
#include <string.h>
#include <stdio.h>
// 文件
// 程序文件 、 数据文件

// 文本文件：ASCII形式存贮
// 二进制文件：二进制不转换直接存贮

// 10000  5   文本
// 10000  4   二进制
void case01() {
    int a = 10000;
    FILE *pf = fopen("../out/a.txt", "wb");
    fwrite(&a, 4, 1, pf);
    fclose(pf);
    pf = NULL;
    FenGeXian();

}

void case02() {
    FILE *pf = fopen("../out/b.txt", "r");
    if (pf == NULL) {
        printf("文件不存在%s\n", strerror(errno));
        return;
    }
    printf("文件已打开\n");
    char buf[1024] = {0};
    while (fgets(buf, 1024, pf)) {

        printf("%s", buf);
    }
    printf("\n");

    fclose(pf);
    pf = NULL;
    printf("文件已关闭\n");
    FenGeXian();
}

void case03() {
    FILE *pf = fopen("../out/c.txt", "w");
    if (pf == NULL) {
        printf("文件不存在%s\n", strerror(errno));
        return;
    }
    printf("文件已打开\n");

    fputc('z', pf);
    fputc('e', pf);
    fputc('e', pf);
    fputc('\n', pf);
    fputs("烟雨下扬州",pf);

    fclose(pf);
    pf = NULL;
    printf("文件已关闭\n");
    FenGeXian();
}

//
//  磁盘----文件缓冲区----内存
//          -输入缓冲区
//          -输出缓冲区
//

// 文件指针

// stdin FILE*
// stdout FILE*
// stderr FILE*

void case04() {
//    printf("输入字符>:");
//    char c = fgetc(stdin);
//    fputc(c, stdout);
//    FenGeXian();
    char buf[1024] ={0};
//    fgets(buf,1024,stdin);
//    fputs(buf,stdout);
    gets(buf);
    puts(buf);


}

// scanf/printf
// fscanf/fprintf
// sscanf/sprintf

// fread/fwrite/fseek /ftell (起始位置偏移)/rewind(回到起始位置)
// feof  // e o f end of file  -1  // 判断是否结束 正常结束    vs  异常结束
// frror

// perror

void case05(){


}

int main() {

//    case04();
//    case03();
//    case02();
//    case01();
    return 0;
}