//
// Created by 项鹏乐 on 2022/11/23.
//

#include <string.h>
#include "Utils.h"
//#include <cstring.h>

void case01() {
    char str[80];
    strcpy (str, "these ");
    strcat (str, "strings ");
    strcat (str, "are ");
    char *p = strcat (str, "concatenated.");
    puts(str);
    puts(p);

}

struct Cat {
    char name[20];
    int age;
};

typedef struct Cat ca_t;

void print_cat(const void *base) {
    struct Cat *ptr = (struct Cat *) base;
    printf("%s(%d岁)", ptr->name, ptr->age);
}

void print_int(const void *base) {
    printf("%d", *(int *) base);
}

void case03() {
    ca_t cats[] = {{"kt",   20},
                   {"mimi", 10}};
    ca_t dest[5] = {0};
    my_arr_print(dest, sizeof(dest) / sizeof(dest[0]), sizeof(dest[0]), print_cat);
    my_mem_cpy(dest, cats, sizeof(cats));
    my_arr_print(dest, sizeof(dest) / sizeof(dest[0]), sizeof(dest[0]), print_cat);
    FenGeXian();
}

void case02() {

    int attr1[] = {1, 2, 3, 4, 5};
    int arr2[10] = {0};
    my_arr_print(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), print_int);
    //memcpy(arr2, attr1, sizeof(attr1));
    my_mem_cpy(arr2, attr1, sizeof(attr1));
    my_arr_print(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), print_int);
    FenGeXian();
}

void case04() {
    int attr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    my_arr_print(attr, sizeof(attr) / sizeof(attr[0]), sizeof(attr[0]), print_int);
//    memmove(attr+2,attr,20);
//    my_mem_move(attr+2,attr,20);
    my_mem_move(attr, attr + 3, 20);
    my_arr_print(attr, sizeof(attr) / sizeof(attr[0]), sizeof(attr[0]), print_int);
    FenGeXian();

    ca_t cats[] = {{"kt",   20},
                   {"mimi", 10},
                   {"cat1", 9},
                   {"cat2", 9},
                   {"cat3", 9},
                   {"cat4", 9},
                   {"cat5", 9},
                   {"cat6", 9},
    };
    my_arr_print(cats, sizeof(cats) / sizeof(cats[0]), sizeof(cats[0]), print_cat);
    my_mem_move(cats+2,cats,3*sizeof (cats[0]));
    my_arr_print(cats, sizeof(cats) / sizeof(cats[0]), sizeof(cats[0]), print_cat);
}

void case05(){
    // memcmp
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,5,4,5};
    int ret = memcmp(arr1,arr2,8);
    printf("ret=%d\n",ret);
    printf("ret=%d\n",     memcmp(arr1,arr2,9));
    //memset
    char char1[20]={0};
    memset(char1,'#',10);
    for (int i = 0; i < 20; ++i) {
        printf("%c ",char1[i]);
    }
    printf("\n");
    int arr[20]={0};
    memset(arr,1,10); // 10:代表的是1字节
    for (int i = 0; i < 20; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    FenGeXian();
}

int main() {
    case05();
    case04();
    case03();
    case02();
    case01();
    return 0;
}

