/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
 */

//二转十六
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BinToHex(char *bins, char *hexs);

int main(void)
{
    char bins[100], hexs[100]; //存放二进制数、十六进制数
    printf("输入一个二进制数：");
    scanf("%s", bins);
    BinToHex(bins, hexs); //将二进制数bins转换成十六进制数hexs
    printf("二进制数%s对应的十六进制数为:%s\n", bins, hexs);

    system("pause");
    return 0;
}
void BinToHex(char *bins, char *hexs)
{
    int len;            //存放二进制数bins的长度
    len = strlen(bins); //求bins的长度
    int r = len % 4;    //存放对bins从右向左四位一段分组后最左段长度
    int flag = 0;       // flag标志r是否为0，1表示不为0，0表示余数为0
    if (r)
        flag = 1; // flag为1表示最左段不足4位
    int i = 0, k = 0;
    while (bins[i])
    {
        int sum = 0; //存放二进制数4位一段对应的十进制数
        if (flag)
        { //求最左段长度不足4位的二进制数对应的十进制数
            while (r--)
            {
                sum = sum * 2 + bins[i] - '0';
                i++;
            }
            flag = 0;
        }
        else
        { //求长度为4位的二进制数对应的十进制数
            r = 4;
            while (bins[i] && r--)
            {
                sum = sum * 2 + bins[i] - '0';
                i++;
            }
        }
        //将sum转换成十六进制对应的字符
        if (sum >= 10) //值大于等于10时映射成字母A~F
            hexs[k++] = sum - 10 + 'A';
        else //值小于10时映射成对应的数字字符
            hexs[k++] = sum + '0';
    }
    hexs[k] = '\0';
}
