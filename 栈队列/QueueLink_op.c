
/*************************************************

Copyright:

Author:Lewao

Date:2020-03-25

Description:链队列
including : subfuction introduction; noted;
**************************************************/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
typedef int Elemtype;

typedef struct QNode
{
    Elemtype data;
    struct QNode *next;
}pQNode,*LinkQueue;

typedef struct
{
    LinkQueue rear;
    LinkQueue front;
}MyQueueLink;

/**
    目的：初始化链队列
    异常：内存未分配成功
    操作：创建一个头结点，next指向NULL，rearfront =
    疑问：
**/
void InitLinkQueue(MyQueueLink *Q)
{
    Q->rear = Q->front = (LinkQueue)malloc(sizeof(pQNode));
    if(Q->rear == NULL)
        printf("分配失败");
    else
    {
        Q->front->next = NULL;
        printf("********* init successfully!!! **********\n");
    }

}

/**
    目的：入队列
    异常：内存未分配成功
    操作：创建新结点，并赋值data和next，将rear修改。
    疑问：
**/
void EnterLinkQueue(MyQueueLink *Q)
{
    Elemtype e;
    LinkQueue pchange;

    printf("please input you wanna enter\n");
    scanf("%d",&e);
    pchange = (LinkQueue)malloc(sizeof(pQNode));

    if(pchange == NULL)
        printf("分配失败");
    else
    {
        pchange->data = e;
        pchange->next = Q->front->next;
        Q->rear->next = pchange;
        Q->rear = pchange;
        printf("enter ok\m");
        printf("the entering element is%d\n",e);
    }
}

/**
    目的：出队列
    异常：不存在队列
    操作：从头出，故新建一个指针指向头结点的next，然后令头结点next = new next，free新
    疑问：
    注  ：若只有一个结点，需考虑rear的处理
**/
void ExitLinkQueue(MyQueueLink *Q)
{
    LinkQueue pchange;
    Elemtype e;

    if(Q->front == Q->rear)
        printf("empty\n");
    else
    {
        pchange = Q->front->next;

        Q->front->next = pchange->next;
        e = pchange->data;

        if(Q->rear == pchange)
            Q->rear = Q->front;
        free(pchange);
        pchange = NULL;

        printf("exit ok\m");
        printf("the entering element is%d\n",e);
    }

}
int main()
{
    MyQueueLink L;

    InitLinkQueue(&L);
    EnterLinkQueue(&L);
    EnterLinkQueue(&L);
    EnterLinkQueue(&L);

    ExitLinkQueue(&L);
    ExitLinkQueue(&L);
    ExitLinkQueue(&L);

}
