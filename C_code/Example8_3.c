#include <stdio.h>

typedef struct student
{
    char name[21];  // 姓名
    int aveScore;   // 期末平均成绩
    int classScore; // 班级评议成绩
    char leader;    // 是否是学生干部
    char west;      // 是否是西部省份学生
    int articles;   // 发表的论文数
} Student;

int main(void)
{
    Student stu[100]; // 结构数组
    int n;            // 学生人数
    scanf("%d", &n);
    int sum = 0;                // 所发放的奖金总额
    int maxjin = 0, k = 0;      // 记录获得最多奖金数和获得最多奖金学生的序号
    for (int i = 0; i < n; i++) // 读n个学生的信息，并计算
    {
        int jiangJin = 0;
        scanf("%s %d %d %c %c %d", stu[i].name, &stu[i].aveScore,
              &stu[i].classScore, &stu[i].leader, &stu[i].west, &stu[i].articles);
        if (stu[i].aveScore > 80 && stu[i].articles >= 1)
            jiangJin += 8000;
        if (stu[i].aveScore > 85 && stu[i].classScore > 80)
            jiangJin += 4000;
        if (stu[i].aveScore > 90)
            jiangJin += 2000;
        if (stu[i].aveScore > 85 && stu[i].west == 'Y')
            jiangJin += 1000;
        if (stu[i].classScore > 80 && stu[i].leader == 'Y')
            jiangJin += 850;
        sum += jiangJin; // 累计总奖金数
        if (jiangJin > maxjin)
        {
            maxjin = jiangJin;
            k = i; // k记录当前获得最多奖金学生的序号
        }
    }
    printf("%s\n%d\n%d\n", stu[k].name, maxjin, sum); // 输出结果

    return 0;
}
