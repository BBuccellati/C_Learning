#include <stdio.h>
#include <stdlib.h>

struct node // 链表结点
{
    int data;          // 数据域
    struct node *next; // 指针域 存放下一个结点的地址
};
typedef struct node Node;

int main(void)
{
    Node *head, *p, *q;
    p = (Node *)malloc(sizeof(Node)); // 第一个结点
    p->data = 20;
    head = p; // 头指针指向第一个结点
    for (int i = 1; i <= 3; i++)
    {
        q = (Node *)malloc(sizeof(Node)); // q指向新申请的结点
        q->data = (i + 2) * 10;           // 新结点数据域赋值
        p->next = q;                      // 新结点链接到表尾
        p = q;                            // p指向尾结点
    }
    p->next = NULL; // 尾结点指针域为空

    printf("链表的头指针的值是：%#X\n", head);

    printf("链表结点的地址:");
    for (Node *p = head; p != NULL; p = p->next) // 遍历链表，输出每个结点的地址
    {
        printf("   %#X ", p);
    }
    printf("\n");
    printf("链表结点的内容:");
    for (Node *p = head; p != NULL; p = p->next)
    { // 遍历链表，输出每个结点的值（数据域和指针域）
        printf("%d %#X ", p->data, p->next);
    }
    system("pause");
    return 0;
}
