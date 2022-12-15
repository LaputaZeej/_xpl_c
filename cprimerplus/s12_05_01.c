//
// Created by 项鹏乐 on 2022/12/5.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch  =-1 ;
    FILE *fp;
    unsigned long count = 0;
//    if (argc != 2) {
//        printf("usage : %s filename \n", argv[0]);
//        exit(EXIT_FAILURE);
//    }
    char * fileName = "../out/b.txt";
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("can't open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    while (EOF != (ch = fgetc(fp))) {
//        printf("%d-", ch);
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    fp = NULL;
    printf("File: [%s] has %lu 个字符",fileName,count);

    return 0;
}