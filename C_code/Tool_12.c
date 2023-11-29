//数值转换器
/*
格式控制参数
%d -> 十进制有符号整数
%u -> 无符号十进制整数
%f -> 十进制浮点数
%o -> 八进制数
%x -> 十六进制数
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int NToD(char *num, int n);          //返回将n进制num转换成的十进制数
void DToM(int d, int m, char *mnum); //将十进制数d转换成m进制数mnum

int main(void)
{
    int N, M;                //分别代表进制数
    char Nnum[20], Mnum[20]; //存放N进制数及转换后的M进制数

    printf("要将N进制数Nnum转换成M进制数\n输入N,Nnum,M: ");
    scanf("%d %s %d", &N, Nnum, &M);
    int d = NToD(Nnum, N); //将N进制数Nnum转换成十进制数d
    DToM(d, M, Mnum);      //将十进制数d转换成M进制数Mnum
    printf("%d进制数%s转换为%d进制数为:%s\n", N, Nnum, M, Mnum);
    
    system("pause");
    return 0;
}
int NToD(char *num, int n)
{
    int weight = 1, d = 0; // weight存放各位的权值及num对应的十进制数
    int len = strlen(num); //计算num的长度

    for (int i = len - 1; i >= 0; i--) // n进制数num转换成十进制数
    {
        if (num[i] >= 'a' && num[i] <= 'z') //将字母映射成对应的十进制数
            d += (num[i] - 'a' + 10) * weight;
        else if (num[i] >= 'A' && num[i] <= 'Z')
            d += (num[i] - 'A' + 10) * weight;
        else if (num[i] >= '0' && num[i] <= '9')
            d += (num[i] - '0') * weight;
        weight *= n; //向左移一位，权值变为原来的n倍
    }

    return d;
}
void DToM(int d, int m, char *mnum)
{
    int len = 0, r;
    do
    {
        r = d % m;
        if (r >= 10)
            mnum[len++] = r - 10 + 'A'; //余数大于等于10时映射成字母
        else
            mnum[len++] = r + '0'; //余数小于10时映射成数字
        d /= m;
    } while (d != 0);
    mnum[len] = '\0'; //千万不要漏掉串的结束符
    char t;
    for (int i = 0, j = len - 1; i < j; i++, j--)
    { // mnum数组逆置
        t = mnum[i];
        mnum[i] = mnum[j];
        mnum[j] = t;
    }
}
