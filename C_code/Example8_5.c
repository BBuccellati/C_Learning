#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union Data // 联合类型定义
{
    int i;        // 整型成员
    double x;     // 浮点成员
    char str[16]; // 字符串成员
};
int main(void)
{
    union Data var;
    printf("%d\n", sizeof(var)); //sizeof(var) = sizeof(var.str) = 16
    var.x = 1.25;
    var.i = 5;
    for (int i = 0; i <= sizeof(double) - 1; i++) // 输出前8个字节空间内容
        printf("%02X ", (unsigned char)var.str[i]); 
    printf("\n");
    printf("%d\n", var.i); // 前4个字节解析成整数输出
    strcpy(var.str, "hello");   //新数据写入会覆盖原数据（字符串还包括最后'\0'）
    for (int i = 0; i <= 15; i++)
        printf("%02X ", (unsigned char)var.str[i]);
    printf("\n");
    system("pause"); // 
    return 0;
}
