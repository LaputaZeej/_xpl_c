#include <printf.h>
#include <string.h>
#include "x_swap.h"

void bubble(int attr[], int size) {
    int i = 0;// 趟数
    for (i = 0; i < size - 1; ++i) {
        // 交换
        int k = 0;
        for (k = 0; k < size - 1 - i; ++k) {
            if (attr[k] > attr[k + 1]) {
                int temp = attr[k];
                attr[k] = attr[k + 1];
                attr[k + 1] = temp;
            }
        }
    }

}

//void bubble2(int attr[], int size) {
void bubble2(int *attr, int size) {
    int i = 0;// 趟数
    for (i = 0; i < size - 1; ++i) {
        printf("第%d趟\n", i + 1);
        // 交换
        int k = 0;
        int flag = 1; //假设已有序
        for (k = 0; k < size - 1 - i; ++k) {
            if (attr[k] > attr[k + 1]) {
                int temp = attr[k];
                attr[k] = attr[k + 1];
                attr[k + 1] = temp;
                flag = 0;
            }
        }
        if (flag == 1)break;
    }

}

//
// Created by 项鹏乐 on 2022/10/28.
//
int main() {
    int a = 5;
    int b = 7;
    printf("a,b = %d,%d \n", a, b);
    x_swap(&a, &b);
    printf("a,b = %d,%d \n", a, b);
    printf("\n----------\n");
    int nums_1[] = {9, 1, 2, 3, 4, 5, 6, 7, 8};
    printf("%p\n", nums_1);
    printf("%p\n", nums_1 + 1);
    printf("%p\n", &nums_1[0]);
    printf("%p\n", (&nums_1[0]) + 1);
    printf("%p\n", &nums_1);
    printf("%p\n", (&nums_1) + 1);

    printf("\n----------\n");
    //int nums[] = { 8, 7, 6, 5, 3, 1,9};
    int nums[] = {9, 1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(nums) / sizeof(nums[0]);
    bubble2(nums, size);
    for (int i = 0; i < size; ++i) {
        printf("%d", nums[i]);
    }
    printf("\n----------\n");
    char arr1[] = "abcdef";
    char *ptr_attr1 = arr1;
    printf("%d\n", sizeof(arr1));       // 7
    printf("%d\n", strlen(arr1));   //6
    printf("%d\n", sizeof(ptr_attr1));   //8
    // ...........................
    char arr2[] = "abc";
    char arr3[] = {'a', 'b', 'c'};
    printf("%d\n", sizeof(arr2)); // 4
    printf("%d\n", sizeof(arr3)); // 3
    printf("%d\n", strlen(arr2)); // 3
    printf("%d\n", strlen(arr3)); // ?
    return 0;
}
