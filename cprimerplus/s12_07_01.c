//
// Created by 项鹏乐 on 2022/12/7.
//
#include "../Utils.h"

# define LIMIT 20
const int LIM = 50;
static int detal[LIMIT];
static int data2[LIM];

#define LIMIT 30

const int LIM2 = 2 * LIMIT;
const int LIM3 = 2 * LIM;

// 变参宏 ... 和 __VA_ARGS__
#define PR(...) printf(__VA_ARGS__)
#define PRX(X, ...) printf("MessageX : " #X " -> " __VA_ARGS__)

//#if  __STDC_VERSION__ != 201111L
//    #error test error1 11
//#endif

// 范型

#define MYTYPE(X) _Generic((X),int:123,float:1.0f,double:"hahah",default:'a')

#define GET_TYPE_NAME(var) _Generic((var),int:"int",float:"float",double:"double",char*:"string",default:"qita")

struct Demo{
    void *value;

};


extern int add_int(int,int);
extern float add_float(float,float);
extern void unSupport(void);

#define ADD1(x,y) _Generic((x),int:add_int(x,y),float:add_float(x,y),default:unSupport())

// 在泛型_Generic的语句中，++ 、*=、 = 等操作都不会让变量发生改变 。
void case001(){
    int x = 1;
    GET_TYPE_NAME(x++);
    GET_TYPE_NAME(++x);
    GET_TYPE_NAME(x+=2);
    GET_TYPE_NAME(x=10);
    printf("x = %d \n",x);
    printf("在泛型_Generic的语句中，++ 、*=、 = 等操作都不会让变量发生改变 。\n");
    FenGeXian();
}

void case002(){

    int a = 10;
    int b =0,c=0;
    _Generic(a+0.1f,int:b,float :c,default:b)++;
    printf("a=%d,b=%d,c=%d\n",a,b,c);

    _Generic(a+=1.1f,int:b,float :c,
    default:b)++;
    printf("a=%d,b=%d,c=%d\n",a,b,c);

    printf("在泛型_Generic的语句中，++ 、*=、 = 等操作都不会让变量发生改变 。\n");
    FenGeXian();
}

int main() {
    ADD1(1111,2222);
    ADD1(1111.0f,2222.0f);
    ADD1(1111.0,2222.0);
    FenGeXian();
    add_int(1,3);
    add_float(2.0f,3.0f);
    FenGeXian();
    case002();
    case001();
    void * t = "abc";
    char * t1 = "abc";
    printf("类型是：%s\n", GET_TYPE_NAME(t));
    printf("类型是：%s\n", GET_TYPE_NAME(t1));


    FenGeXian();

    int a = MYTYPE(4);
    printf("d---->%d\n", a);
    int b = MYTYPE(5.0); // 实际应该是字符串
    printf("d---->%d\n", b);
    char* b1 = MYTYPE(5.0); // 实际应该是字符串
    printf("d1---->%s\n", b1);
    int c = MYTYPE("adada");
    printf("d---->%d\n", c);
    void *d = &(MYTYPE(5.0));
    printf("d---->%p\n", d);
    //void *e = &(MYTYPE("kt")); // Cannot take the address of an rvalue of type 'int'
    //printf("e---->%p\n", e);



    // printf("d---->%s\n", MYTYPE(1.5));
    // printf("d---->%d\n", MYTYPE(4));
    FenGeXian();
    static int detal[LIMIT];
    static int data2[LIM];

    const int LIM2 = 2 * LIMIT;
    const int LIM3 = 2 * LIM;

    PR("hello\n");
    PR("hello,world %s\n", "hahaha");
    PRX(10086, "hello %s %d", "kt", 1024);

    PR("%s %s %s  %s %s %s %d \n", __DATE__, __FILE__, __FILE_NAME__, __TIME__, __TIMESTAMP__, __func__, __LINE__);

    return 0;
}