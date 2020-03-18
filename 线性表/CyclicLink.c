/*************************************************

Copyright:

Author:Lewao

Date:2020-03-13

Description:ѭ������ĳ�ʼ�������������뼰ɾ������

**************************************************/
#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

/*    ��������ṹͼ     */
typedef struct Node
{
    ElemType data;
    struct Node *next;
}pNode,*LinkList;

/*************************************************

Ŀ�ģ���ʼ��ѭ������
�쳣��
����������ͷ��㣬�����ָ��ָ������
���ʣ�

**************************************************/
InitLink(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(pNode));
    (*L)->next=*L;
}
/*************************************************

Ŀ�ģ�����ѭ������
�쳣��
������ѭ������������ѯ�ʲ��ϲ���Ԫ�ء�ע��ֹͣ���룬�����һ��Ԫ�ص�ָ����ָ��ͷ��㡣
���ʣ�

**************************************************/
Status BuildLink(LinkList *L)
{
    int e;
    LinkList rear,pinsertelem;

    printf("please input data and enter 0 end \n");
    scanf("%d",&e);
    rear = *L;  // ��ʼֵָ��ͷ���


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

Ŀ�ģ���ʾn��ѭ������
�쳣��
������ѭ��������
���ʣ�

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

Ŀ�ģ���ѭ�������в���Ԫ��
�쳣������λ��С��1����->next = L->next
������
���ʣ�
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

Ŀ�ģ���ѭ��������ɾ��Ԫ��
�쳣��ɾ��λ��С��1����
��i-1Ԫ��ΪL
������
���ʣ�
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
        if(pchange->next == *L)  //����벻ͬ
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


