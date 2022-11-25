//
// Created by 项鹏乐 on 2022/10/28.
//

#include <stdio.h>
#include <string.h>
#include "x_swap.h"

void t1() {
    printf("hello \n");
    char ch1[] = "sssss";
    char ch2[20] = "";
    strcpy(ch2, ch1);
    printf("%s\n", ch2);
}

void t2() {
    char attr[] = "hello world";
    memset(attr, '*', 5);
    printf("%s\n", attr);
}

// 实际参数->形式参数
// 临时拷贝

// 传值调用
// 传址调用
void Swap(int x, int y) {
    printf("错误的交换 \n");
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

void Swap2(int *x, int *y) {
    printf("正确的交换 \n");
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

int isSuSu(int num) {
    int i = 0;
    for (i = 2; i < num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void printSuSu(int start, int end) {
    printf("打印%d-%d之间的素数", start, end);
    int count = 0;
    for (int i = start; i < end; ++i) {
        if (isSuSu(i) == 1) {
            printf("%d ", i);
            count++;
        }
    }
    printf("一共count=%d \n", count);
}

int search(int k, const int attr[], int size) {
    printf("查找\n");
    int left = 0;
//    int right =( sizeof(attr) / sizeof(attr[0])) -1;
    int right = size - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        printf("%d~%d mid=%d\n", left, right, mid);
        if (attr[mid] > k) {
            printf("大了\n");
            right = mid - 1;

        } else if (attr[mid] < k) {
            printf("小了%d\n", mid);
            left = mid + 1;
        } else {
            printf("正好\n");
            return mid;
        }
    }
    return -1;
}

int search2(int k, int attr[]) {
    int size = sizeof(attr) / sizeof(attr[0]);
    printf("attr字节大小%d\n", sizeof(attr));
    printf("attr元素字节大小%d\n", sizeof(attr[0]));
    printf("查找 size = %d\n", size);

    for (int i = 0; i < 4; ++i) {
        printf("--->%d\n", attr[i]);
    }
    printf("attr字节大小%d\n", sizeof(attr));
    printf("attr元素字节大小%d\n", sizeof(attr[0]));
    printf("查找 size = %d\n", size);
    int left = 0;
    int right = (sizeof(attr) / sizeof(attr[0])) - 1;
    while (left <= right) {
        int mid = (right + left) / 2;
        printf("%d~%d mid=%d\n", left, right, mid);
        if (attr[mid] > k) {
            printf("大了\n");
            right = mid - 1;

        } else if (attr[mid] < k) {
            printf("小了%d\n", mid);
            left = mid + 1;
        } else {
            printf("正好\n");
            return mid;
        }
    }
    return -1;
}


int searchIndex(int k, int nums[]) { //error
    int left = 0;
    int size = sizeof(*nums) / sizeof(nums[0]); // 传参之后会退化成指针
    printf("%d \n", nums);
    printf("nums大小:%d\n", size);
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > k) {
            right = mid - 1;
        } else if (nums[mid] < k) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

void test() {
    int nums[] = {1, 3, 5, 7, 11};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("nums大小:%d\n", size);
    int k = 7;
    int r = searchIndex(k, nums);
    printf("结果:%d\n", r);
}

void autoAdd(int *);

// print 1234
// print 123 4
// print 12 3 4
// print 1 2 3 4
void print(int n) {
    if (n > 9) {
        print(n / 10);
    }
    printf("%d ", n % 10);

}

int x_str_len(char *attr) {
    int count = 0;
    while (*attr != '\0') {
        count++;
        attr++;
    }
    return count;
}

int x_str_len_elc(char *attr) {
    if (*attr != '\0') {
        return 1 + x_str_len_elc(attr + 1);
    } else {
        return 0;
    }
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

// 1 1 2 3 5 8
int fib(int n) {
    if (n > 2) {
        return fib(n - 1) + na(n -2);
    } else {
        return 1;
    }
}

int x_fib(int n) {
    int n1 = 1;
    int n2 = 1;
    int n3 = 1;
    while (n > 2) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        n--;
    }
    return n3;
}

int main() {
    printf("nabo：%d\n", fib(5));
    printf("nabo：%d\n", x_fib(5));
    printf("阶乘：%d\n", factorial(15));
    char attr[] = "hello c";
    int len = x_str_len(attr);
    printf("长度：%d\n", len);
    int lenElc = x_str_len_elc(attr);
    printf("长度：%d\n", lenElc);
//    t1();
//    t2();
    int a = 5;
    int b = 6;
    Swap(a, b);
    printf("a=%d,b=%d\n", a, b);
    Swap2(&a, &b);
    printf("a=%d,b=%d\n", a, b);
    printSuSu(100, 200);
    int k = 5;
    int nums[] = {1, 3, 5, 6, 7, 8, 9, 11, 13};
    int index = search(k, nums, sizeof(nums) / sizeof(nums[0]));
    printf("nums字节大小%d\n", sizeof(nums));
//    int index = search(k, nums);
    printf("位置：%d\n", index);
//    test();

    int aaaa = 0;
    autoAdd(&aaaa);
    printf("aaaa=%d\n", aaaa);

    int x1 = 5;
    int x2 = 56;
    x_swap(&x1, &x2);
    printf("x1=%d,x2=%d\n", x1, x2);

    print(123456);
    return 0;
}


void autoAdd(int *num) {
    (*num)++;
}


