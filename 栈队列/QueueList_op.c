
/*************************************************

Copyright:

Author:Lewao

Date:2020-03-25

Description:����˳��ѭ���洢
including : subfuction introduction; noted;
**************************************************/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 4

/**
    Ŀ�ģ�ѭ������ṹ��
    �쳣��
    ����������һ������/ָ�룬������Ϊ����ַ��Ȼ����һ��ͷ��β��Ϊ�˴ﵽѭ����Ŀ�ģ�ͷβ����ָ�룩
    ���ʣ�
**/
typedef int Elemtype;
typedef struct QueueList
{
    Elemtype *base;
    int rear,front;
}pQueueList;

/**
    Ŀ�ģ���ʼ��ѭ������
    �쳣���ڴ�δ����ɹ�
    ����������һ���ڴ�ռ䣬�������ַָ���䡣����Ϊ�գ���rearfront = 0��
    ���ʣ�
**/
void InitQueue(pQueueList *Q)
{
    Q->base = (pQueueList *)malloc(MAXSIZE*(sizeof(Elemtype)));
    if(!Q->base)
        printf("����ʧ��\n");
    else
    {
        Q->front = Q->rear = 0;
        printf("********** init successfully!!! **********\n");
    }

}

/**
    Ŀ�ģ�ѭ�����е�����в���
    �쳣����rear+1 = front����˵�������������޷�����
    ������������ǴӶ�β�룬����base[rear+1 %maxsize]��Ԫ�أ���rear++
    ���ʣ�
    ע  ��1��ENTER :Ԫ�ظ�ֵʱ������*����ΪQ->base�����൱�����飬ֱ�Ӹ�ֵ����
        2�� ENTER:rearʵ������βԪ�غ�һλ��������ջ��˳��洢
        3,scanf��Ҫ��\n
        4,���ֻ�ܴ洢Max-1��Ԫ��
**/
void EnterQueue(pQueueList *Q)
{
    Elemtype e;

    printf("please input the element you wanna input\n");
    scanf("%d",&e);

    if((Q->rear+1)%MAXSIZE == Q->front)
        printf("��������\n");
    else
    {
        Q->base[Q->rear] = e;
        Q->rear = (Q->rear+1)%MAXSIZE;
        printf("********** ENTER OK **********\n");
        printf("the element of entering is%d\n",e);
    }


}

/**
    Ŀ�ģ�ѭ�����еĳ����в���
    �쳣����front = rear����˵�������ѿգ��޷�����
    �������������ǴӶ�ͷ��������front++
    ���ʣ�
    ע
**/
void ExitQueue(pQueueList *Q)
{
    Elemtype e;

    if(Q->front == Q->rear)
        printf("�����ѿ�\n");
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
