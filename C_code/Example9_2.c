//【例9-2】 从指定文件中读取数据，并在屏幕上输出
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char inputfile[20];
    
    printf("请输入要打开文件的名字：");
    scanf("%s", inputfile);     // 输入文件名
    fp = fopen(inputfile, "r"); // 以只读方式打开文本文件
    if (fp == NULL)             // 文件打开失败，直接退出程序
    {
        printf("\n%s打开失败!\n", inputfile);
        return 0;
    }
    printf("%s 文件内容：\n", inputfile);
    while (!feof(fp))       // 当文件未结束时
        putchar(fgetc(fp)); // 从文件中读取字符并显示
    printf("\n");
    fclose(fp); // 关闭文件
    system("pause");
    return 0;
}

