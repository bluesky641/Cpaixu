/*
    日期：2020年8月20日
    冒泡排序
    基本思想：：每次比较两个相邻的元素，如果它们的顺序错误就把它们交换过来
    如从大到小排序：需要把最小的排到最右边
    第一趟把最小的排到最右边，需要交换 N-1-0 次
    第二趟需要交换 N-1-1 次，所以双重循环就写成 N-1-i 次
    然后依次...
    共需进行 N-1 趟
*/
#include <stdio.h>
#include <windows.h>
// 输入要排序数字的数量

//定义结构体
typedef struct student{
    char name[20];
    int score;
}STU;


#define numbers 5
int main()
{
    STU a[numbers],t;
    // int a[numbers];
    int N = numbers;
    int i,j;
    // 初始化
    for(i=0;i<N;i++)
    {
        a[i].score = 0;
    }
    // 赋值
    for(i=0;i<N;i++)
    {
        printf("Please input name and score for the %d:",i+1);
        scanf("%s %d",a[i].name,&a[i].score);
    }
    //循环的趟数，N个数排序，只需进行N-1趟
    for(i=0;i<N-1;i++)
    {
        // 循环一趟，交换
        for(j=0;j<N-1-i;j++)
        {
            if(a[j].score<a[j+1].score)
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    // 打印
    for(i=0;i<N;i++)
    {
        printf("%s %d\n",a[i].name,a[i].score);
    }
    system("pause");
    return 0;
}

