/*************************************************

Copyright:

Author:Lewao

Date:2020-03-18

Description:��һ������1����1���ڶ�������2.��1����������3���Դ�����

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

Ŀ�ģ�����Ƶĳ�ʼ�ڷ�λ��
�쳣��
����������һ��ѭ�������ҽ�ͷ���free��13�����Ĭ�Ͼ���Ϊ0.Ȼ��Ҫ��ѭ����ֵ����ֵ��13������
���ʣ�
ע���轫ͷ����ͷţ����ҳ�ʼĬ��0���������֪��Ϊʲô��Ϊ0

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

/* ע��i=0�ǿ���ע��  ,��Ϊ����if��仹Ҫִ�У�iӦ������λ��������1λ��Ż��1*/
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
