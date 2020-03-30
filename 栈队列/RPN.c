
/*************************************************

Copyright:

Author:Lewao

Date:2020-03-26

Description:逆波兰计算器。例如12+2*5 输入时应该为 12 2 5 * +
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
    目的：顺序存储结构的栈初始化
    异常：分配失败
    操作：生成存储空间，对base top赋值，且对最大存储赋值
    疑问：
**/
void InitStack(pStack *S)
{
    S->base = (pStack *)malloc(STACKMAXSIZE*sizeof(Elemtype));
    if(S->base == NULL)
        printf("分配失败\n");
    else
    {
        S->top = S->base;
        S->stacksize = STACKMAXSIZE;
        printf("********** init OK **********\n");
    }

}

/**
    目的：顺序存储结构的栈入栈
    异常：最大内存
    操作：top 赋值，且使top++
    疑问：
**/
void PushStack(pStack *S,Elemtype e)
{
    Elemtype *pchange;
    if(S->top - S->base >= S->stacksize)
    {
        pchange = (pStack *)realloc(S->base,(STACKMAXSIZE+1)*sizeof(Elemtype));
        if(!pchange)
            printf("扩容失败\n");
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
    目的：顺序存储结构的栈出栈
    异常：空栈
    操作：top--并把元素传出。
    疑问：
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
    目的：顺序存储结构的栈显示
    异常：
    操作：从base开始依次显示
    疑问：
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
    目的：实现逆波兰计算器
    异常：
    操作： 整体来说，主函数分为以下几部分：一是将字符转变为double，并push，二是识别运算符，pop两次计算结果并push
           首先考虑输入，输入是一串字符，参考进制转化，设置为scanf c ，然后自动读入。
           那么首先一个问题就是需判断某字节是不是运算符，如果是运算符，则需pop两次，然后计算结果入栈
           可采用switch  default为数字
           在defalt里，还需完成的是字符串转double，考虑到遇到空格说明数字结束，可用while将一整块字符转化为double

    疑问：
    注： 因为用到了字符串的函数，故buff后需加一个\0
          退出循环的条件
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

    printf("请输入逆波兰表达式,以q结束，运算符和数字之间空格区分，且若有负号，请改为0-x（例-1写为 0 - 1）");

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
                    printf("除数不能为0\n");
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
                        printf("数字占用内存过大\n");
                }
                buff[i+1] = '\0';   // 转化为字符串
                PushStack(&L,atof(buff));
                DisplayStack(L);
            }
        }

    }
    printf("the result is\n");
    DisplayStack(L);

}
