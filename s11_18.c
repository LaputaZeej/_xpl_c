//
// Created by 项鹏乐 on 2022/11/18.
//

//
// Created by 项鹏乐 on 2022/11/18.
//
#include <stdlib.h>
#include <string.h>
#include "Utils.h"

struct Student {
    char name[20];
    int age;
};

typedef struct Student stu_t;

typedef struct T_CASE T_CASE;

int cmp_int(const void *e1, const void *e2) {
    return *((int *) e1) < *((int *) e2);
}

int cmp_student(const void *e1, const void *e2) {
//    e1=NULL;
//    *e1=NULL;

    return ((stu_t *) e1)->age < ((stu_t *) e2)->age;
}

int cmp_student_by_name(const void *e1, const void *e2) {
    return strcmp(((stu_t *) e1)->name, ((stu_t *) e2)->name);
}

void print_student(const void *item) {
    stu_t *ptr = (stu_t *) item;
    printf("学生姓名:%s,年龄%d", ptr->name, ptr->age);
}

void Print(int *attr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d", attr[i]);
//        printf("%d %p/%p  | ", attr[i], (&(attr[i])), (attr + i * sizeof(int)));
    }
    printf("\n");
}


// 对比传入了制定的类型
void my_print_attr2(stu_t *attr, size_t num, size_t size, void(*print)(const void *)) {
    printf("打印数组个数：%zu,元素大小%zu\n", num, size);
    for (int i = 0; i < num; ++i) {
        void *ptr_01 = attr + i; // 明确了指针类型，指针偏移+i就行了
        void *ptr_02 = &(attr[i]); // 直接取
        printf("%p vs %p ", ptr_01, ptr_02);
        print(ptr_02);
        printf("\n");
    }
}



// 9 8 7 6 5 4 3 2 1           i       j
// 8 7 6 5 4 3 2 1   9      // 1       7     9-1-1
// 7 6 5 4 3 2 1   8 9      // 2       6
// 6 5 4 3 2 1   7 8 9      // 3       5
// 5 4 3 2 1   6 7 8 9      // 4       4
// 4 3 2 1   5 6 7 8 9      // 5       3
// 3 2 1   4 5 6 7 8 9      // 6       2
// 2 1   3 4 5 6 7 8 9      // 7       1
// 1   2 3 4 5 6 7 8 9      // 8       0
//   1 2 3 4 5 6 7 8 9      // 9       -1

void bubble_sort(int *attr, int size) {
    printf("[冒泡排序]总元素个数:%d\n", size);
    Print(attr, size);
    int count = 0;
//    for (int i = 0; i < size; ++i) { // 因为最后一趟只有一个元素，不需要交换，所以可以优化成size-1
    for (int i = 0; i < size - 1; ++i) {
        // 每趟交换的元素个数 size-i；
        int todo = size - i;
        printf("第%d趟,每趟交换的元素个数:%d\n", count, todo);

        for (int j = 0; j < todo - 1; ++j) { // 每趟需要交换的次数：j+1<=size -> j = size-1
            int left = attr[j];
            int right = attr[j + 1];
            printf("---->第%d次交换[%d^%d]\n", j, left, right);
            if (left > right) {
                int temp = attr[j];
                attr[j] = attr[j + 1];
                attr[j + 1] = temp;
            }
        }
        count++;
    }
}

// 快速排序
// void qsort (void* base, size_t num, size_t size,            int (*compar)(const void*,const void*));
void my_qsort() {

}

void case02() {
    stu_t students[5] = {
            {"小米",     20},
            {"kotlin", 10},
            {"cpp",    5},
            {"java",   15},
            {"c",      17}
    };
    int size = sizeof(students) / sizeof(students[0]);
    int width = sizeof(students[0]);
    my_arr_print(students, size, width, print_student);
    qsort(students, size, width, cmp_student);
    my_arr_print(students, size, width, print_student);


}

