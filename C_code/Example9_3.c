//【例9-3】 从键盘输入字符，并将其写入一个文本文件，直到遇到“#”结束输入，然后再从该文件读取文件内容，并在屏幕上输出
#include <stdio.h>
#include <stdlib.h>
void WriteFile(FILE *fp); // 向文件里写内容
void ReadFile(FILE *fp);  // 从文件里读内容

int main(void)
{
    FILE *fp;
    char inputfile[30];

    printf("请输入文件名: ");
    scanf("%s", inputfile); // 输入要打开的文件名
    fp = fopen(inputfile, "w+");
    if (fp == NULL)
    {
        printf("打开文件失败");
        return 0;
    }
    else
    {
        printf("%s 打开成功\n", inputfile);
        WriteFile(fp); // 调用函数把字符写入文件
        ReadFile(fp);  // 调用函数读文件内容并显示
        fclose(fp);    // 关闭文件
    }
    system("pause");
    return 0;
}
void WriteFile(FILE *fp) // 向文件里写内容
{
    char ch;

    printf("请输入文件内容，以#结束！\n");
    while ((ch = getchar()) != '#') // 从键盘读入字符，直到读入#循环结束
    {
        fputc(ch, fp); // 向fp所指文件里写字符ch
    }
    rewind(fp); // 将文件指针定位于文件开头
}

void ReadFile(FILE *fp) // 从文件里读内容
{
    char ch;
    printf("读取文件内容：\n");
    ch = fgetc(fp); // 从文件读取字符
    while (ch != EOF)
    {
        putchar(ch);    // 显示字符
        ch = fgetc(fp); // 从文件读取下一个字符
    }
    printf("\n文件读取结束");
}
