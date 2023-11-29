#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *p;    // 定义p是指针变量
    int a = 15; // a是整型变量，初始值是5
    p = &a;    // p变量存放a变量的地址

    printf("变量a的值是:%d,变量a的地址是:%X\n", a, &a);
    printf("变量p的值是:%X,变量p指向空间的值是:%d\n", p, *p);
    printf("变量p的地址是:%X,变量p所占空间大小是:%d个字节\n", &p, sizeof(p));

    system("pause");
    return 0;
}