
/*************************************************

Copyright:

Author:Lewao

Date:2020-03-26

Description:�沨��������������12+2*5 ����ʱӦ��Ϊ 12 2 5 * +
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define OK 1
#define ERROR 0
#define STACKMAXSIZE 20
#define BUFFERSIZE 10

typedef double Elemtype;
typedef struct MyStackList
{
    Elemtype *base;
    Elemtype *top;
    int stacksize;
}pStack;

/**
    Ŀ�ģ�˳��洢�ṹ��ջ��ʼ��
    �쳣������ʧ��
    ���������ɴ洢�ռ䣬��base top��ֵ���Ҷ����洢��ֵ
    ���ʣ�
**/
void InitStack(pStack *S)
{
    S->base = (pStack *)malloc(STACKMAXSIZE*sizeof(Elemtype));
    if(S->base == NULL)
        printf("����ʧ��\n");
    else
    {
        S->top = S->base;
        S->stacksize = STACKMAXSIZE;
        printf("********** init OK **********\n");
    }

}

/**
    Ŀ�ģ�˳��洢�ṹ��ջ��ջ
    �쳣������ڴ�
    ������top ��ֵ����ʹtop++
    ���ʣ�
**/
void PushStack(pStack *S,Elemtype e)
{
    Elemtype *pchange;
    if(S->top - S->base >= S->stacksize)
    {
        pchange = (pStack *)realloc(S->base,(STACKMAXSIZE+1)*sizeof(Elemtype));
        if(!pchange)
            printf("����ʧ��\n");
        else
        {
            S->base = pchange;
            *(S->top) = e;
            S->top++;

            S->stacksize ++;
            printf("********** push OK **********\n");
        }
    }
    else
    {
        *(S->top) = e;
        S->top ++;
        printf("********** push OK **********\n");

    }
}

/**
    Ŀ�ģ�˳��洢�ṹ��ջ��ջ
    �쳣����ջ
    ������top--����Ԫ�ش�����
    ���ʣ�
**/
void PopStack(pStack *S,Elemtype *e)
{
    Elemtype *pchange;
    if(S->base == S->top)
        printf("empty stack\n");
    else
    {
        pchange = S->top;
        S->top --;
        *e = *(S->top);
        printf("********** pop OK **********\n");
    }
}

/**
    Ŀ�ģ�˳��洢�ṹ��ջ��ʾ
    �쳣��
    ��������base��ʼ������ʾ
    ���ʣ�
**/
void DisplayStack(pStack S)
{
    Elemtype *pchange;

    pchange = S.base;
    printf("********** Display begin **********\n");
    printf("the element of stack is\n");

    while(pchange != S.top)
    {
        printf("%f\n",*pchange);
        pchange ++;
    }
    printf("********** display ok **********\n");
}

/**
    Ŀ�ģ�ʵ���沨��������
    �쳣��
    ������ ������˵����������Ϊ���¼����֣�һ�ǽ��ַ�ת��Ϊdouble����push������ʶ���������pop���μ�������push
           ���ȿ������룬������һ���ַ����ο�����ת��������Ϊscanf c ��Ȼ���Զ����롣
           ��ô����һ������������ж�ĳ�ֽ��ǲ��������������������������pop���Σ�Ȼ���������ջ
           �ɲ���switch  defaultΪ����
           ��defalt�������ɵ����ַ���תdouble�����ǵ������ո�˵�����ֽ���������while��һ�����ַ�ת��Ϊdouble

    ���ʣ�
    ע�� ��Ϊ�õ����ַ����ĺ�������buff�����һ��\0
          �˳�ѭ��������
**/
int main()
{
    pStack L;
    Elemtype e;
    char ch;
    char buff[BUFFERSIZE];
    Elemtype d1,d2;
    int i;

    ch = '1';
    InitStack(&L);

    printf("�������沨�����ʽ,��q�����������������֮��ո����֣������и��ţ����Ϊ0-x����-1дΪ 0 - 1��");

    while(ch != 'q')
    {
        scanf("%c",&ch);
        switch(ch)
        {
            case '+':
            {
                PopStack(&L,&d2);
                PopStack(&L,&d1);
                PushStack(&L,d1+d2);
                break;
            }
            case '-':
            {
                PopStack(&L,&d2);
                PopStack(&L,&d1);
                PushStack(&L,d1-d2);
                break;
            }
            case '*':
            {
                PopStack(&L,&d2);
                PopStack(&L,&d1);
                PushStack(&L,d1*d2);
                break;
            }
            case '/':
            {
                PopStack(&L,&d2);
                PopStack(&L,&d1);
                if(d2 == 0)
                    printf("��������Ϊ0\n");
                else
                {
                    PushStack(&L,d1/d2);
                    break;
                }

            }
            case ' ': break;
            case 'q': break;
            default:
            {
                i = 0;
                while(ch !=' ')
                {
                    buff[i] = ch;
                    i++;
                    scanf("%c",&ch);
                    if(i >= BUFFERSIZE)
                        printf("����ռ���ڴ����\n");
                }
                buff[i+1] = '\0';   // ת��Ϊ�ַ���
                PushStack(&L,atof(buff));
                DisplayStack(L);
            }
        }

    }
    printf("the result is\n");
    DisplayStack(L);

}
