/*************************************************

Copyright:

Author:Lewao

Date:2020-03-13

Description:ʵ��Լɪ�򻷣�1��41�����У�ÿ��������ɱһ��������ɱ˳��

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

Ŀ�ģ������ɱ˳��
�쳣��
����������ѭ����������41����������Ȼ������ÿ����ɾ��һ������ɾ��˳��
���ʣ�
ע��Ҫɾ��ͷ��㣬���轫ͷ��㸳ֵ������ָ�룬����Lָ����Ԫ��㣬��free��ֵ��ָ��

**************************************************/

Status InitLink(LinkList *L)
{
    (*L)=(LinkList)malloc(sizeof(pNode));
    (*L)->next =(*L);
    printf("init successful!!!\n");
    return 1;
}
Status BuildLink(LinkList *L,int n)   // ע��
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
    rear->next = (*L)->next;  // ɾ��ͷ���
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
