/*************************************************

Copyright:

Author:Lewao

Date:2020-03-23

Description: ջ����ز���(��ʼ������ջ����ջ�����㡢����)

**************************************************/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;

typedef struct MyStack
{
    Elemtype *base;
    Elemtype *top;
    int StackSize;
}pStack;

void InitStack(pStack *S)
{
    int i;
    printf("please input the maxsize of the Stack");
    scanf("%d",&i);

    S->base = (pStack*)malloc(i*sizeof(Elemtype));
    if(S->base == NULL)
        printf("����ʧ��");
    else
    {
        S->top = S->base;
        S->StackSize = i;
        printf("********** init successfully!!! **********\n");
    }

}

void PushStack(pStack *S)
{
    Elemtype e,*pnew;

    printf("input the element you wanna input \n");
    scanf("%d",&e);

    if(S->top - S->base >= S->StackSize)
        {
            pnew = (pStack*)realloc(S->base,((S->StackSize)+1)*sizeof(Elemtype));
            if(pnew == NULL)
                printf("����ʧ��");
            else
            {
                S->base = pnew;
                *(S->top) = e;
                S->top ++;
                (S->StackSize)++;
                printf("********** push successfully!!! **********\n");
                printf("the element of pushing is %d\n",e);
            }

        }
    else
    {
        *(S->top) = e;
        S->top++;
        printf("********** push successfully!!! **********\n");
        printf("the element of pushing is %d\n",e);
    }
}
/** ע�����ڳ�ʼ��ʱ��̬�������ڴ棬��popʱ����free��ֻ���޸�ָ�뼴�� **/
void PopStack(pStack *S)
{
    int e;
    if(S->top == S->base)
        printf("�޿ɵ���Ԫ��");
    else
    {
        e = *(S->top-1);
        S->top --;
        printf("the element of pop is %d\n",e);
    }
}
void DisplayStack(pStack S)
{
    Elemtype *pchange;

    pchange = S.base;     // ����ָ�룬�ʲ���->

    while(pchange != S.top)
    {
        printf("%d\t",*pchange);
        pchange++;
    }
    printf("\n");
    printf("********** display successfully!!! **********\n");
}

/*** ��õ�ǰԪ������ʱ����һ�ַ�����ͨ����������ȡ��
���ڶ��ַ�����ֱ�Ӽ�ָ�루c���Զ��еģ�ֱ�Ӽ�ָ��õ���ΪԪ�ظ�����������ռ�õ��ֽ�����***/
void CalNowSize1(pStack S)
{
    int i;
    Elemtype *pchange;

    pchange = S.base;
    i = 0;

    while(pchange != S.top)
    {
        pchange++;
        i++;
    }
    printf("the present capacity is %d\n",i);
}
void CalNowSize2(pStack S)
{
    printf("the present capacity is %d\n",(S.top - S.base));  // c����ָ��ֻ�ܼ������ܼ�
    return (S.top - S.base);
}
/** ���ջʱ��ֻ����ջ��ָ�����ջ��ָ�뼴�� */
void EmptyStack(pStack *S)
{
    S->top = S->base;
    printf("********** empry successfully!!!**********\n");
}

/** ����ʱ��ֱ������base���ɣ���Ϊ��Ϊ�ڵ���malloc��ʱ��
ϵͳ���ס���������������ռ����ʼ��ַ�Լ����ռ�Ĵ�С��
�ͷ�free��ʱ��ֻҪ�������ʼ��ַ����ϵͳ��ϵͳ��Ȼ��֪��Ҫ�ͷŶ��Ŀռ䡣 */

void DestroyStack(pStack *S)
{
    Elemtype *pchange;
    int i;

    i = 1;
    pchange = S->base;
    free(S->base);

    S->base = S->top = NULL;
    S->StackSize = 0;
    printf("********** destroy successfully!!!**********\n");

}
int main()
{
    pStack L;
    int i;

    i = 1;

    InitStack(&L);

    while(i)
    {
        printf("please choose your operation(0 - quit;1 - push; 2 - pop;3 - empty; 4 - destroy)\n");
        scanf("%d",&i);
        switch(i)
        {
            case 0:
            {
                printf("quit");
                break;
            }

            case 1:
            {
                PushStack(&L);
                DisplayStack(L);
                CalNowSize1(L);
                CalNowSize2(L);
                break;
            }
            case 2:
            {
                PopStack(&L);
                DisplayStack(L);
                CalNowSize1(L);
                CalNowSize2(L);
                break;
            }
            case 3:
            {
                EmptyStack(&L);
                DisplayStack(L);
                CalNowSize1(L);
                CalNowSize2(L);
                break;
            }
            case 4:
            {
                DestroyStack(&L);
                break;
            }
            case 5:
            {
                InitStack(&L);
                break;
            }

        }
    }
    return 0;
}


/**   Ӧע���   **/
/**
1,switch ���÷�
2,pushʱ���ж��Ƿ񳬳��������
3,c����ָ�����ΪԪ�ظ�������������ռ�ֽڴ�С
4,ָ�����ýṹ����->,���ṹ�����ó�Աʱ��.
5,����ʱֱ��free base���ɡ�*/





