//字符串的简单加密
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(viod)
{
    char text[80];
    int len;
    char a;
    printf("输入要加密的字符：");
    gets(text);     //输入可能含有空格的字符串
    len = strlen(text);     //求字符串的长度
    for(int i = 0; i < len; i++)
    {
        if(text[i] >= 'a' && text[i] < 'z' || text[i] >= 'A' && text[i] < 'Z')
            text[i]++;
        else if (text[i] == 'z')
            text[i] = 'a';
        else if (text[i] == 'Z')
            text[i] = 'A';
    }
    printf("加密后的字符串为：    %s\n",text);

    system("pause");
    return 0;
}