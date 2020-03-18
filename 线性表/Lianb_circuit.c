/*************************************************

Copyright:

Author:Lewao

Date:2020-03-17

Description:����ͷ�巨�����޻�������ʹ��β�巨�����л�������
            ���ж��Ƿ�Ϊ�л����������ǣ��������ڽڵ�
**************************************************/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int Elemtype;

typedef struct Node
{
    int data;
    struct Node *next;
}pNode,*LinkList;

void InitLink(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(pNode));
    (*L)->next = NULL;
    printf("********** initializer successfully!!! **********\n");
}

BuildLinkHead(LinkList *L,int n)
{
    LinkList pchange,phead;

    phead = *L;
    for(int i=0;i<n;i++)
    {
        pchange = (LinkList)malloc(sizeof(pNode));
        pchange->next = phead->next;
        phead->next = pchange;
        pchange->data = i;
    }
    printf("********** creat head link successfully!!!\n");


}
BuildLinkTail(LinkList *L,int n)
{
    LinkList pchange,phead;

    phead = (*L);
    for(int i=0;i<n;i++)
    {
        pchange = (LinkList)malloc(sizeof(pNode));
        phead->next = pchange;
        pchange->next = NULL;
        pchange->data = i;
        phead = pchange;
    }
    pchange->next = (*L)->next->next->next;
    printf("%d",pchange->data);
    printf("********** creat tail link successfully!!!**********\n");

}
/*************************************************

Ŀ�ģ��ж��Ƿ��л����ҷ����غϵ�
�쳣��
��������������ָ�룬ѭ������������ָ��һ�»�fastָ��ΪNULLʱ��ֹͣѭ����ע����ָ��һ�£�������flagΪ1.���л�..
���ʣ�
ע������fast��Ҫÿ��ָ�����������豣֤�ڵ���Ϊż�����ʲ��ܼ���while�ж��Ƿ�ΪNULL����ÿ�α���ǰ�����жϽ�����������ָ���Ƿ�Ϊ��


**************************************************/
Status JudgeCircuite(LinkList L,LinkList*psame)
{
    LinkList pfast,pslow,pjugde;
    int flag;

    flag = 0;
    pfast = L;
    pslow = L;
    printf("********** whether has circuite? **********\n");
    while(pfast->next != NULL && pfast->next->next != NULL  )
    {
        pfast = pfast->next->next;
        pslow = pslow->next;

        if (pfast == pslow)
        {
            *psame = pfast;
            flag = 1;
            printf("this Linklist has circuite\n");
            return flag;
        }

    }

    printf("this Linklist has not circuite\n");
    return flag;

}
/*************************************************

Ŀ�ģ�����л���������
�쳣��
��������������ָ�룬�ֱ�ӱ�ͷ���غ�λ�ÿ�ʼ�ƶ�����ָ����ͬʱ����Ϊ��ڡ�
���ʣ�
ע��


**************************************************/
void GetEnter(LinkList L,LinkList Lsame,LinkList Lenter)
{
    LinkList phead,psame;
    int i;

    i = 1;
    phead = L;
    psame = Lsame;

    while(phead != psame)
    {
        phead = phead->next;
        psame = psame->next;
        i++;
    }
    Lenter = psame;
    printf("the enter node is the %dth and the data is %d\n",i,Lenter->data);
}

int main()
{
    LinkList Lhead,Ltail,Lsame,Lenter;
    int n,flagh,flagt;

    printf("please input the length of Linklist\n");
    scanf("%d",&n);

    InitLink(&Lhead);
    InitLink(&Ltail);

    BuildLinkHead(&Lhead,n);
    BuildLinkTail(&Ltail,n);

    printf("********** head **********");
    printf("the first and second element are %d and %d\n",(Lhead)->next->data,(Lhead)->next->next->data);
    printf("********** tail **********");
    printf("the first and second element are %d and %d\n",(Ltail)->next->data,(Ltail)->next->next->data);

    flagh = JudgeCircuite(Lhead,&Lsame);
    if(flagh)
        GetEnter(Lhead,Lsame,Lenter);

    flagt = JudgeCircuite(Ltail,&Lsame);
    if(flagt)
        GetEnter(Ltail,Lsame,Lenter);

    return 0;
}
