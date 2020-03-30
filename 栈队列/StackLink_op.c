/*************************************************

Copyright:

Author:Lewao

Date:2020-03-23

Description: ջ��(��̬����ռ䣬���赣���ڴ治����)

**************************************************/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Elemtype;

typedef struct Node
{
    Elemtype data;
    struct Node *next;
}pNode,*LinkStack;

typedef struct MyStack
{
    LinkStack top;
    int count;
}pStack;

/** ��ʼ��ʱ����topָ��NULLʱ**/
void InitLinkStack(pStack *L)
{
    L->top = NULL;
    L->count = 0;
    printf("********** init successfully !!! **********\n");
}

/** pushʱ��ע������ڴ�ʧ�ܵ����� **/
void PushLinkStack(pStack *L)
{
    Elemtype e;
    LinkStack pchange;

    printf("please input the element  you wanna input\n");
    scanf("%d",&e);
    pchange = (LinkStack)malloc(sizeof(pNode));

    if(!pchange)
        printf("����ʧ��\n");
    else
    {
        pchange->next = L->top;
        pchange->data = e;
        L->top = pchange;
        L->count ++;
        printf("********** push successfully!!! **********\n");
        printf("the element you push is %d\n",e);
    }

}
/** popʱ��ע��ջΪ��ʱ���޷�pop,�ж�����top == NUll **/
void PopLinkStack(pStack *S)
{
    LinkStack pchange;
    Elemtype e;

    if(!S->top)
        printf("no element can pop\n");
    else
    {
        pchange = S->top;

        e = pchange->data;
        // S->top --; ���ܼ�������Ϊ�����������洢��
        S->top = S->top->next;
        S->count --;

        free(pchange);

        printf("********** pop successfully!!! **********\n");
        printf("the element you pop is %d\n",e);
    }
}

void DisplayLinkStack(pStack S)
{
    LinkStack L;
    L = S.top;
    printf("********** print the element **********\n");
    while(L)
    {
        printf("%d\t",L->data);
        L = L->next;
    }
    printf("\n");
}

void EmptyStack(pStack *S)
{
    while(S->top)
    {
        PopLinkStack(S);

    }
    printf("********** empty successfully!!! **********\n");
}

void DestroyLinkStack(pStack *S)
{
    while(S->top)
    {
        PopLinkStack(S);
    }

    free(S->top);
    S->top = NULL;
    printf("********** destroy successfully!!! **********\n");

}
void NowCapacity(pStack S)
{
    printf("now the capacity is %d\n",S.count);
}
int main()
{
    pStack S;
    int i;

    i = 1;

    InitLinkStack(&S);

    while(i)
    {
        printf("please choose your operation(0 - quit;1 - push; 2 - pop;3 - empty; 4 - destroy)\n");
        scanf("%d",&i);

        switch(i)
        {
            case 0:
            {
                printf("quit\n");
                break;
            }
            case 1:
            {
                PushLinkStack(&S);
                DisplayLinkStack(S);
                NowCapacity(S);
                break;
            }
            case 2:
            {
                PopLinkStack(&S);
                DisplayLinkStack(S);
                NowCapacity(S);
                break;
            }
            case 3:
            {
                EmptyStack(&S);
                DisplayLinkStack(S);
                NowCapacity(S);
                break;
            }
            case 4:
            {
                DestroyLinkStack(&S);
                DisplayLinkStack(S);
                NowCapacity(S);
                break;
            }
            case 5:
            {
                InitLinkStack(&S);
                break;
            }
        }
    }
    return 0;

}


/** ע  **/
/**
1,������ջ���赣���ڴ湻��������Ϊ�䶯̬�����ڴ�
2��S->top --; ���ܼ�������Ϊ�����������洢��
3,ջ��topʱ�����ʽ����ע�ⶨ��ı�����ջ���ǽڵ�ָ��
4,case ���ð��
5,dispalyʱ��S����ָ�룬����.���нṹ���Ա�Ĳ���
6,ջ������պ����ٵ����������Ƿ��top free(����û����);

**/
