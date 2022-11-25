//
// Created by 项鹏乐 on 2022/11/7.
//

#include "Utils.h"
#include <assert.h>

void FenGeXian() {
    printf("***************** 华丽的分割线 ******************\n");
}

long my_strLen(const char *str) {
    assert(str != NULL);
    const char *start = str;
    const char *end = str;
    while (*end != '\0') {
        end++;
    }
    return end - start;
}


char *my_strCpy(char *dest, const char *source) { // dest ： out , source：const 输入 in
//    if (dest == NULL || source == NULL)return;
    // 方法1：
//    while (*source != '\0') {
//        *dest = *source;
//        source++;
//        dest++;
//    }
//    *dest = *source;

    // 方法2：
//    while (*source != '\0') {
//        *dest++ = *source++;
//    }

    // 方法3：
//    while ((*dest++) = (*source++)) { // Using the result of an assignment as a condition without parentheses
//
//    }

    assert(dest != NULL);
    assert(source != NULL);
//    while (((*source++) = (*dest++))) { // const的意义
//
//    }
    char *ret = dest;
    while (((*dest++) = (*source++))) {
        // dest[0] = source[0]
        // dest++ source++
    }
    return ret;
}

/**
 *
 * @return 1：小端 0：大端
 */
int sys_check() {
    int a = 1;
    char *ptr = (char *) &a;
    if (*ptr == 1) {
        return 1;
    } else {
        return 0;
    }
}

void my_arr_print(void *base, size_t num, size_t size, void(*print)(const void *)) {
    printf("打印数组个数：%zu,元素大小%zu\n", num, size);
    for (int i = 0; i < num; ++i) {
        void *ptr_01 = base + i * size; // void* ：不知道指针是什么，是多大，指针偏移i*size
        void *ptr_02 = &(base[i * size]); // 同样，不知道指针多大，指针偏移i*size
        // printf("%p vs %p ", ptr_01, ptr_02);
        print(ptr_02);
        printf("\n");
    }
}

 void swap(char *buf1, char *buf2, size_t size) {
    for (int i = 0; i < size; ++i) {
        char temp = buf1[i];
        buf1[i] = buf2[i];
        buf2[i] = temp;
    }
}

  void my_swap() {

}

/**
 * 排序
 * @param attr 数组首元素指针
 * @param num  整个数组字节大小
 * @param size 单个元素字节大小
 * @param compare 比较函数。一个函数指针：参数是2个待比较元素的指针（指针常量，指针可修改，内容不可修改）；返回int。
 */
void my_arr_sort(void *base, size_t num, size_t size, int(*compare)(const void *v1, const void *v2)) {
    printf("【排序开始】数组大小:%zu,元素大小:%zu\n", num, size);
    // 冒泡排序
    // 趟数： num-1 //最后一趟只有一个元素，故num-1。
    // 每趟比较次数：num-趟数-1
    for (int i = 0; i < num - 1; ++i) {
        for (int j = 0; j < num - i - 1; ++j) {

            void *left = base + j * size;
            void *right = left + size;
            if (compare(left, right) > 0) {
                // error
//                void temp = *left;
//                *left = *right;
//                *right = temp;
                // 直接转成char*
                swap(left, right, size);
            }
        }
    }
    printf("【排序结束】");
}

//  1 2 3 4 5 6 7 8 9
//      1 2 3 4 5
//  1 2 1 2 1 2 1 8 9  // error
//  1 2 1 2 3 4 5 8 9
void *my_mem_move(void *dest, const void *source, size_t size) {
    assert(dest != NULL);
    assert(source);
    void *ret = dest;
    if (dest < source) {
        // 从前往后
        while (size--) {
            *((char *) dest) = *((char *) source);
            (char *) dest++;
            (char *) source++;
        }
    } else {
        // 从后往前
        while (size--) {
            *((char *) dest+size) = *((char *) source+size);
        }
    }
    return ret;
}

void *my_mem_cpy(void *dest, const void *source, size_t size) {
    assert(dest != NULL);
    assert(source);
    void *ret = dest;
    while (size) {
        *((char *) dest) = *((char *) source);
        (char *) dest++;
        (char *) source++;
        size--;
    }
    return ret;
}