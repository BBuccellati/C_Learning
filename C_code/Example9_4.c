//【例9-4】 编程实现将一个字符串追加到指定文件中，并将文件的内容在屏幕上输出（使用字符串读写函数实现）
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    char str[100];
    printf("请输入一个字符串：\n");
    gets(str);         // 输入要写到文件中的字符串
    char fileName[20]; // 定义存放文件名的字符数组
    printf("请输入文件所在路径及名称：\n");
    scanf("%s", fileName);                   // 输入文件所在路径及名称
    if ((fp = fopen(fileName, "a")) == NULL) // 以追加方式打开指定文件
    {
        printf("打开失败!");
        return 0;
    }
    fputs(str, fp); // 把字符数组str中的字符串写到fp指向的文件
    fclose(fp);
    if ((fp = fopen(fileName, "r")) != NULL)
    {
        printf("%s 文件内容：\n", fileName);
        while (fgets(str, sizeof(str), fp)) // 从fp所指的文件中读取字符串存入str中
            printf("%s", str);              // 将字符串输出
        fclose(fp);                         // 关闭文件
    }
    system("pause");
    return 0;
}
