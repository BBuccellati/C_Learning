#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 8 //表示原整数是几进制数

int OcToDec(char *a, int base); //将base（8）进制数a转换成十进制数

int main(void)
{
    char a[20]; // a存放八进制整数
    int tennum; //存放a对应的十进制整数

    scanf("%s", a);
    tennum = OcToDec(a, N); //求N(8)进制数a对应的十进制数
    printf("%d\n", tennum); //输出a对应的十进制数

    system("pause");
    return 0;
}
int OcToDec(char *a, int base) //将base（8）进制数a转换成十进制数
{
    int sum = 0;
    int len = strlen(a);

    for (int i = 0; i < len; i++)
    {
        sum = sum * base + a[i] - '0'; // ASCII码：48='0',秦久韶算法
        printf("%d\n", sum);
    }
    return sum;
}