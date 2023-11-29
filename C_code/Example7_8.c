//数组指针访问二维数组
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    //int a[5][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    int a[5][4] = {{1, 2, 3, 16}, {4, 5, 6, 17}, {7, 8, 9, 18}, {10, 11, 12, 19}, {13, 14, 15, 20}};
    int(*p)[4] = a; // 指向第一行 p为一个二级指针
    int sum = 0;
    printf("%x \n",*p);//*p所存放的值也还是地址
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
            sum += *(*p + j);   //遍历第一行三个元素，循环最后指针指向此行最后一个元素的地址
        p++; // 指向下一行,将p存放的地址向后移动4*sizeof(int)字节
    }

    printf("sum = %d\n", sum);
    system("pause");
    return 0;
}
