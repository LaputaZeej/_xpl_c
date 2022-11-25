//
// Created by 项鹏乐 on 2022/11/22.
//

#include <math.h>
#include "Utils.h"
#include <assert.h>
#include <string.h>


// 水仙花数，自幂数
void case01() {
    for (int i = 0; i < 100000; ++i) {
        int size = 1;
        int tmp = i;
        int sum = 0;
        while (tmp /= 10) {
            size++;
        }
        tmp = i;
        while (tmp) {
            sum += pow(tmp % 10, size);
            tmp /= 10;
        }
        if (sum == i) {
            printf("%d\n", i);
        }
    }

}

void case02() {
    int line = 12;
//    printf("请输入：");
//    scanf("%d",&line);
    char *space = " ";
    char *star = "*";
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < line - 1 - i; ++j) {
            printf("%s", space);
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            printf("%s", star);
        }
        printf("\n");
    }
    for (int i = 0; i < line - 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%s", space);
        }
        for (int j = 0; j < 2 * (line - 1 - i) - 1; ++j) {
            printf("%s", star);
        }
        printf("\n");
    }
}

void case03() {
    // 喝汽水
    // 20 20 20
    //    10 10
    //     5  5
    //     2  2
//           3  3
//           2  2
//           1 2
//           1
    int price = 1;
    int swap = 4;
    int money;
    printf("喝汽水，%d元/瓶,%d个空瓶还一瓶新的汽水。请输入金额：", price, swap);
    scanf("%d", &money);
    int total = money / price;//买了多少瓶
    printf("买了%d瓶汽水\n", total);
    int empty = total; // 剩下多少个空瓶
    printf("喝完有%d个空瓶\n", empty);

    int count = 0;
    int jie = 0;
    while (empty > 0) { // 空瓶换不了了。
        printf("    ---------%d---------\n", count);
        if (jie > 0) {
            empty -= jie;
            printf("    还%d个空瓶\n", jie);
            jie = 0;
            if (empty <= 0)break;
        }
        int temp;
        int left;
        if (swap - empty > 0) {
            int yes = 0;
            int shao = swap - empty;
            if (shao != 1)break;
            printf("    是否借给用户%d瓶，1：是；2：否 >:", shao);
            scanf("%d", &yes);
            if (yes == 1) {
                jie = shao;
                printf("    借了%d个空瓶\n", jie);
                temp = 1;
                left = 0;
            } else {
                break;
            }
        } else {
            temp = empty / swap; // 2个空瓶兑换一个新的20
            left = empty % swap;
        }
        printf("    %d个空瓶兑换一个新的,一共换了%d瓶汽水,还剩下%d个空瓶\n", swap, temp, left);
        total += temp;
        printf("    继续喝,一共%d瓶\n", total);
        empty = temp + left; // 空瓶增加
        printf("    喝完剩下空瓶数量：%d\n", empty);
        count++;
    }

    printf("最终可以喝%d瓶，还剩下空瓶:%d\n", total, empty);
    FenGeXian();
}

void left_hand(char *first, int k) { // 这里能不能区分是字符串首地址，还是数组首地址？
    assert(first);
    // abcdefg
    // bcdefga
    // cdefgab
//    int len = my_strLen(first);
    int len = strlen(first);
    for (int i = 0; i < k; ++i) {
        char tmp = *first;
        for (int j = 0; j < len - 1; j++) {
            char *pre = first + j;
            char *aft = pre + 1;
            printf("%p,%p,%c,%c \n", pre, aft, *pre, *aft);
            *pre = *aft; //  如果是字符串就报错error
        }
        *(first + len - 1) = tmp;
    }
}

void left_hand_01(char first[7], int k) { // 这里能不能区分是字符串首地址，还是数组首地址？
    assert(first);
    // abcdefg
    // bcdefga
    // cdefgab
//    int len = my_strLen(first);
    int len = strlen(first);
    for (int i = 0; i < k; ++i) {
        char tmp = *first;
        for (int j = 0; j < len - 1; j++) {
            char *pre = first + j;
            char *aft = pre + 1;
            printf("%p,%p,%c,%c \n", pre, aft, *pre, *aft);
            *pre = *aft; //  如果是字符串就报错error
        }
        *(first + len - 1) = tmp;
    }
}

void reverse(char *left, char *right) {
    assert(left != NULL);
    assert(right != NULL);
    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

void left_hand_advance(char *first, int k) {
    assert(first != NULL);
    // ab cdefg
    // ba gfedc
    // cdefgab
    int len = my_strLen(first);
    assert(k <= len);
    reverse(first, first + k - 1); // left
    reverse(first + k, first + len - 1);//right
    reverse(first, first + len - 1);;//all

}

// 左旋字符串
void case04() {
    char str[] = "abcdefg";
    const char *const str1 = "abcdefg"; // 如果是这样 就错了。字符串不能改变
    printf("%s\n", str);
//    left_hand(str, 2);
//    left_hand(str1, 2);
//    left_hand_01(str, 2);
    left_hand_advance(str, 2);
    printf("%s", str);
    FenGeXian();
}

// 杨氏矩阵
// 上到下 左到右 从小到大
// 1 2 3
// 2 3 4
// 3 4 5

int find(int arr[3][3], int row, int col, int k) {
    int x = 0;
    int y = col - 1;
    while (x < row && y > 0) {
        if (arr[x][y] > k) {
            y--;
        } else if (arr[x][y] > k) {
            x++;
        } else {
            return 1;
        }
    }
    return 0;
}

void case05() {
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 7;
    find(arr, 3, 3, k);
}

int main() {
    case04();
//    case03();
//    case02();
//    case01();
    return 0;
}

