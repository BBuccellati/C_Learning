//【例9-8】 输出第m个商品信息：将商品信息文件中所有商品信息输出后，
//再根据输入的商品记录号m，输出第m个商品信息。
#include <stdio.h>
#include <stdlib.h>

typedef struct Rec // 定义结构体类型，使用typedef定义Rec为结构体类型名
{
    char id[10];
    char name[20];
    float price;
    int count;
} Rec;

int main(void)
{
    char filename[20]; // 存放商品信息文件名
    FILE *fp;
    int m; // 存放要读取的商品记录号
    Rec record;

    printf("请输入商品信息文件:\n");
    scanf("%s", filename);
    fp = fopen(filename, "rb"); // 以文本读写方式打开文件
    if (fp == NULL)
    {
        printf("打开文件失败");
        exit(1);
    }
    while (fread(&record, sizeof(Rec), 1, fp))
    {
        printf("%s 名称:%s 价格:%5.2f 数量:%d \n", record.id, record.name,
               record.price, record.count);
    }
    printf("请输入要读取的商品记录号:\n");
    scanf("%d", &m);                     // 从键盘输入
    fseek(fp, (m - 1) * sizeof(Rec), 0); // 将文件位置指针移到第m个商品信息位置
    fread(&record, sizeof(Rec), 1, fp);
    printf("第%d条记录\n序号:%s 名称:%s 价格:%5.2f 数量:%d \n", m, record.id,
           record.name, record.price, record.count);
    fclose(fp); // 关闭文件
    system("pause");
    return 0;
}
