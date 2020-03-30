/*************************************************

Copyright:

Author:Lewao

Date:2020-03-24

Description: ����ת������������ƣ����Ϊʮ���ƣ�

reference��https://blog.csdn.net/Wmll1234567/article/details/82463573��scanf�÷���


**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef char Elemtype;

typedef struct MyStack
{
    Elemtype *base;
    Elemtype *top;
    int StackSize;
}pStack;

void InitStack(pStack *S)
{
    S->base = (pStack *)malloc(MAXSIZE*sizeof(Elemtype));
    if(!S->base)
        printf("����ʧ��\n");
    else
    {
        S->top = S->base;
        S->StackSize = MAXSIZE;
        printf("******** init successfully!!! **********\n");
    }
}

void PushStack(pStack *S,Elemtype e)
{
    Elemtype *pnew;
    Elemtype *pchange;
    pchange = S->top;

    if(S->top - S->base >= S->StackSize)
    {
        pnew =(pStack *)realloc(S->base,(1+S->StackSize)*sizeof(Elemtype));
        S->base = pnew;

        if(!pnew)
            printf("����ʧ��");
        else
        {
            *pchange = e;
            S->top ++;
            pchange = S->top;
            S->StackSize ++;
        }
    }
    else
    {
        *pchange = e;
        S->top ++;
        pchange = S->top;
    }
    printf("********** push successfully!!! **********\n");
    printf("the element you push is%c\n",e);
}

void PopStack(pStack *S,Elemtype *e)
{
    if(S->base == S->top)
        printf("no element can pop\n");
    else
    {
        (*e) = *(S->top-1);
        S->top -- ;
        printf("******** pop successfully!!!**********\n");
        printf("the element you pop is%c\n",*e);
    }
}

void B2D(pStack L)
{
    Elemtype e;   // �˴����ܶ���eΪָ�룬������ָ�룬���ָ�����һ��ջ���ڴ�
    int sum,i;

    i = 0;
    sum = 0;

    while(L.top != L.base)
    {
        PopStack(&L,&e);
        sum = sum + (e-48) * pow(2,i);
        i++;

    }
    printf("The Decent is %d\n",sum);
}

/**
    ������ת���˽��ƣ�������ÿ���������ƶ�Ӧһ���˽��ƣ���ÿȡ���������ƣ���������������ջ��
    ��ע����ǣ�������һ��if(i),���ж����ֻ���ڶ���������3��������ʱ���С�
    ע�⽫intת��Ϊcharʱ�����48
**/
void B2O(pStack L)
{
    pStack NewStack;
    InitStack(&NewStack);

    Elemtype e,e1;
    int i,sum;

    i = 0;
    sum =0;

    while(L.top != L.base)
    {
        PopStack(&L,&e);
        sum = sum + (e-48)*pow(2,i);
        i++;
        if(i == 3)
        {
            printf("sum is %d\n",sum);
            PushStack(&NewStack,sum+48);  // int תchar
            sum = 0;
            i = 0;
        }
    }
    if(i)
        PushStack(&NewStack,sum+48);

    printf("the octal is\n");
    while(NewStack.top != NewStack.base)
    {
        PopStack(&NewStack,&e1);
    }
}

void B2H(pStack L)
{
    pStack NewStack;
    Elemtype e,e1;
    int sum,i;

    sum = 0;
    i = 0;
    InitStack(&NewStack);

    while(L.base != L.top)
    {
        PopStack(&L,&e);
        sum = sum + (e-48)*pow(2,i);

       // �ο�https://blog.csdn.net/qq_42552533/article/details/86554794
        i++;

        if(i == 4)
        {
            switch(sum)
            {
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15: sum+=55;break;//����ʮת������ĸ�ַ�
                default :sum+=48;      //С��ʮת���������ַ�

            }
            PushStack(&NewStack,sum);
            i = 0;
            sum = 0;
        }
    }
    if(i)
    {
        switch(sum)
        {
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15: sum+=55;break;//����ʮת������ĸ�ַ�
            default :sum+=48;      //С��ʮת���������ַ�

        }
        PushStack(&NewStack,sum);
    }


    // ���
    printf("the H is\n");
    while(NewStack.base != NewStack.top)
    {
        PopStack(&NewStack,&e1);
    }
}
int main()
{
    pStack S;
    char ch;
    ch = '1';
    InitStack(&S);

    printf("please input binary,enter q ending\n");
    scanf("%c",&ch);

    while(ch != 'q')
    {
        if(ch  == '0' || ch == '1')
        {
            PushStack(&S,ch);
            scanf("%c",&ch);
        }
        else
        {
            printf("�������\n");
            return 0;
        }

    }
    getchar();    // ���س��ӻ�����ȥ��

    B2D(S);
    B2O(S);
    B2H(S);


}

/** ע  **/
/**
1,getchar���÷�
2,B2D��e�Ķ��壬���ܶ���Ϊָ�룬������Ϊָ�룬����mallocһ��ջ���ڴ棬����ָ����ָ����ڴ档
3,B2O\B2H���¶�����һ��ջ�����ʼ�������ʹ��,��Ϊ֮��Ը�ջ������push��pop������
4,elementy ����ʱʱchar���ͣ�����ת8��16����ʱ��ҲӦ����char��ջ��ջ�������ܸ�Ϊint���͡�
5,sum��ջʱ����Ϊ��0����Ӧ��ASCIIΪ48�������ǽ���ջ������48����
6,ʮ��������ͬ��1-9ת���ַ�ʱ����48���ɣ���A\B\C�������⴦��
**/

