/*************************************************

Copyright:

Author:Lewao

Date:2020-03-13

Description:实现约瑟夫环，1：41个人中，每隔三个自杀一个，求自杀顺序

**************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef struct Node
{
    int data;
    struct Node *next;
}pNode,*LinkList;
/*************************************************

目的：求得自杀顺序
异常：
操作：定义循环链表，建立41个结点的链表，然后依次每三个删除一个，求删除顺序
疑问：
注：要删除头结点，故需将头结点赋值给其他指针，并将L指向首元结点，且free赋值的指针

**************************************************/

Status InitLink(LinkList *L)
{
    (*L)=(LinkList)malloc(sizeof(pNode));
    (*L)->next =(*L);
    printf("init successful!!!\n");
    return 1;
}
Status BuildLink(LinkList *L,int n)   // 注，
{
    int i;
    LinkList pchange,rear,phead;

    i = 1;
    rear = *L;
    phead = *L;

    while(i<=n)
    {
        pchange = (LinkList)malloc(sizeof(pNode));
        rear->next = pchange;
        pchange->data = i;
        rear = pchange;
        i++;

    }
    rear->next = (*L)->next;  // 删除头结点
    (*L) = (*L)->next;
    free(phead);
    printf("build successful!!!\n");
    return 1;
}

void DeleteThirdElem(LinkList *L)
{
    LinkList pchange,pdelete;
    int e;

    pchange = *L;
    while(pchange->next != pchange)
    {
        pdelete = pchange->next->next;
        pchange->next->next = pdelete->next;
        pchange = pdelete->next;
        e = pdelete->data;
        printf("%d\t",e);
        free(pdelete);
    }
    printf("%d",pchange->data);
}
int main()
{
    int n;
    LinkList L;

    n = 41;

    InitLink(&L);
    BuildLink(&L,n);
    DeleteThirdElem(&L);

    return 0;
}
