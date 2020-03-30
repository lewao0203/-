/*************************************************

Copyright:

Author:Lewao

Date:2020-03-24

Description: 进制转换（输入二进制，输出为十进制）

reference：https://blog.csdn.net/Wmll1234567/article/details/82463573（scanf用法）


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
        printf("分配失败\n");
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
            printf("分配失败");
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
    Elemtype e;   // 此处不能定义e为指针，若定义指针，需给指针分配一个栈的内存
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
    二进制转化八进制，利用了每三个二进制对应一个八进制，故每取三个二进制，计算出来后放入新栈，
    需注意的是，下面有一个if(i),该判断语句只有在二进制数非3的整数倍时运行。
    注意将int转化为char时，需加48
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
            PushStack(&NewStack,sum+48);  // int 转char
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

       // 参考https://blog.csdn.net/qq_42552533/article/details/86554794
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
                case 15: sum+=55;break;//大于十转换成字母字符
                default :sum+=48;      //小于十转换成数字字符

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
            case 15: sum+=55;break;//大于十转换成字母字符
            default :sum+=48;      //小于十转换成数字字符

        }
        PushStack(&NewStack,sum);
    }


    // 输出
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
            printf("输入出错\n");
            return 0;
        }

    }
    getchar();    // 将回车从缓冲区去掉

    B2D(S);
    B2O(S);
    B2H(S);


}

/** 注  **/
/**
1,getchar的用法
2,B2D中e的定义，不能定义为指针，若定义为指针，还需malloc一个栈的内存，便于指针有指向的内存。
3,B2O\B2H中新定义了一个栈，需初始化后才能使用,因为之后对该栈进行了push和pop操作。
4,elementy 定义时时char类型，故在转8和16进制时，也应该以char出栈入栈，而不能改为int类型。
5,sum入栈时，因为‘0’对应的ASCII为48，故我们将入栈的数加48即可
6,十六进制则不同，1-9转化字符时，加48即可，而A\B\C则需另外处理。
**/

