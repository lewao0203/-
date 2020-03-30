/*************************************************

Copyright:

Author:Lewao

Date:2020-03-23

Description: 栈的相关操作(初始化、入栈、出栈、清零、销毁)

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
        printf("分配失败");
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
                printf("分配失败");
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
/** 注：由于初始化时静态分配了内存，故pop时无需free，只需修改指针即可 **/
void PopStack(pStack *S)
{
    int e;
    if(S->top == S->base)
        printf("无可弹出元素");
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

    pchange = S.base;     // 不是指针，故不用->

    while(pchange != S.top)
    {
        printf("%d\t",*pchange);
        pchange++;
    }
    printf("\n");
    printf("********** display successfully!!! **********\n");
}

/*** 获得当前元素容量时，第一种方法是通过遍历来获取；
而第二种方法则直接减指针（c语言独有的，直接减指针得到的为元素个数，而不是占用的字节数）***/
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
    printf("the present capacity is %d\n",(S.top - S.base));  // c语言指针只能减，不能加
    return (S.top - S.base);
}
/** 清空栈时，只需令栈顶指针等于栈底指针即可 */
void EmptyStack(pStack *S)
{
    S->top = S->base;
    printf("********** empry successfully!!!**********\n");
}

/** 销毁时，直接销毁base即可，因为因为在调用malloc的时候，
系统会记住你申请的这块连续空间的起始地址以及这块空间的大小，
释放free的时候，只要把这个起始地址告诉系统，系统自然就知道要释放多大的空间。 */

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


/**   应注意的   **/
/**
1,switch 的用法
2,push时需判断是否超出最大容量
3,c语言指针相减为元素个数，而不是所占字节大小
4,指针引用结构体用->,而结构体引用成员时用.
5,销毁时直接free base即可。*/