void case01() {

    int attr2[] = {1, 6, 3, 5, 8, 7, 9};
    Print(attr2, sizeof(attr2) / sizeof(attr2[0]));
    qsort(attr2, sizeof(attr2) / sizeof(attr2[0]), sizeof(attr2[0]), cmp_int);
    Print(attr2, sizeof(attr2) / sizeof(attr2[0]));
    FenGeXian();

    int attr[] = {1, 6, 3, 5, 8, 7, 9};
    int size = sizeof(attr) / sizeof(attr[0]);
    Print(attr, size);
    bubble_sort(attr, size);
    Print(attr, size);
    FenGeXian();


}

void t(int *attr, int num, int size) {
    printf("num=%d,size=%d,%p \n", num, size, attr);
    for (int i = 0; i < num; ++i) {
        int *ptr_01 = attr + i * size;//
        int *ptr_02 = &(attr[i]);
        printf("%d\n", i);
        printf("----ptr_01:[%d]%p\n", *ptr_01, ptr_01);
        printf("----ptr_02:[%d]%p\n", *ptr_02, ptr_02);
    }
}

void case03() {
    int attr[7] = {1, 6, 3, 5, 8, 7, 9};
    int *ptr_0 = attr;
    int num = sizeof(attr) / sizeof(attr[0]);
    int size = sizeof(attr[0]);
    printf("num=%d,size=%d,%p \n", num, size, ptr_0);
    for (int i = 0; i < num; i++) {
        int *ptr_01 = ptr_0 + i;
        int *ptr_02 = &(attr[i]);
        printf("%d\n", i);
        printf("----ptr_01:[%d]%p\n", *ptr_01, ptr_01);
        printf("----ptr_02:[%d]%p\n", *ptr_02, ptr_02);
    }
    FenGeXian();
}


void case04() {
    stu_t students[5] = {
            {"小米",     20},
            {"kotlin", 10},
            {"cpp",    5},
            {"java",   15},
            {"c",      17}
    };
    int size = sizeof(stu_t);
    int num = sizeof(students) / size;
    stu_t *ptr_0 = &(students[0]);
    printf("num=%d,size=%d,%p \n", num, size, students);

    for (int i = 0; i < num; ++i) {
        stu_t *ptr_01 = students + i;
        stu_t *ptr_02 = &(students[i]);
        printf("%d\n", i);
        printf("----ptr_01:[%d]%p\n", ptr_01->age, ptr_01);
        printf("----ptr_02:[%d]%p\n", ptr_02->age, ptr_02);
    }
    FenGeXian();
}

void case05() {
    int num = 0;
    int *ptr_01 = &num;
    void *ptr_02 = &num;
    void *ptr_03 = ptr_01;
    printf("%p %p \n", ptr_01, ptr_01 + 1);
    printf("%p %p \n", ptr_02, ptr_02 + 1);
    printf("%p %p \n", ptr_03, ptr_03 + 1);
    printf("%lu \n", sizeof(void));
    FenGeXian();

}

void case06() {
    stu_t students[5] = {
            {"小米",     66},
            {"kotlin", 33},
            {"cpp",    22},
            {"java",   55},
            {"c",      77}
    };
    size_t size = sizeof(stu_t);
    size_t num = sizeof(students) / size;
    my_arr_print(students, num, size, print_student);
    my_arr_sort(students, num, size, cmp_student_by_name);
    my_arr_print(students, num, size, print_student);
    FenGeXian();

}

void case07() {

    // 《《《《 重点 》》》》》》》
    // 数组名是手元素地址，以下两点例外
    // 1。sizeof（数组名）
    // 2。&数组名
    // 《《《《 重点 》》》》》》》

    int a[] = {1, 2, 3, 4};
    printf("%d\n", sizeof(a));   // 16       16      数组总大小 16字节
    printf("%d\n", sizeof(a + 0)); // 4或8      8
    printf("%d\n", sizeof(*a));  // 4        4
    printf("%d\n", sizeof(a + 1)); // 4或8        8
    printf("%d\n", sizeof(a[1]));// 4        4
    printf("%d\n", sizeof(&a)); // 4或8        8
    printf("%d\n", sizeof(*&a)); // ?        16 // 计算的是数组的大小。数组的地址 解引用 等于=sizeof（a）
    printf("%d\n", sizeof(&a + 1)); // 4或8       8
    printf("%d\n", sizeof(&a[0])); // 4或8      8
    printf("%d\n", sizeof(&a[0] + 1)); // 4或8    8
    FenGeXian();
}

