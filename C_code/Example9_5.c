//【例9-5】 编程实现文件复制（使用字符串读写函数实现）
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *in, *out;               // 定义两个FILE类型的指针变量
    char infile[50], outfile[50]; // 分别存放源文件和目标文件名
    char s[256];
    printf("请输入源文件名:");
    scanf("%s", infile); // 输入源文件所在路径及名称
    printf("请输入目标文件名:");
    scanf("%s", outfile);                  // 输入目标文件所在路径及名称
    if ((in = fopen(infile, "r")) == NULL) // 以只读方式打开指定文件
    {
        printf("打开文件%s失败\n", infile);
        exit(0); // 退出程序
    }
    if ((out = fopen(outfile, "w")) == NULL) // 以只写方式打开指定文件
    {
        printf("不能建立%s文件\n", outfile);
        exit(0); // 退出程序
    }
    while (fgets(s, 256, in)) // 将in指向的文件的内容复制到out所指向的文件中
        fputs(s, out);
    printf("文件复制完成\n");
    // 关闭文件
    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}
