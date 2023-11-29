#include <stdio.h>

int IsLeap(int y);                                                       //判断y年是否为闰年，是返回1，否则返回0
void WeekValue(int y);                                                   //求y年各个月1日的星期值，存到weekofmonth数组中
void MonCalendar(int y, int m);                                          //打印y年m月的月历表
int monthdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //非闰年每个月的天数
int weekofmonth[13];                                                     //存放某年各个月1日是星期几

int main(void)
{
    int year, month;               //存放要输入的年月值
    scanf("%d %d", &year, &month); //输入年月值
    WeekValue(year);               //用打表法求year年每月1日是星期几
    MonCalendar(year, month);      //输出year年month月的月历表

    return 0;
}
int IsLeap(int y)
{
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}
void WeekValue(int y)
{
    int days = 0; //存放y年各个月1日是1900年后的天数对 7 求余所得的数

    for (int i = 1900; i < y; i++)
    {
        if (IsLeap(i))
            days += 366 % 7;
        else
            days += 365 % 7;
    }
    if (IsLeap(y))
        monthdays[2] = 29;
    for (int i = 1; i <= 12; i++) //计算y年1至12月各个月1号的星期值
    {
        weekofmonth[i] = (days + 1) % 7;
        days += monthdays[i];
    }
}
void MonCalendar(int y, int m)
{
    // months存放各个月英文单词串
    char months[13][15] = {"", "January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

    printf("\t%s(%d)\n", months[m], y);      //输出 月（年）
    printf("Sun Mon Tue Wed Thu Fri Sat\n"); //输出星期简写
    for (int i = 0; i < weekofmonth[m]; i++) //输出1日前的w个空白
        printf("    ");
    if (IsLeap(y))
        monthdays[2] = 29;
    else
        monthdays[2] = 28;
    int k = weekofmonth[m];
    for (int i = 1; i <= monthdays[m]; i++) //输出1至月末日期，每7个换行
    {
        printf("%3d ", i);
        k++;
        if (k % 7 == 0)
            printf("\n");
    }
    printf("\n");
}
