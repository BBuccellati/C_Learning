#include <stdio.h>
#include <stdlib.h>
struct Date
{
    unsigned int month : 4; // 日期中的月
    unsigned int day : 5;   // 日期中的日
    signed int year : 22;   // 日期中的年
    _Bool isDST : 1;        // 如果是夏令时
};
int main(void)

{
    struct Date birthday = {12, 3, 1980}; // 初始化列表方式初始化变量
    struct Date d;
    printf("%d\n", sizeof(d));
    d.day = 10;
    d.month = 4;
    d.year = 2023;
    d.isDST = 0;
    
    printf("%02d-%02d-%04d\n", d.month, d.day, d.year);
    system("pause");
    return 0;
}
