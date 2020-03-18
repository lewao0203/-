/*************************************************

Copyright:

Author:Lewao

Date:2020-03-19

Description: abcdefg,输入正数，zuo移，输入负数，you移
注：创建链表时，采样尾插法时，前驱域是头结点改变。
**************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef int Elemtype;
typedef int Status;

typedef struct DualNode
{
    Elemtype data;
    struct DualNode *prior;
    struct DualNode *next;
}pDualNode,*LinkList;

void InitLink(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(pDualNode));
    (*L)->next = *L;
    (*L)->prior = *L;
    printf("********** initialize successfully!!! **********\n");
}

void BuildLink(LinkList *L)
{
    LinkList phead,pchange,pinsert;

    phead = pinsert = *L;

    for(int i=1;i<=26;i++)
    {
        pchange = (LinkList)malloc(sizeof(pDualNode));

        pchange->next = pinsert->next;
        pinsert->next = pchange;

        phead->prior =  pchange;
        pchange->prior = pinsert;

        pchange->data = 'A'+i-1;

        pinsert = pchange;

    }
    (*L) = (*L)->next;
    pinsert->next = *L;

    (*L)->prior = pinsert;

    free(phead);

    printf("********** build successfully!!! **********\n");
    printf("the first and second element are %c and %c\n",(*L)->data,(*L)->next->data);
    printf("the last and second last element are %c and %c\n",(*L)->prior->data,(*L)->prior->prior->data);

}

void Display(LinkList L)
{
    LinkList phead,pchange;

    pchange = phead = L;

    printf("%c",pchange->data);
    pchange = pchange->next;

    while(phead != pchange)
    {
        printf("%c",pchange->data);
        pchange = pchange->next;

    }
    printf("\n");
}

void Changelocation(LinkList L,int n)
{

    if(n>=0)
    {
        for(int i=0;i<n;i++)
        {
            L = L->next;
        }
    }
    else
        for(int i=0;i<-n;i++)
        {
            L = L->prior;
        }
    Display(L);
}
int main()
{
    LinkList L;
    int n;

    n = 1;
    InitLink(&L);
    BuildLink(&L);
    Display(L);

    while(n)
    {
        printf("please input the moved location\n");
        scanf("%d",&n);

        Changelocation(L,n);
    }

    return 0;

}
