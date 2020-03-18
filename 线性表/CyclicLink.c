/*************************************************

Copyright:

Author:Lewao

Date:2020-03-13

Description:循环链表的初始化、建立、插入及删除操作

**************************************************/
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

/*    定义链表结构图     */
typedef struct Node
{
    ElemType data;
    struct Node *next;
}pNode,*LinkList;

/*************************************************

目的：初始化循环链表
异常：
操作：创建头结点，将结点指针指向自身
疑问：

**************************************************/
InitLink(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(pNode));
    (*L)->next=*L;
}
/*************************************************

目的：创建循环链表
异常：
操作：循环遍历，不断询问不断插入元素。注若停止插入，则将最后一个元素的指针域指向头结点。
疑问：

**************************************************/
Status BuildLink(LinkList *L)
{
    int e;
    LinkList rear,pinsertelem;

    printf("please input data and enter 0 end \n");
    scanf("%d",&e);
    rear = *L;  // 初始值指向头结点


    while(e)
    {

        pinsertelem = (LinkList)malloc(sizeof(pNode));
        rear->next = pinsertelem;
        pinsertelem->data = e;
        rear = pinsertelem;

        printf("please input data and enter 0 end \n");
        scanf("%d",&e);
    }
    rear->next = *L;
    return OK;

}

/*************************************************

目的：显示n个循环链表
异常：
操作：循环遍历，
疑问：

**************************************************/
Status DisplayLink(LinkList L)
{
    LinkList pdisplay;
    pdisplay = L;

    while(pdisplay->next != L)
    {
        pdisplay = pdisplay->next;
        printf("%d\t",pdisplay->data);
    }


    return OK;

}

/*************************************************

目的：在循环链表中插入元素
异常：插入位置小于1，或->next = L->next
操作：
疑问：
**************************************************/


Status InsertElem(LinkList *L)
{
    int i,j,e;
    LinkList pchange,pinsert;

    j = 1;
    pchange = (*L)->next;
    pinsert = (LinkList)malloc(sizeof(pNode));
    printf("please input location you wanna insert");
    scanf("%d",&i);
    printf("please input element you wanna insert");
    scanf("%d",&e);

    if(i<1)
        return ERROR;
    while(j<i-1)
    {
        if(pchange->next == *L)
        {
            printf("insert failed");
            return ERROR;
        }
        pchange = pchange->next;
        j++;
    }

    pinsert->next = pchange->next;
    pinsert->data = e;
    pchange->next = pinsert;
    printf("insert successful!!!\n");


}

/*************************************************

目的：在循环链表中删除元素
异常：删除位置小于1，或
第i-1元素为L
操作：
疑问：
**************************************************/
Status DeleteElem(LinkList *L)
{
    LinkList pchange,pdelete;
    int i,j,e;

    pchange = (*L)->next;
    j = 1;
    printf("please input location you wanna delete");
    scanf("%d",&i);

    if(i<1)
        return ERROR;
    while(j<i-1)
    {
        pchange = pchange->next;
        j++;
        if(pchange->next == *L)  //与插入不同
        {
            printf("delete failed!!!");
            return ERROR;
        }
    }
    pchange->next = pchange->next->next;
    e = pchange->next->data;
    printf("you've delete the location %d,the elem %d\n",i,e);
    return OK;

}

int main()
{
    LinkList L;

    InitLink(&L);
    BuildLink(&L);
    DisplayLink(L);
    InsertElem(&L);
    DisplayLink(L);
    DeleteElem(&L);
    DisplayLink(L);

    return 0;
}


