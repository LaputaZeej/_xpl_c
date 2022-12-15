//
// Created by 项鹏乐 on 2022/12/8.
//

#define NDEBUG // 忽略assert
#include  <assert.h>
#include "../Utils.h"
#include <math.h>

inline static void eatLine() {
    while (getchar() != '\n')
        continue;
}

#define PI  4.0*atan(1)
#define RAD_TO_DEG (180.0/(4.0*atan(1)))

#include <limits.h>
//_Static_assert(CHAR_BIT == 16,"16-bit char falsely assumed");


// 可变参数
#include "stdarg.h"

double sum(int ,...);
void case001(){
    double s,t;
    s = sum(3,1.1,2.5,3131.1);
    t = sum(4,1.0,2.0,3.0f,5);
    printf("s=%lf\n",s);
    printf("t=%lf\n",t);
    FenGeXian();
}

double sum(int lim,...){
    va_list  ap;        // 声明一个对象存储参数
    double total = 0;
    int i;
    va_start(ap,lim); // 把ap初始化为参数列表
    for (i = 0;  i<lim ; i++) {
        total += va_arg(ap,double) ; // 访问参数列表中的每一项
    }
    va_end(ap); // 清理工作
    return total;
}

int main() {
    case001();
    double pi = PI;
    assert(pi<3);
    printf("%lf\n", pi);
    //eatLine();
    return 0;
}
