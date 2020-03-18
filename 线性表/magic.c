/*************************************************

Copyright:

Author:Lewao

Date:2020-03-18

Description:第一张牌是1，从1数第二张牌是2.从1数第三张是3，以此类推

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

/*************************************************

目的：求得牌的初始摆放位置
异常：
操作：创建一个循环链表，且将头结点free，13个结点默认均设为0.然后按要求循环赋值，赋值够13即结束
疑问：
注：需将头结点释放，，且初始默认0，看代码会知道为什么设为0

**************************************************/
void InitLink(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(pNode));
    (*L)->next = (*L);
    printf("********** initializer successfully **********!!!\n");
}

void BuildLink(LinkList *L)
{
    LinkList pchange,phead,pinsert;
    int n;

    n = 13;
    phead = *L;
    pinsert = *L;
    for(int i=0;i<n;i++)
    {
        pchange = (LinkList)malloc(sizeof(pNode));
        pchange->next = pinsert->next;
        pchange->data = 0;
        pinsert->next = pchange;
        pinsert = pchange;
    }
    pchange->next = (*L)->next;
    *L = phead->next;
    free(phead);
    printf("********** build successfully **********\n");
    printf("the first and second element is %d and %d\n",(*L)->data,(*L)->next->data);
}

/* 注：i=0那块需注意  ,因为下面if语句还要执行，i应该是移位的数，移1位后才会加1*/
void Magician(LinkList *L)
{
    LinkList pchange;
    int count,i;

    i = 1;
    count = 1;
    pchange = *L;

    while(1)
    {

        if(i == count)
        {
            pchange->data = count;
            count++;
            i = 0;
        }

        if(pchange->next->data == 0)
        {
            i++;
        }
        pchange = pchange->next;

        if(count > 13)
            break;
    }
    printf("********** build successfully **********\n");
    printf("the first and second element is %d and %d\n",(*L)->data,(*L)->next->data);

}
void DisplayOrigin(LinkList L)
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

    InitLink(&L);
    BuildLink(&L);
    Magician(&L);
    DisplayOrigin(L);


}
