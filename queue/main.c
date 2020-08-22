/*
    日期：2020年8月22日
    队列
    队列的概念:
    队列是一种特殊的线性结构，它只允许在队列的首部（head）进行删除操作，这称为“出队”，而在队
    列的尾部（tail）进行插入操作，这称为“入队”。当队列中没有元素时（即 head==tail），称为空队列。在我们
    的日常生活中有很多情况都符合队列的特性。比如我们之前提到过的买票，每个排队买票的窗口就是一个队列。在这
    个队列当中，新来的人总是站在队列的最后面，来得越早的人越靠前，也就越早能买到票，就是先来的人先服务，我
    们称为“先进先出”（First In First Out，FIFO）原则。
*/
/*
    题目：加密字符串解密
    规则：首先将第 1 个数删除，紧接着将第 2 个数放到这串数的末尾，再将第 3 个数删除并将第 4 个数放到这串数的末尾，再将
    第 5 个数删除……直到剩下最后一个数，将最后一个数也删除。按照刚才删除的顺序，把这些删除的数连在一起就是解密字符串。给出加密
    过的一串数是“6 3 1 7 5 8 9 2 4”。
*/
#include <stdio.h>
#include <windows.h>

#define N 9
//结构体实现队列操作
struct queue
{
    int data[100];
    int head;
    int tail;
};

int main()
{
    struct queue q;
    int i;
    //初始化队列
    q.head = 0; //队列中有9个元素，tail指向队尾的后一个位置
    q.tail = 0;
    for(i=0;i<N;i++)
    {
        printf("Please input %dth number:",i+1);
        scanf("%d",&q.data[q.tail]);
        q.tail++;
    }
    while(q.head < q.tail)//当队列不为空的时候执行循环
    {
        //打印队首并将队首出队
        printf("%d ",q.data[q.head]);
        q.head++;
        //将第二个添加到队尾
        q.data[q.tail] = q.data[q.head];
        q.tail++;
        //再将队首出列
        q.head++;
    }
    system("pause");
    return 0;
}
