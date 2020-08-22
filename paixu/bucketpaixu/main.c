/*
    日期；2020年8月20日
    木桶排序法
    题目：输入五个0-10之间的数，按从小到大的顺序排列
    如：输入了 5 5 8 3 6
    思路：建立一个数组，大小为 11 ，arr[11]
    |0|1|2|3|4|5|6|7|8|9|10|
    输入一个数，相应的下标加1
    如检测到输入了5，则arr[5]++;
    则最后就是：
     0 0 0 1 0 2 1 0 1 0 0
    然后依次输出 
    ==============================================
    时间复杂度O(2*(M+N)),较小常数可以忽略，m、n通常大写
    最大的问题：浪费空间
    桶排序是最快的，它的时间复杂度是O(N+M)；冒泡排序是 O(N^2)；快速排序是 O(NlogN)
*/

#include <stdio.h>
#include <windows.h>

int main()
{
    int arr[11],i,j,k;
    //初始化数组数据为0
    for(i=0;i<11;i++)
    {
        arr[i] = 0;
    }
    for(i=0;i<5;i++)
    {
        printf("Please input number between 1-10 for 5 times:\n");
        scanf("%d",&k);
        arr[k]++;
    }
    for(i=0;i<11;i++)
    {
        while(arr[i])
        {
            printf("%d ",i);
            arr[i]--;
        }
    }
    printf("\n");
    system("pause");
}
