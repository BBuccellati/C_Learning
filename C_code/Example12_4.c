#include <stdio.h>
#include <stdlib.h>

int BToTen(int m, int b);       //B进制转换到十进制

int main(void)
{
    int B; //存放进制数
    int p, q, r;
    int x, y, z; //分别存放p,q,r是B进制数时代表的十进制数

    scanf("%d %d %d", &p, &q, &r);
    for (B = 2; B <= 16; B++) //枚举B为2,…,16
    {
        x = BToTen(p, B);
        y = BToTen(q, B);
        z = BToTen(r, B);
        if (x != -1 && y != -1 && z != -1 && x * y == z) //是否满足x*y == z
            break;
    }
    if (B > 16)
        B = 0; // 2~16之间没有满足条件的B
    printf("%d\n", B);

    system("pause");
    return 0;
}
int BToTen(int m, int b)        //B转十，m是待转数，b是B进制
{
    int a = 1; //存放m进制数各位上的位权
    int ten = 0;
    while (m)
    {                   //从右向左求m各个位上的数是否为b进制数
        int r = m % 10; //求m各个位上的数
        if (r >= b)     //如果r大于等于b，说明r不是b进制，返回-1
            return -1;
        ten += a * r;
        a *= b; //用迭代法求m进制数的位权
        m /= 10;
    }

    return ten;
}