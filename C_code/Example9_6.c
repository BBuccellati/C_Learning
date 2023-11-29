//【例9-6】 用fscanf和fprintf函数实现将商品信息输入到文件、
//将文件内容及这些商品的总价输出到显示器上。
#include <stdio.h>
#include <stdlib.h>
typedef struct Rec // 定义结构体类型，使用typedef定义Rec为结构体类型名
{
    char id[10];
    char name[20];
    float price;
    int count;
} Rec;
void WriteFile(FILE *fp, int n); // 将键盘输入的商品信息写到文件
void ReadFile(FILE *fp, int n);  // 从文件读出商品信息

int main(void)
{
    char filename[20];
    int n;
    FILE *fp;
    printf("请输入目标文件:\n");
    scanf("%s", filename);
    fp = fopen(filename, "w+"); // 以文本读写方式打开文件
    if (fp == NULL)
    {
        printf("打开文件失败");
        return 0;
    }
    printf("请输入商品数量:\n");
    scanf("%d", &n); // 从键盘输入
    WriteFile(fp, n);
    ReadFile(fp, n);
    fclose(fp); // 关闭文件
    system("pause");
    return 0;
}
void WriteFile(FILE *fp, int n) // 将键盘输入的商品信息写到文件
{
    int i;
    Rec record;
    printf("***********请输入商品数据***********\n");
    for (i = 1; i <= n; i++) // 从键盘输入商品信息
    {
        printf("请输入序号:");
        scanf("%s", record.id);
        printf("请输入名称:");
        scanf("%s", record.name);
        printf("请输入价格：");
        scanf("%f", &record.price);
        printf("请输入数量：");
        scanf("%d", &record.count);
        printf("\n");
        // 写入文件
        fprintf(fp, "%s %s %5.2f %d\n", record.id, record.name, record.price, record.count);
    }
}
void ReadFile(FILE *fp, int n) // 从文件读出商品信息
{
    Rec record;
    double total = 0;
    rewind(fp); // 把文件内部的位置指针移到文件首
    while (fscanf(fp, "%s %s %f %d\n", record.id, record.name, &record.price, &record.count) != EOF)
    { // 输出数据
        printf("序号:%s 名称:%s 价格:%5.2f 数量:%d \n", record.id, record.name,
               record.price, record.count);
        total = total + record.price * record.count;
    }
    printf("合计:%5.2f\n", total);
}
