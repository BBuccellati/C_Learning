/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 8 // M存进制数

void DToM(int d, int m, char *mnum); //将十进制数d转成m进制数，存在mnum中

int main(void)
{
    int d;                // d存十进制数
    scanf("%d", &d);      //输入十进制数d
    char Mnum[100];       //存放d对应的M进制数
    DToM(d, M, Mnum);     //将十进制数d转换成八进制数，存在Mnum中
    printf("%s\n", Mnum); //输出M进制数Mnum

    system("pause");
    return 0;
}
void DToM(int d, int m, char *mnum)
{
    int len = 0, r; //存放mnum的下标，及d%m的值
    do
    {
        r = d % m;
        mnum[len++] = r + '0'; //将对应的整数转换成数字字符
        d /= m;
    } while (d != 0);
    mnum[len] = '\0';
    char t;
    for (int i = 0, j = len - 1; i < j; i++, j--)
    { // mnum数组逆置
        t = mnum[i];
        mnum[i] = mnum[j];
        mnum[j] = t;
    }
} */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 16 // M存进制数

void DToM(int d, int m, char *mnum); //将十进制数d转成m进制数，存在mnum中

int main(void)
{
    int d;                // d存十进制数
    scanf("%d", &d);      //输入十进制数d
    char Mnum[100];       //存放d对应的M进制数
    DToM(d, M, Mnum);     //将十进制数d转换成八进制数，存在Mnum中
    printf("%s\n", Mnum); //输出M进制数Mnum

    system("pause");
    return 0;
}
void DToM(int d, int m, char *mnum)
{
    int len = 0, r; //存放mnum的下标，及d%m的值
    do
    {
        r = d % m;
        if (r >= 10)
            mnum[len++] = r - 10 + 'A'; //将对应的整数转换成字母字符
        else
            mnum[len++] = r + '0'; //将对应的整数转换成数字字符
        d /= m;
    } while (d != 0);
    mnum[len] = '\0';
    char t;
    for (int i = 0, j = len - 1; i < j; i++, j--)
    { // mnum数组逆置
        t = mnum[i];
        mnum[i] = mnum[j];
        mnum[j] = t;
    }
}
