/*************************************************

Copyright:

Author:Lewao

Date:2020-03-08

Description:���Ա���������ʽ�洢ʱ����ز��������Ԫ�أ����룩

**************************************************/

#define OK 1
#define Error 0

typedef int Status ;
typedef struct Node *LinkList;
typedef int ElemType;
typedef struct Node()
{
    ElemType data; // ���������
    LinkList Next; // ���ָ����
};

/*************************************************

Ŀ�ģ�ͷ�巨��������
�쳣��
������LΪͷ��㣬ÿ�β�����ʱ���½��nextָ��ԭͷ����ext,��ͷ���nextָ���½��.
       ����n�������
���ʣ�

**************************************************/
Status CreatLinkhead(LinkList*L,int n)
{
    LinkList pnew_elem,phead;
    int i;

    phead = *L;      // ͷ���
    srand(time(0))   //��֤ÿ���������һ��

    /* ����ͷ��� */
    phead = (LinkList)malloc(sizeof(Node));
    phead->next = NULL;

    /* �����½�� */
    for(i=0;i<n;i++)
    {
        pnew_elem = (LinkList)malloc(sizeof(Node));
        pnew_elem->data = rand()%100+1;
        pnew_elem->next = phead->next;
        phead->next = pnew_elem;
    }


}
/*************************************************

Ŀ�ģ�β�巨��������
�쳣��
������LΪͷ��㣬ÿ�β�����ʱ��ǰһ����nextָ���½�㣬�½��nextָ��null��.
       ����n�������
���ʣ�

**************************************************/
Status CreatLinktail(LinkList*L,int n)
{
    int i;
    LinkList phead,pnew_elem,pfront_elem;

    phead = *L;      // ͷ���
    srand(time(0))   //��֤ÿ���������һ��

    /* ����ͷ��� */
    phead = (LinkList)malloc(sizeof(Node));
    phead->next = NULL;
    pfront_elem = phead;
    /* �����½�� */
    for(i=0;i<n;i++)
    {
        pnew_elem = (LinkList)malloc(sizeof(Node));
        pnew_elem->data = rand()%100+1;
        pnew_elem->next = NULL;

        pfront_elem->next = pnew_elem;
        pfront_elem = pnew_elem;
    }
    return OK;


}

/*************************************************

Ŀ�ģ�ɾ����������
�쳣��
��������ͷ��㿪ʼ������һ����next��ֵ��ͷ���next��free�½�㡣
���ʣ�
**************************************************/
Status DeleteLink(LinkList*L)
{
    LinkList phead,pdelete;
    phead = *L;

    while(phead->next)
    {
        pdelete = phead->next;
        phead->next = pdelete->next;
        free(pdelete);

    }
}
/*************************************************

Ŀ�ģ���ȡ�����е�i��Ԫ��
�쳣����������Χ��;ѭ��ʱ��nextΪnull
����������һ�����α�����ѭ��������ÿ�ξ�ʹͷָ��ָ��next��
���ʣ�ͷָ��next��Ϊ��Ԫ��㣿

**************************************************/
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;  // ��ǰָ��λ��
    j = 1;
    p = L->next;
    if(i<1)   // ���ڶ�ȡ��Χ
        return Error;
    while( p && j<i)
        {
            p = p->next;

            if(!p)
                 return Error;

            j++;
        }
    *e = p->data;
    return OK;

}

/*************************************************

Ŀ�ģ��������ڵ�i��Ԫ�ز���e
�쳣����������Χ��;ѭ��ʱ��nextΪnull
����������һ�����α�����ѭ��������ÿ�ξ�ʹͷָ��ָ��next���ڵ�i-1Ԫ��ʱ������nextָ��eԪ�أ���eԪ�ص�nextָ��ԭ�ȵ�i��
       ����˳��i-1next��ֵ����һָ�룬�ٸ��ǡ�
���ʣ�ͷָ��next��Ϊ��Ԫ��㣿

**************************************************/
Status InsertElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p,pinsert_elem,pyuanxian_elem;  // ��ǰָ��λ��

    j = 1;
    p = L->next;
    pinsert_elem = e;
    if(i<1)   // ���ڶ�ȡ��Χ
        return Error;
    while( p && j<i-1)
        {

            p = p->next;      // i-1 ���
            if(!p)
                 return Error;

            j++;
        }

    pyuanxian_elem = p->next; //ԭ��i��Ԫ�ص�ַ��ֵ
    p->next = pinsert_elem;
    pinsert_elem->data = *e;
    pinsert_elem->next = pyuanxian_elem;

    return OK;

}

/*************************************************

Ŀ�ģ���������ɾ����i��Ԫ��,����ɾ��Ԫ�ط��ظ�e
�쳣����������Χ��;ѭ��ʱ��nextΪnull
����������һ�����α�����ѭ��������ÿ�ξ�ʹͷָ��ָ��next���ڵ�i-1Ԫ��ʱ������һ��ָ��i��㣬����i-1next'ָ��inext
���ʣ�ͷָ��next��Ϊ��Ԫ��㣿

**************************************************/
Status DeleteElem(LinkList*L,int i,ElemType *e)
{
    int j;
    LinkList pdelete_elem,p;
    p = *L;     // ע����ʱ��ͷָ�룬������Ԫ���

    if(i<1)
        return Error;
    while(p && j<i)
    {
        p = p->next;
        if(!p)
            return Error;
        j++;
    }

    pdelete_elem = p->next;   // ��i������ַ��ֵ
    p->next = pdelete_elem->next;   // ���i-1�����ָ����ָ���i������ָ����

    *e = pdelete_elem->data;
    free(pdelete_elem);

    return OK;

}