void case08() {
    char arr[] = {'a', 'b', 'c', 'd'};
    printf("%d\n", sizeof(*arr));
    printf("%d\n", sizeof(arr[1]));

//    printf("%d\n",strlen(*arr));//error
//    printf("%d\n",strlen (arr[1]));//error
    FenGeXian();

    int a[3][4] = {0};
    // 4/8   --》15
    // 4
    // 4/8   --》16
    // 4/8   --》16 --》4/8 是第一行第2个元素地址 ，不是第二行地址
    // 4
    printf("sizeof (a+1) = %d\n", sizeof(a + 1));// 4/8 a是第一行的地址，+1 是第二行的地址
    printf("sizeof (&a[0]+1) = %d\n", sizeof(&a[0] + 1));// 4/8 是第二行的地址
    printf("sizeof (*a) = %d\n", sizeof(*a));// 16
    printf("sizeof (a[3]) = %d\n", sizeof(a[3]));// 16
}

void case09() {
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = (int *) (&a + 1); // 数组末尾的指针
    // int (*ptr_arr)[5] = &a;
    // &a+1 *数组+1  实际的地址是 ptr_arr+1
    // a+1  元素地址+1 ->2

    printf("%d,%d\n", *(a + 1), *(ptr - 1)); // 2 5
    FenGeXian();

}

struct T_CASE {
    int num;
    char *pcName;
    short sDate;
    char ch[2];
    short sBar[4];
} *p; // 已知结构体变量大小是20个字节,p -> 0x10 00 00 00

void case10() {
    p = (struct T_CASE *) 0x1000000000000000;
    printf("%d \n", sizeof(struct T_CASE));
    printf("%p \n", p + 0x1);
    printf("%p \n", (unsigned long) p + 0x1); // 为什么还能用指针打印？不是一个长整形
    //printf("%lu \n", (unsigned long) p + 0x1); // 为什么还能用指针打印
    printf("%p \n", (unsigned int *) p + 0x1);
    printf("%p \n", (unsigned long *) p + 0x1);
    FenGeXian();
}

void case11() {
    int a[4] = {1, 2, 3, 4};
    int *ptr1 = (int *) (&a + 1); // 4
    int *ptr2 = (int *) ((int) a + 1); // Cast to 'int *' from smaller integer type 'int'
    //int *ptr2 = (int *) ((long) a + 1); //这样就好了！a不会丢失高位
    int *ptr3 = (long *) ((long) a +1); // Incompatible pointer types initializing 'int *' with an expression of type 'long *'
    printf("ptr2=%p\n", ptr2);
    printf("ptr3=%p\n", ptr3);
    printf("%x\n", ptr1[-1]); // 4
    // printf("%x\n", *ptr2); // 因为被截断了 找不到地址 error：Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)
    printf("%x\n", *ptr3);

    // (int*)(a+1)强转时导致高位4个字节丢失，只剩下后面4个字节。使用时就报非法使用内存？
    // 换成（long*)(a+1)就不存在此问题。

    FenGeXian();
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(long *));
}

void case12() {
    // 小端环境，打印什么
    int a[4] = {1, 2, 3, 4};
    int *ptr1 = (int *) (&a + 1); // 4
    int *ptr2 = (int *) ((int) a + 1);
    printf("%x\n", ptr1[-1]);
    printf("%x\n", *ptr2);
}


int main() {
    case12();
    case11();
//    case10();
//    case09();
//    case08();
//    case07();
//    case06();
//    case05();
    // case04();
//    case03();
//    case02();
//    case01();
    return 0;
}


