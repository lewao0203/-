/*************************************************

Copyright:

Author:Lewao

Date:2020-03-18

Description:latin ����ÿһ��ÿһ�о���ͬ

**************************************************/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Elemtype;
typedef int Status;

typedef struct Node
{
    Elemtype data;
    struct Node *next;
}pNode,*LinkList;

void InitLink(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(pNode));
    (*L)->next = (*L);
    printf("********** initializer successfully **********!!!\n");
}

void BuildLink(LinkList *L,int n)
{
    LinkList pchange,phead,pinsert;

    phead = *L;
    pinsert = *L;
    for(int i=1;i<=n;i++)
    {
        pchange = (LinkList)malloc(sizeof(pNode));
        pchange->next = pinsert->next;
        pchange->data = i;
        pinsert->next = pchange;
        pinsert = pchange;
    }
    pchange->next = (*L)->next;
    *L = phead->next;
    free(phead);
    printf("********** build successfully **********\n");
    printf("the first and second element is %d and %d\n",(*L)->data,(*L)->next->data);
}

/* ע��i=0�ǿ���ע��  ,��Ϊ����if��仹Ҫִ�У�iӦ������λ��������1λ��Ż��1*/

void Display(LinkList L)
{
    LinkList phead,pchange;

    phead =  L;
    pchange = L;

    printf("%d\t",pchange->data);
    pchange = pchange->next;

    while(pchange != phead)
    {
        printf("%d\t",pchange->data);
        pchange = pchange->next;

    }
}
int main()
{
    LinkList L;
    int n;

    printf("please input the length of the Latin matric\n");
    scanf("%d",&n);
    InitLink(&L);
    BuildLink(&L,n);

    Display(L);
    printf("\n");
    for(int i=1;i<n;i++)
    {
        L = L->next;
        Display(L);
        printf("\n");
    }



}
