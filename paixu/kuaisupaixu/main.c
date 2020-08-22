/*
	日期：2020年8月22日
	快速排序
	题目：输入n个数，按从小到大的顺序排列
    如：输入了 6 1 2 7 9 3 4 5 10 8
	首先，选择基准数，就以第一个数为例
	tmp = a[left];
	然后从两边开始遍历，要先从右边开始
	左边为 i，右边为 j
	只要i!=j,开始循环
	j从右往左，遍历，直到找到第一个小于tmp的值时停止
	i从左往右，遍历，直到找到第一个大于tmp的值时停止
	然后a[i] 和 a[j] 交换
	第一轮循环完之后把a[i]的值和a[left]的值交换，然后递归开始小循环，现在左边都是小于tmp的，右边都是大于tmp的
	以中间为界，对半分，左右两边再开始相同的上述过程,递归
	quicksort(left,i-1);
	quicksort(i+1,right);进行小排序
	图例：
	6 1 2 7 9 3 4 5 10 8
	6 1 2 7 9 3 4 5 10 8
		  7       5
	6 1 2 5 9 3 4 7 10 8
			9   4
	6 1 2 5 4 3 9 7 10 8
	6		  3
	3 1 2 5 4 6 9 7 10 8	//基准6归位
	3 1 2 5 4 		6		9 7 10 8
	3   2           6           10 8
	2 1 3 5 4		6		9 7 8  10   
	//基准3归位              8 7 9 10//基准9归位
	2 1 |3| 5 4             8 7 | 9 10
	1 2  3  4 5             7 8   9 10
	完成！！
*/

#include <stdio.h>
#include <windows.h>
int a[101],n;//定义全局变量

void quicksort(int left,int right)
{
	int i,j,t,tmp;
	//递归结束判断
	if(left>right)
		return;
	
	tmp = a[left];
	i = left;
	j = right;
	while(i!=j)
	{
		//j往左，i往右，顺序很重要，要先从右往左找
		while(a[j]>=tmp && i<j)
			j--;
		while(a[i]<=tmp && i<j)
			i++;
		if(i<j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = tmp;	//基准数归位
	//二分法，左右边再继续用同样的方法处理
	quicksort(left,i-1);//继续处理左边的，递归
	quicksort(i+1,right);//继续处理右边的，递归
}

int main()
{
	int i,j,t;
	printf("Please input count of number:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Please input the %dth number:",i);
		scanf("%d",&a[i]);
	}
	quicksort(1,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	system("pause");
	return 0;
}
