
/*************************************************

Copyright:

Author:Lewao

Date:2020-03-25

Description:队列顺序循环存储
including : subfuction introduction; noted;
**************************************************/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 4

/**
    目的：循环链表结构体
    异常：
    操作：定义一个数组/指针，用来作为基地址，然后定义一个头和尾（为了达到循环的目的，头尾不用指针）
    疑问：
**/
typedef int Elemtype;
typedef struct QueueList
{
    Elemtype *base;
    int rear,front;
}pQueueList;

/**
    目的：初始化循环队列
    异常：内存未分配成功
    操作：创建一个内存空间，并令基地址指向其。由于为空，故rearfront = 0；
    疑问：
**/
void InitQueue(pQueueList *Q)
{
    Q->base = (pQueueList *)malloc(MAXSIZE*(sizeof(Elemtype)));
    if(!Q->base)
        printf("分配失败\n");
    else
    {
        Q->front = Q->rear = 0;
        printf("********** init successfully!!! **********\n");
    }

}

/**
    目的：循环队列的入队列操作
    异常：若rear+1 = front，则说明队列已满，无法操作
    操作：入队列是从队尾入，故令base[rear+1 %maxsize]加元素，且rear++
    疑问：
    注  ：1、ENTER :元素赋值时，无需*，因为Q->base【】相当于数组，直接赋值即可
        2， ENTER:rear实际上是尾元素后一位置类似于栈的顺序存储
        3,scanf后不要加\n
        4,最大只能存储Max-1个元素
**/
void EnterQueue(pQueueList *Q)
{
    Elemtype e;

    printf("please input the element you wanna input\n");
    scanf("%d",&e);

    if((Q->rear+1)%MAXSIZE == Q->front)
        printf("队列已满\n");
    else
    {
        Q->base[Q->rear] = e;
        Q->rear = (Q->rear+1)%MAXSIZE;
        printf("********** ENTER OK **********\n");
        printf("the element of entering is%d\n",e);
    }


}

/**
    目的：循环队列的出队列操作
    异常：若front = rear，则说明队列已空，无法操作
    操作：出队列是从队头出，故令front++
    疑问：
    注
**/
void ExitQueue(pQueueList *Q)
{
    Elemtype e;

    if(Q->front == Q->rear)
        printf("队列已空\n");
    else
    {
        e = Q->base[Q->front];
        Q->front = (Q->front+1)%MAXSIZE;
        printf("********** EXIT OK **********\n");
        printf("the element of exiting is%d\n",e);
    }
}
int main()
{
    pQueueList L;

    InitQueue(&L);

    EnterQueue(&L);
    EnterQueue(&L);
    EnterQueue(&L);

    ExitQueue(&L);
    ExitQueue(&L);
    ExitQueue(&L);


}
