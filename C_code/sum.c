#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int sum(int n);
int sum_1(int n);
//double pow_1(double a, int n);
// 递归求a的n次幂
double pp(double a, int n) // a为底数，n为次数
{
    if (n == 0)
        return 1; // 递归出口
    if (n == 1)
        return a;                             // 递归出口
    return pp(a, n / 2) * pp(a, n - n / 2); // 递归调用
}
int main()
{
    int n;
    double a;
    printf("请先输入n,再输入a的值");
    scanf("%d %lf", &n,&a);
    printf("n=%d b=%lf\n",n,a);
    printf("1到%d的和是:%d\n", n, sum(n));
    printf("1到%d的和是:%d\n", n, sum_1(n));
    printf("%lf的%d次幂是:%lf\n", a, n, pow(a,n));
    system("pause");
    return 0;
}
// 求和函数
int sum(int n)
{
    int s = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}
// 嵌套求和函数,递归调用
int sum_1(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sum_1(n - 1);
}
