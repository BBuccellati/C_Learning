#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str1[100] = "I love Chinese poeple";
    int k = 6, n = 0, i = 1;
    char str2[] = "china and";
    int len1 = (strlen(str1)) - k + 1;              //需要移动的片段长度
    int len2 = strlen(str2);                        //需要往后移的位数
   
    for (int i = 0; i <= len2; i++)                 //第K位后面整体移位len2次
    {
        for (int j = 0; j <= len1;j++)              // 第K位后面移位一次
        {
            int len3 = strlen(str1);//str1的长度
            str1[(len3) + 1 - j] = str1[(len3) - j];
        }
            printf("str1=%s\n", str1);
    }
    
    
    while(str2[n] !='\0')
    {
        str1[k+1] = str2[n];
        k++;
        n++;
    }
    printf("str1=%s", str1);

    return 0;
}

