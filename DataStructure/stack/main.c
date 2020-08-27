/*
    日期：2020年8月23日
    栈
    栈限定为只能在一端进行插入和删除操作
    题目：判断回文字符
    通过栈这个数据结构我们将很容易判断一个字符串是否为回文
    栈的实现很简单，只需要一个一维数组和一个指向栈顶的变量top就可以了
    top=-1,表示当前栈为空
    len为字符串的长度
    mid为字符串的最中间字符的位置
    思路：先把字符串前面一半入栈，再出栈并和另一半比较
    asdfdsa len=7,mid=3,i=0开始，i<mid，0、1、2入栈
    如果长度为奇数，next=mid+1,next从4开始a[4]=d,dsa
    asddsa len=6,mid=3
    如果长度为偶数，next=mid,a[3]=d,dsa
    然后出栈，top--，判断top是否等于-1，
    top=-1,栈为空，左右一致，都被抵消了，说明是回文字符串
    top!=-1,栈不为空，有剩余，不是回文字符串
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
int main()
{
    char a[101],s[101];
    int i,top=-1,next,len,mid;
    printf("Please input a string:");
    gets(a);
    len = strlen(a);
    mid = len/2;
    for(i=0;i<mid;i++)
    {
        top++;
        s[top] = a[i];
    }
    if(len%2==0)
        next = mid;
    else
        next = mid+1;
    for(i=next;i<len;i++)
    {
        if(s[top] == a[i])
        {
            top--;
        }
    }
    if(top == -1)
        printf("YES\n");
    else
        printf("NO\n");
    system("pause");
}
