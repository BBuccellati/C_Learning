#include <time.h>

/*
    C中两种表示时间日期的值
    time_t
    struct tm

    可通过time()函数获得time_t类型的计算机系统的当前日历时间
    gmtime()和localtime()处理日期时间都是以time()的返回值为基础进行运算
    使用gmtime()和localtime()可将time_t类型的时间日期数据转换为struct tm 类型的数据

*/

time_t time(time_t *calptr);                //返回1970-1-1，00:00:00以后经过的秒数
struct tm *localtime(const time_t *calptr); //将calptr时间数值变换成本地时间，考虑到本地时区和夏令时标志
struct tm *gmtime(time_t *timep);           //功能与localtime类似，但返回的时间日期未经时区转换，是UTC时间(又称世界时间，即格林尼治时间)
char *asctime(const struct tm *tp);         //将tp指向的结构转换为字符串形式，如Fri Nov 07 11:41:56 2014
char *ctime(const time_t *tp);              //将tp指向的时间转换为字符串形式。它等价于asctime(localtime(tp))

typedef long clock_t;
typedef  __int32  __time32_t;
typedef __time32_t time_t;

struct tm
{
    int tm_sec;         //秒取值区间为［0,59]
    int tm_min;         //分取值区间为［0,59]
    int tm_hour;        //时取值区间为［0,23]
    int tm_mday;        //一个月中的日期取值区间为［1,31]
    int tm_mon;         //月份（从一月开始，0代表一月）取值区间为［0,11]
    int tm_year;        //年份，其值等于实际年份减去1900
    int tm_wday;        //星期取值区间为［0,6]，其中0代表星期天，1代表星期一
    int tm_yday;        //从每年1月1日开始的天数，其中0表示1月1日
    int tm_isdst;       //夏令时标识符，夏令时tm_isdst为正；否则tm_isdst为0
};

//判断闰年
// y % 400 == 0 || y % 4 == 0 && y % 100 != 0;