/*************************************************

Copyright:

Author:Lewao

Date:2020-03-08

Description:线性表以链表形式存储时的相关操作（获得元素，插入）

**************************************************/

#define OK 1
#define Error 0

typedef int Status ;
typedef struct Node *LinkList;
typedef int ElemType;
typedef struct Node()
{
    ElemType data; // 结点数据域
    LinkList Next; // 结点指针域
};

/*************************************************

目的：头插法创造链表
异常：
操作：L为头结点，每次插入结点时，新结点next指向原头结点的ext,将头结点next指向新结点.
       插入n个随机数
疑问：

**************************************************/
Status CreatLinkhead(LinkList*L,int n)
{
    LinkList pnew_elem,phead;
    int i;

    phead = *L;      // 头结点
    srand(time(0))   //保证每次随机数不一样

    /* 创建头结点 */
    phead = (LinkList)malloc(sizeof(Node));
    phead->next = NULL;

    /* 插入新结点 */
    for(i=0;i<n;i++)
    {
        pnew_elem = (LinkList)malloc(sizeof(Node));
        pnew_elem->data = rand()%100+1;
        pnew_elem->next = phead->next;
        phead->next = pnew_elem;
    }


}
/*************************************************

目的：尾插法创造链表
异常：
操作：L为头结点，每次插入结点时，前一结点的next指向新结点，新结点next指向null；.
       插入n个随机数
疑问：

**************************************************/
Status CreatLinktail(LinkList*L,int n)
{
    int i;
    LinkList phead,pnew_elem,pfront_elem;

    phead = *L;      // 头结点
    srand(time(0))   //保证每次随机数不一样

    /* 创建头结点 */
    phead = (LinkList)malloc(sizeof(Node));
    phead->next = NULL;
    pfront_elem = phead;
    /* 插入新结点 */
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

目的：删除整个链表
异常：
操作：从头结点开始，将下一结点的next赋值给头结点next，free下结点。
疑问：
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

目的：读取链表中第i个元素
异常：不在链表范围内;循环时，next为null
操作：定义一个整形变量，循环遍历，每次均使头指针指向next。
疑问：头指针next即为首元结点？

**************************************************/
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;  // 当前指针位置
    j = 1;
    p = L->next;
    if(i<1)   // 不在读取范围
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

目的：链表中在第i个元素插入e
异常：不在链表范围内;循环时，next为null
操作：定义一个整形变量，循环遍历，每次均使头指针指向next。在到i-1元素时，令其next指向e元素；且e元素的next指向原先第i个
       插入顺序，i-1next赋值给另一指针，再覆盖。
疑问：头指针next即为首元结点？

**************************************************/
Status InsertElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p,pinsert_elem,pyuanxian_elem;  // 当前指针位置

    j = 1;
    p = L->next;
    pinsert_elem = e;
    if(i<1)   // 不在读取范围
        return Error;
    while( p && j<i-1)
        {

            p = p->next;      // i-1 结点
            if(!p)
                 return Error;

            j++;
        }

    pyuanxian_elem = p->next; //原第i个元素地址赋值
    p->next = pinsert_elem;
    pinsert_elem->data = *e;
    pinsert_elem->next = pyuanxian_elem;

    return OK;

}

/*************************************************

目的：链表中在删除第i个元素,并将删除元素返回给e
异常：不在链表范围内;循环时，next为null
操作：定义一个整形变量，循环遍历，每次均使头指针指向next。在到i-1元素时，定义一个指向i结点，并令i-1next'指向inext
疑问：头指针next即为首元结点？

**************************************************/
Status DeleteElem(LinkList*L,int i,ElemType *e)
{
    int j;
    LinkList pdelete_elem,p;
    p = *L;     // 注，此时是头指针，而非首元结点

    if(i<1)
        return Error;
    while(p && j<i)
    {
        p = p->next;
        if(!p)
            return Error;
        j++;
    }

    pdelete_elem = p->next;   // 第i个结点地址赋值
    p->next = pdelete_elem->next;   // 令第i-1个结点指针域指向第i个结点的指针域

    *e = pdelete_elem->data;
    free(pdelete_elem);

    return OK;

}
