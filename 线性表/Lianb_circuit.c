/*************************************************

Copyright:

Author:Lewao

Date:2020-03-17

Description:利用头插法创建无环单链表，使用尾插法创建有环单链表，
            且判断是否为有环单链表，若是，则求出入口节点
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

目的：判断是否有环。且返回重合点
异常：
操作：定义两个指针，循环遍历，当两指针一致或fast指针为NULL时，停止循环。注若两指针一致，则设置flag为1.即有环..
疑问：
注：由于fast需要每次指向两个，故需保证节点数为偶数，故不能简单用while判断是否为NULL。在每次遍历前，需判断接下来的两个指针是否为空


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

目的：求得有环链表的入口
异常：
操作：定义两个指针，分别从表头和重合位置开始移动，两指针相同时，即为入口。
疑问：
注：


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
