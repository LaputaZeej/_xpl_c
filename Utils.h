//
// Created by 项鹏乐 on 2022/11/7.
//

#ifndef _XPL_C_UTILS_H
#define _XPL_C_UTILS_H

#include <stdio.h>
#include <assert.h>

void FenGeXian();


long my_strLen(const char *str);

char *my_strCpy(char *dest, const char *source);

int sys_check();

/**
 * 数组打印
 * @param attr 数组首元素指针
 * @param num  整个数组字节大小
 * @param size 单个元素字节大小
 * @param compare 打印函数。一个函数指针：参数是1个待打印元素的指针（指针常量，指针可修改，内容不可修改）；返回void。
 */
void my_arr_print(void *base, size_t num, size_t size, void(*print)(const void *));

/**
 * 数组排序
 * @param attr 数组首元素指针
 * @param num  整个数组字节大小
 * @param size 单个元素字节大小
 * @param compare 比较函数。一个函数指针：参数是2个待比较元素的指针（指针常量，指针可修改，内容不可修改）；返回int。
 */
void my_arr_sort(void *base, size_t num, size_t size, int(*compare)(const void *v1, const void *v2));


void* my_mem_cpy(void*dest,const void * source,size_t size);
void* my_mem_move(void*dest,const void * source,size_t size);

#endif //_XPL_C_UTILS_H
