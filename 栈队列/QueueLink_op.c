
/*************************************************

Copyright:

Author:Lewao

Date:2020-03-25

Description:������
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
    Ŀ�ģ���ʼ��������
    �쳣���ڴ�δ����ɹ�
    ����������һ��ͷ��㣬nextָ��NULL��rearfront =
    ���ʣ�
**/
void InitLinkQueue(MyQueueLink *Q)
{
    Q->rear = Q->front = (LinkQueue)malloc(sizeof(pQNode));
    if(Q->rear == NULL)
        printf("����ʧ��");
    else
    {
        Q->front->next = NULL;
        printf("********* init successfully!!! **********\n");
    }

}

/**
    Ŀ�ģ������
    �쳣���ڴ�δ����ɹ�
    �����������½�㣬����ֵdata��next����rear�޸ġ�
    ���ʣ�
**/
void EnterLinkQueue(MyQueueLink *Q)
{
    Elemtype e;
    LinkQueue pchange;

    printf("please input you wanna enter\n");
    scanf("%d",&e);
    pchange = (LinkQueue)malloc(sizeof(pQNode));

    if(pchange == NULL)
        printf("����ʧ��");
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
    Ŀ�ģ�������
    �쳣�������ڶ���
    ��������ͷ�������½�һ��ָ��ָ��ͷ����next��Ȼ����ͷ���next = new next��free��
    ���ʣ�
    ע  ����ֻ��һ����㣬�迼��rear�Ĵ���
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
