#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    int *a = NULL; // 定义指针变量并初始化为空指针
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int)); // 动态分配 n个整型空间
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int x, sum = 0;
    scanf("%d", &x);    //输入一个待检测数字
    for (int i = 0; i < n; i++)
        if (x == a[i])  //若待检测数字在一维动态数组中出现一次，则sum就加一
            sum++;
    printf("%d\n", sum);
    free(a); // 释放a指针指向的n个整型空间
    system("pause");
    return 0;
}