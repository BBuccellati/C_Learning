//[11-2] 简单四则运算（OP）
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

/*
库文件stdlib.h中的rand()函数能随机产生0~32767之间的整数

使用srand(time(NULL))函数完成用当前机器的时间设置随机种子
time()函数在头文件time.h中

要随机产生[a,b]的一个整数，0<=a,b<=32767,可用rand()%(b-a+1)+a

*/

int Compute(int x, char op, int y); //计算x op y的值并返回

//如何实现op的随机生成！！！

int main(void)
{
    int n, k;            //存放出题目数，每道题学生可输入答案次数
    int a, b, ans, yans; //存放题中两个操作数、正确答案及学生给的答案
    char op;             //存放运算符

    printf("输入题目数及运算符：\n");
    scanf("%d %c", &n, &op); //输入题目数及运算符
    srand(time(NULL));       //用机器时间设置随机种子
    while (n--)
    {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        ans = Compute(a, op, b); //计算a op b的正确答案
        k = 3;
        while (k--) //每道题至多做3次
        {
            printf("%d %c %d = ", a, op, b);
            scanf("%d", &yans);
            if (yans == ans)
                break; //答案正确，继续下一道题
            else
                printf("no\n"); //答案不正确，输出no，重做
        }
        if (yans != ans) // 3次答案都不正确，输出计算式子与正确答案
            printf("%d %c %d = %d\n", a, op, b, ans);
        else //答案正确，输出ok
            printf("ok!\n");
    }
    system("pause");
    return 0;
}
int Compute(int x, char op, int y)  //计算正确答案的函数
{
    int res;
    switch (op)
    {
    case '+':
        res = x + y;
        break;
    case '-':
        res = x - y;
        break;
    case '*':
        res = x * y;
        break;
    case '/':
        res = x / y;
        break;
    }

    return res;
}