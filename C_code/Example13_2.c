/* #include <stdio.h>
#include <stdlib.h>

struct Date
{ //日期结构类型
    int year, month, day;
};
typedef struct Date Date; //将struct Date定义一个同义词Date
int IsLeap(int y);        //判断y是否是闰年，是返回1，否则返回0
void NextDay(Date *pd);   //将pd所指日期变成下一天日期
int monthdays[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; //每个月的天数

int main(void)
{
    Date today; //存放一个日期
    int n;      //存放天数

    scanf("%d-%d-%d %d", &today.year, &today.month, &today.day, &n);
    for (int i = 1; i <= n; i++) //循环n次求下一天日期即得n天后日期
        NextDay(&today);
    printf("%d-%02d-%02d\n", today.year, today.month, today.day);

    system("pause");
    return 0;
}
int IsLeap(int y)
{
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}
void NextDay(Date *pd)
{
    int leap = 0;         //存放是否是闰年，初始假设pd->year不是闰年
    if (IsLeap(pd->year)) //判断pd所指日期那一年是否是闰年，如果是，则leap=1
        leap = 1;
    if (pd->day < monthdays[leap][pd->month]) //如果pd所指日期不是月末
        pd->day++;                            //下一天日期只修改pd->day
    else if (pd->month < 12)
    { //如果pd所指日期是月末，但不是年末，下一天日期为下月1日
        pd->month++;
        pd->day = 1;
    }
    else
    { //如果pd所指日期是年末，则下一天日期变为下一年的1月1日
        pd->year++;
        pd->month = 1;
        pd->day = 1;
    }
}
 */
#include <stdio.h>
#include <stdlib.h>

struct Date
{ //日期结构类型
    int year, month, day;
};
typedef struct Date Date;           //将struct Date定义一个同义词Date
int IsLeap(int y);                  //判断y是否是闰年，是返回1，否则返回0
int Days(Date dd);                  //返回日期dd是dd.year年的第几天
void NextNDate(int days, Date *pd); //计算pd->year年后days天的日期
int monthdays[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int main(void)
{
    Date today;
    int n;

    scanf("%d-%d-%d %d", &today.year, &today.month, &today.day, &n);
    int sumdays = Days(today); //求today是today.year年的第几天

    NextNDate(sumdays + n, &today); //计算today.year年后sumdays+n天的日期
    printf("%d-%02d-%02d\n", today.year, today.month, today.day);

    system("pause");
    return 0;
}
int IsLeap(int y)
{
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}
int Days(Date dd)
{
    int sum = 0, leap = 0; //分别存放dd.year年后的天数、是否为闰年

    if (IsLeap(dd.year))
        leap = 1;
    for (int i = 1; i < dd.month; i++) //求1月至m-1月的总天数
    {
        sum += monthdays[leap][i];
    }
    sum += dd.day;
    return sum;
}
void NextNDate(int days, Date *pd)
{
    int y, m, yeardays;

    y = pd->year;
    yeardays = 365;
    if (IsLeap(y))
        yeardays = 366;
    while (days > yeardays)
    { //通过循环执行days减去y年的天数，计算所求日期的年份
        days -= yeardays;
        y++;
        yeardays = 365;
        if (IsLeap(y))
            yeardays = 366;
    }
    int leap = 0;
    if (IsLeap(y))
        leap = 1;
    m = 1;
    while (days > monthdays[leap][m])
    { //通过循环执行y年m月天数，计算所求日期的月份
        days -= monthdays[leap][m];
        m++;
    }
    pd->year = y; //分别为所求日期的年、月、日
    pd->month = m;
    pd->day = days;
}
