/*************************************************

Copyright:

Author:Lewao

Date:2020-03-23

Description: 栈链(动态分配空间，无需担心内存不够用)

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

/** 初始化时，令top指向NULL时**/
void InitLinkStack(pStack *L)
{
    L->top = NULL;
    L->count = 0;
    printf("********** init successfully !!! **********\n");
}

/** push时需注意分配内存失败的情形 **/
void PushLinkStack(pStack *L)
{
    Elemtype e;
    LinkStack pchange;

    printf("please input the element  you wanna input\n");
    scanf("%d",&e);
    pchange = (LinkStack)malloc(sizeof(pNode));

    if(!pchange)
        printf("分配失败\n");
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
/** pop时需注意栈为空时，无法pop,判断条件top == NUll **/
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
        // S->top --; 不能减减，因为链表不是连续存储的
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


/** 注  **/
/**
1,链表型栈无需担心内存够不够，因为其动态分配内存
2，S->top --; 不能减减，因为链表不是连续存储的
3,栈的top时结点形式，需注意定义的变量是栈还是节点指针
4,case 后加冒号
5,dispaly时，S不是指针，故意.进行结构体成员的操作
6,栈链的清空和销毁的区别在于是否把top free(好像没区别);

**/
