//
// Created by 项鹏乐 on 2022/11/9.
//

#include "Utils.h"

int main() {
    int aa = -1;
    if (aa > sizeof(aa)) {
        printf("大于\n");
    } else {
        printf("小于\n");
    }
    //
    int a = 10;
    int b = 11;
    int c = 12;
    int *ptr_a = &a;
    int *ptr_b = &b;
    int *ptr_c = &c;
    int *ptr_attr[3] = {ptr_a, ptr_b, ptr_c};
    for (int i = 0; i < 3; ++i) {
        printf("%d\n", *(ptr_attr[i]));
    }
    printf("%p \n", ptr_a);
    printf("%p \n", ptr_attr);
    printf("%p \n", ptr_attr[0]);
    printf("%p \n", ptr_b);
    printf("%p \n", ptr_attr + 1);

    for (int i = 0; i < 3; ++i) {
        printf("%d\n", *(ptr_attr + i));
    }

    // &数组名 整个数组地址
    // sizeof(数组名）整个数组大小 （字节）
    FenGeXian();
    int nums[10] = {0};
    int *ptr_1 = nums;
    int *ptr_2 = &nums[0];
    void *ptr_3 = &nums; // 具体是一个什么类型？
    int *ptr_4 = &nums;
    int *ptr_5 = (int *) &nums;

    int(*ptr_6)[10] = &nums; // 数组指针？ int（*）[]
    // int *ptr_8 [10] = &nums;
    // int[10]* ptr_7 = &nums;



    printf("ptr_1:%p \n", ptr_1);
    printf("ptr_2:%p \n", ptr_2);
    printf("ptr_3:%p \n", ptr_3);
    printf("ptr_4:%p \n", ptr_4);
    printf("ptr_5:%p \n", ptr_5);
    printf("&nums:%p \n", &nums);
    printf("ptr_6:%p \n", &ptr_6);

    printf("ptr_1+1:%p \n", ptr_1 + 1);
    printf("ptr_2+1:%p \n", ptr_2 + 1);
    printf("ptr_3+1:%p \n", ptr_3 + 1);
    printf("ptr_4+1:%p \n", ptr_4 + 1);
    printf("ptr_5+1:%p \n", ptr_5 + 1);
    printf("ptr_6+1:%p \n", ptr_6 + 1);
    FenGeXian();
    char test[] = "abcdefg";
    int len = my_strLen(test);
    printf("len=%d\n", len);
    FenGeXian();
    // 野指针

    // 指针类型的意义
    int arr[10] = {0};
    int *ptr = arr;
//    char *ptr=arr;
    for (int i = 0; i < 10; ++i) {
        *(ptr + i) = i;
    }
    for (int i = 0; i < 10; ++i) {
        printf("arr[%d]=%d \n", i, (arr[i]));
    }

    for (int i = 0; i < 10; ++i) {
        printf("arr[%d]=%d \n", i, *(arr + i));
    }
    return 0;
}