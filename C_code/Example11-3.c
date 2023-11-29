//【例11-3】表达式求值问题
#include <stdio.h>
#include <stdlib.h>

int Isop(char ch);                  //判断ch是否为运算符，是返回1，否则返回0
int Priority(char op);              //返回运算符op的优先级，整数大小代表优先级大小
int Compute(int x, char ch, int y); //返回x op y的计算结果

int main(void)
{
    int a, b, c;
    char op1, op2;
    printf("输入表达式: a op1 b op2 c= \n");
    scanf("%d %c %d %c %d", &a, &op1, &b, &op2, &c);
    getchar();                    //接收'='
    if (!Isop(op1) || !Isop(op2)) // op1和op2中有一个不是"+,-,*,/"，则输出Error
        printf("Error\n");
    else
    {
        if (Priority(op1) >= Priority(op2))
        { //先计算 a op1 b
            if (op1 == '/' && b == 0)
            { //被0除情况
                printf("Divided by 0\n");
                return 0;
            }
            a = Compute(a, op1, b);
            op1 = op2;
            b = c;
        }
        else
        { //先计算 b op2 c
            if (op2 == '/' && c == 0)
            { //被0除情况
                printf("Divided by 0\n");
                return 0;
            }
            b = Compute(b, op2, c);
        }
        //计算上面两种情况后剩余式子
        if (op1 == '/' && b == 0)
        { //被0除情况
            printf("Divided by 0\n");
            return 0;
        }
        a = Compute(a, op1, b);
        printf("%d\n", a);
    }
    system("pause");
    return 0;
}
int Isop(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}
int Priority(char op)
{
    int res; //存放op的优先级整数
    switch (op)
    { //'+'和'-'的优先级一样，'*'和'/'的优先级一样
    case '+':
    case '-':
        res = 1;
        break;
    case '*':
    case '/':
        res = 2;
        break;
    }

    return res;
}
int Compute(int x, char ch, int y)
{
    int res; //存放x ch y的值
    switch (ch)
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
