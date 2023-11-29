#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[5] = {1, 3, 5, 7, 9};
    int i = 0;
    int *p = a;
    p[2] = 10;
    printf("a数组的首地址是:%p\n", a);

    for (i = 0; i < 5; i++) // 使用指针变量p输出数组a每个单元的地址及数组元素值
        printf("  a[%d]的地址是：%p a[%d]的值是：%d\n", i, p + i, i, *(p + i));
/* 
    for(i = 0; i < 5; i++)      //使用指针变量p输出数组a每个单元的地址及数组元素值
    {
        printf("a[%d]的地址是：%p a[%d]的值是：%d\n", i, p, i, *p);
        p++;                    //表示p指向下一个数组单元
    }

    p = &a[4];              //p指向数组a的第5个元素
    while(p >= a)           //同类型的指针值是可以比较大小的
    {
        printf("%d\n",*p);
        p--;                //p指向前一个数组单元
    } */
    double x;
    double *q = &x;


    printf("%p  %p\n", q, q + 1);
    system("pause");
    return 0;
}
