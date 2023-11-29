//[11-1] 计算IPv6地址能分配多久
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

//用于计算x*2的n次幂
/* double ldexp(double x, int n); */

int main(void)
{
    double x;

    x = ldexp(1.0, 128) / 1000000 / (365 * 24 * 60 * 60);   //计算x
    printf("%e 年\n", x);
    system("pause");
    return 0;
}