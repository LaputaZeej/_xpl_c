//
// Created by 项鹏乐 on 2022/11/28.
//

#include <stdio.h>


// 9
long long tail_recursion(long long total,
                         int cur) { // warn:Clang-Tidy: Function 'tail_recursion' is within a recursive call chain
    if (cur == 0) {
        return total * 1;
    } else {
        long long sum = total * cur;
        return tail_recursion(sum, cur - 1);
    }
}

long long xpl_factorial(int num) {
    return tail_recursion(1, num);
}

// 0 0
// 1 1
// 2 2
// 3 3
// 4 5
// 5 8
// ...

// 重复计算了
long long xpl_fibonacci(int num) {
    if (num <= 2) {
        return num;
    } else {
        return xpl_fibonacci(num - 1) + xpl_fibonacci(num - 2);
    }
}

/**
 * 那波切啥数
 * @param num index
 * @param cur 当前
 * @param pre 上一个
 * @return
 */
long long xpl_fibonacci_inner(int num, int cur, int pre) {
    if (num <= 0)return cur;
    return xpl_fibonacci_inner(num - 1, cur + pre, cur);
}

long long xpl_fibonacci_advance(int num) {
    return xpl_fibonacci_inner(num, 1, 0);
}

// chapter_10
int sum(int []);

typedef int arr4_int[5];
typedef arr4_int arr_arr4_int[4];
typedef int arr_4_5[4][5];

int sum2d(int rows,int cols,int arr[rows][cols]);
int sum2d_01(int,int,int arr[*][*]);

void case10() {

    // 复合字面量
    int *pt1;
    pt1 = (int[2]){10,20};
    // vla
    int q=4;
    int r =5;
    double sales[q][r];


    int arr[4][5] = {1, 2, 3, 4, 5};
    arr_arr4_int a1 = {1, 2, 3, 4, 5};
    arr_4_5 a2 = {1, 2, 3, 4, 5};

    int aaaaaaaa[][2][2][3][4][5][6] ={};
    int abc = 1;
    const int **pp2; //
    int *p1 = &abc;
    const int n = 13; // 去掉const就一样了
    pp2 = &p1;// 允许这么写，但是const 限定失效 ？是否就是p2类型->int**p2，即 *p2里面的值const int*->int*// 所以步骤2里的&n也转成了int * // 所以真实内存=10//但是直接打印n就是数字13？
    // int *a = &n;
    *pp2 = &n;// The address of the local variable may escape the function局部变量的地址可能对函数进行转义 // 2
    *p1 = 10;
    printf("n = %d \n", *(&n)); //10
    printf("n = %d \n", n);     //13
    printf("n = %d \n", *(&n)); //10

    printf("&n   = %p\n", &n);
    printf("*pp2 = %p\n", *pp2);
    printf("---------");

    //把const int n =13的const去掉就都是10了，我只能理解成const的关系，增加了一个隐藏的指针n'，和n的地址相同但是&n放的是13，n'放的是10。 //error

//    const int b = 999;
//    &b = 2000;

}

#define 整型 int
#define 主函数 main()
#define 输出 printf
#define 开始 {
#define 结束 }
#define 返回 return


整型 主函数 开始
    输出("你好\n");
    case10();
    const int attr[] = {1, 2, 3, 4, 5};
    const int *ptr = attr;

    int x = 20;
    const int y = 23;
    int *p1 = &x;
    const int *p2 = &y;
    const int **pp2;
    p1 = p2; // Assigning to 'int *' from 'const int *' discards qualifiers 从'const int *'赋值给'int *'会丢弃限定符
    p2 = p1; // ok
    int **p3 = &p1;
    pp2 = p3; // Assigning to 'const int **' from 'int **' discards qualifiers in nested pointer types 从'int **'赋值给'const int **'会丢弃嵌套指针类型中的限定符
    int **p4 = &p2;
    printf("p1=%p\n", p1);
    printf("p2=%p\n", p2);
    printf("p3=%p\n", p3);
    printf("p4=%p\n", p4);
    返回 0;
结束



//int main() {
//
//
//    printf("%lld\n", xpl_factorial(5));
//
//    printf("%lld\n", xpl_fibonacci(15));
//
//    printf("%lld\n", xpl_fibonacci_advance(15));
//
//    int a1[] = {1, 2, [6]=10};
//    int a2[] = {1, 2, [6]=10, 11, 12};
//
//    printf("%d,%d",sizeof(a1)/sizeof (int),sizeof (a2)/sizeof (int ));
//
//
//
////    char ch;
////    while ((ch = getchar()) != EOF) {
////        putchar(ch);
////    }
//
////    int a = (500, 499);
////    printf("%d", a);
////
////    int friend = 5;
////    int day;
////    printf("亲手给输入天数>:");
////    scanf("%d", &day);
////    for (int i = 0; i < day; ++i) {
////        friend--;
////        friend = 2 * friend;
////        printf("朋友个数:%-4d (%d)\n", friend,i);
////    }
//
//    return 0;
//}

//int sum(int *arr) {
//
//}
//
//int sumX(int arr[]) {
//
//}