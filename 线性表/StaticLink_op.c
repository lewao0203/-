#define OK 1
#define Error 0
#define MAXSIZE 1000

typedef int Status;
typedef int ElemType

typedef struct
{
    ElemType data;
    int cur;
}StaticLink[MAXSIZE];

/*************************************************

目的：获得静态链表长度
异常：
操作：循环遍历，直到游标为0
疑问：

**************************************************/
int ListLength(StaticLink space)
{
    int i,j;
    j = 0;
    i =space[MAXSIZE-1].cur;
    while(i)
    {
        i = space[i].cur;
        j++;
    }
    return j;

}

/*************************************************

目的：初始化静态链表
异常：
操作：循环遍历，不断使cur指向下一元素。注最后一cur指向0
疑问：

**************************************************/
Status InitStaticLink(StaticLink space)
{
    int i;
    for(i=0;i<MAXSIZE-1;i++)
        space[i].cur = i+1;
    space[MAXSIZE].cur = 0;

    return OK;
}

 /*************************************************

目的：静态链表的插入操作
异常：
操作：三步走，一是找到备用链表首位置，二是将新元素放到备用链表，并指向原第i个元素；三是找到i
       i-1元素，并令其指针指向新的第i个元素
疑问：

**************************************************/
// 需实现两个功能，一是返回备用链表cur；二是形成新的备用链表
int GetspareLink(StaticLink space)
{
    int i = space[0].cur;
    if(i)
    {
        space[0].cur = space[i].cur;
    }

    return i;
}
Status InsertElem(StaticLink space,int i,ElemType e)
{
    int lspare,j,lfront;

    lspare = GetspareLink;
    lfront = MAXSIZE-1;

    if(i<1 || i>ListLength(space))
        return Error;
    if(j)
    {
        for(int t=1;t<i;t++)
        {
            lfront = space[lfront].cur;   //最后一次lfront实际上是第i-1个元素的下标
        }
        space[t].cur = lspare;
        space[lspare].cur = space[lfront].cur;  // i-1元素下标的cur赋值给新的i元素
        space[lspare].data = e;
        return OK;
    }
    return Error;

}
/*************************************************

目的：静态链表的删除操作
异常：超出范围    备用链表为0
操作：两种情况，一是删除第一个元素，则需将该元素的游标指向备用链表。第0个游标指向1，最后一个游标指向2
                 删除不是第一个元素，则先找到第i-1个元素，并将i元素的游标赋值给i-1元素的游标；原i元素游标
                 指向备用链表，第0个游标指向i元素。
疑问：删除后数据置为0？

**************************************************/
Status DeleteElem(StaticLink space,int i,ElemType *e)
{
    int lspare,lfirst,ldelete;

    lspare = GetspareLink;
    lfirst = space[MAXSIZE-1].cur;

    if(i<1 || i>ListLength(space))
        return Error;
    if(lspare)
    {
        if(i == 1)
        {
            space[i].cur = lspare;
            space[i].data = 0;
            space[0].cur = i;
            space[MAXSIZE-1].cur = lnext;
        }
        else
        {
            for(int j=1;j<i-1;j++)
            {
                lfirst = space[lfirst].cur;
            }
            ldelete = space[lfirst].cur;             // 获得第i个元素的下标
            space[lfirst].cur = space[ldelete].cur;  // 将第i+1个元素的下标赋给第i-1元素
            space[ldelete].cur = lspare;             // 指向备用链表
            space[ldelete].data = 0;
            space[0].cur = ldelete;
            return OK;
        }
    }
    return Error;



}
