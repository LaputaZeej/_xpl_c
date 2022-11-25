#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

//int main() {
//    printf("Hello, World!\n");
//
//    printf("char size大小为%d\n", sizeof(char));
//    printf("short size大小为%lu\n", sizeof(short));
//    printf("int size大小为%lu\n", sizeof(int));
//    printf("long size大小为%lu\n", sizeof(long));
//    printf("long long size大小为%lu\n", sizeof(long long));
//    printf("float size大小为%lu\n", sizeof(float));
//    printf("double size大小为%lu\n", sizeof(double));
//
//    int a;
//    int b;
//    scanf("%d%d", &a, &b);
//    int sum;
//    sum = a + b;
//    printf("sum = %d\n", sum);
//
//    int haha = 1;
//    {
//        int haha = 5;
//        haha = 3;
//    }
//    printf("haha=%d", haha);
//
//
//
//    return 0;
//}

#define MAX(X, Y) (X>Y?X:Y)


struct User {
    int age;
    char name[20];
};

int isJi(int num) {
    return num % 2;
}

int sum(int a) { // 5 5 6
    int b = 5;
    printf("    前a,b = %d,%d\n", a, b);
    b = b + a;
    printf("    后a,b = %d,%d\n", a, b);
    return b;
}

void menu() {
    printf("************************\n");
    printf("***********开始1 结束0***\n");
    printf("************************\n");
}

void game() {
    printf("开始游戏！\n");
    int ret = rand() % 100 + 1; // RAND_MAX
    printf("%d\n", ret);
    while (1) {
        printf("猜一猜！\n");
        int guess = 0;
        scanf("%d", &guess);
        if (guess > ret) {
            printf("猜大了！\n");
        } else if (guess < ret) {
            printf("猜小了！\n");
        } else {
            printf("猜对了！\n");
            break;
        }
    }
}


int main() {
//    int input;
//    srand((unsigned int)time(NULL));
//    do {
//        menu();
//        printf("请选择>:\n");
//        scanf("%d", &input);
//        switch (input) {
//            case 1:
//                game();
//                break;
//            case 0:
//                printf("退出游戏!\n");
//                break;;
//            default:
//                printf("再试一次!\n");
//                break;
//        }
//    } while (input);

    int m;
    int n;
    scanf("%d%d", &m, &n);
    printf("求%d,%d的最大公约数\n", m, n);

    int ret;
    do {
        ret = m % n;
        if (ret == 0)break;
        m = n;
        n = ret;
    } while (1);
    printf("最大公约数为:%d\n", n);

//    int i = 0;
//    int count = 0;
//    for (i = 101; i < 200; i+=2) {
//        int j = 0;
//        for (j = 2; j <= sqrt(i); j++) {
//            if (i % j == 0) {
//                break;
//            }
//        }
//        if (j>sqrt(i)){
//            printf("%d\n", i);
//            count++;
//        }
//    }
//    printf("count = %d\n", count);

//    int i = 0;
//    int count = 0;
//    for (i = 100; i < 200; ++i) {
//        int j = 0;
//        for (j = 2; j <= sqrt(i); j++) {
//            if (i % j == 0) {
//                break;
//            }
//        }
//        if (j>sqrt(i)){
//            printf("%d\n", i);
//            count++;
//        }
//    }
//    printf("count = %d\n", count);

//    int i = 0;
//    int count = 0;
//    for (i = 100; i < 200; ++i) {
//        int j = 0;
//        for (j = 2; j <= i/2; j++) {
//            if (i % j == 0) {
//                break;
//            }
//        }
//        if (j>i/2){
//            printf("%d\n", i);
//            count++;
//        }
//    }
//    printf("count = %d\n", count);

//    int i = 0;
//    int count = 0;
//    for (i = 100; i < 200; ++i) {
//        int j = 0;
//        for (j = 2; j <= i; j++) {
//            if (i % j == 0) {
//                break;
//            }
//        }
//        if (j==i){
//            printf("%d\n", i);
//            count++;
//        }
//    }
//    printf("count = %d\n", count);

//    int num = 0;
//    for (int i = 0; i < 3; ++i) {
//        int temp = sum(i);
//        printf("循环结果%d->%d\n",i,temp);
//        num += temp;
//    }
//    printf("结果num=%d\n", num); // (0+5)+(1+5)+(2+5) = 18

//    char attr1[] = "hello kotlin!!!";
//    char attr2[] = "******************";
//    int left = 0;
// //    int right = sizeof(attr2)/sizeof(attr2[0]) -2;
//    int right = strlen(attr2)-1;
//
//    while (left<=right){
//        attr2[left] = attr1[left];
//        attr2[right] = attr1[right];
//        printf("%s\n",attr2);
//        system("clear");
//        left++;
//        right--;
//    }
//    printf("%s\n",attr2);



//    int attr[] = {1, 2, 3, 4, 5, 6, 8, 10, 11, 14};
//    int num = 5;
//    int left = 0;
//    int right = sizeof(attr) / sizeof (attr[0]) - 1;
//
//    while (left <= right) {
//        int mid = (right + left) / 2;
//        printf("left=%d,right=%d,mid=%d\n", left,right,mid);
//        if (num > attr[mid]) {
//            printf("小了\n");
//            left = mid + 1;
//        } else if (num < attr[mid]) {
//            printf("大了\n");
//            right = mid - 1;
//        } else {
//            printf("找到%d了!下标是%d\n", num, mid);
//            break;
//        }
//    }
//    if (left > right) {
//        printf("没有找到\n");
//    }




//    int num  =100;
//    for (int i = 0; i < num; ++i) {
//        if(isJi(i)){
//            printf("%d是奇数\n",i);
//        }
//    }

//    struct User u1 = {20, "aaaaa"};
//    printf("age=%d,name=%s \n", u1.age, u1.name);
//    struct User *pu1 = &u1;
//    printf("age=%d,name=%s \n", (*pu1).age, (*pu1).name);
//    printf("age=%d,name=%s \n", pu1->age, pu1->name);
//    const int n = 10;
//    int attr[n] = {1,2,3,4,5};
//    printf("%d ",attr[0]);
//    int attr1[MAX_SIZE] = {1,2,3,4,5};
//    printf("MAX_SIZE %d ",attr[0]);

//    char hello[] = {'a', 'b', 'c', '\0','d'};

//    char hello[] = {'a', 'b', 'c'};
//    printf("%s\n", hello);
//    printf("%d\n", strlen(hello));
//
//    char h[] = "abc";
//    printf("%d\n", strlen(h));
//    printf("%s\n", h);
//
//    int a1=1;
//    int a2=2;
//    int c = MAX(a1, a2);
//    printf( "c =%d", c);



}