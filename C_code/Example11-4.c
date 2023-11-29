#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 30
#define K 1e6

void Ftick(double (*fp)(double *, int, double));
double Polyf1(double a[], int n, double x);
double Polyf2(double a[], int n, double x);
double Polyf3(double a[], int n, double x);
double Polyf4(double a[], int n, double x);
clock_t start, end;
double dur;
double a[N + 1], x = 1.1;

int main(void)
{
    for (int i = 0; i <= N; i++)
        a[i] = i;
    Ftick(Polyf1);
    Ftick(Polyf2);
    Ftick(Polyf3);
    Ftick(Polyf4);

    system("pause");
    return 0;
}
void Ftick(double (*fp)(double *, int, double))
{               //测试fp所指函数的执行时间，本处是Polyf1~Polyf4
    double sum; // fp的返回值

    start = clock();             //记录下面代码开始执行时的时钟打点数
    for (int i = 1; i <= K; i++) //为了能测出时间，让函数fp执行K次
        sum = fp(a, N, x);
    end = clock();                               //记录上面代码结束时的时钟打点数
    dur = (double)(end - start) / CLK_TCK / K;   //计算函数fp执行一次的时间（秒）
    printf("f(x) = %f, time=%6.2e\n", sum, dur); //输出sum及dur
}

//方法一：使用头文件中的函数double pow(double a,double x),求a的x次幂
double Polyf1(double a[], int n, double x)
{                   //调用头文件math.h中的pow(x,i)求xi的值
    double p, term; //存放f(x)的值,及x的i次幂的值

    p = a[0];
    for (int i = 1; i <= n; i++)
    {
        term = pow(x, i);
        p += a[i] * term;
    }

    return p;
}

//方法二：自己写循环求x的i次幂
double Polyf2(double a[], int n, double x)
{ //用循环计算xi
    double p = a[0];
    double term;

    for (int i = 1; i <= n; i++)
    {
        term = 1;
        for (int j = 1; j <= i; j++) //求xi的值
            term *= x;
        p += a[i] * term;
    }

    return p;
}

//迭代法
double Polyf3(double a[], int n, double x)
{ //用迭代法计算xi
    double p = a[0];
    double term = 1; // term存放xi的值，初始term=x0=1

    for (int i = 1; i <= n; i++)
    {
        term *= x; // xi=xi-1*x
        p += a[i] * term;
    }

    return p;
}

//
double Polyf4(double a[], int n, double x)
{ //秦九韶的从最高阶一项开始迭代的方法
    double p = a[n];

    for (int i = n - 1; i >= 0; i--)
    {
        p = p * x + a[i];
    }

    return p;
}
