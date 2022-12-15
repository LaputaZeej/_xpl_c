//
// Created by 项鹏乐 on 2022/12/8.
//
#include <stdio.h>
#include <string.h>

char *s_gets(char *st,int n){
    char *ret_val;
    char *find;
    ret_val = fgets(st,n,stdin);
    if(ret_val){
        find = strchr(st,'\n'); // 查找换行符
        if(find){                       // 如果地址不是null
            *find = '\0';               // 在此处放置一个 空字符
        }else{
            while (getchar()!='\n')      //处理剩余输入行
                continue;
        }
    }
    return ret_val;
}