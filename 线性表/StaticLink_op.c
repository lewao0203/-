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

Ŀ�ģ���þ�̬������
�쳣��
������ѭ��������ֱ���α�Ϊ0
���ʣ�

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

Ŀ�ģ���ʼ����̬����
�쳣��
������ѭ������������ʹcurָ����һԪ�ء�ע���һcurָ��0
���ʣ�

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

Ŀ�ģ���̬����Ĳ������
�쳣��
�����������ߣ�һ���ҵ�����������λ�ã����ǽ���Ԫ�طŵ�����������ָ��ԭ��i��Ԫ�أ������ҵ�i
       i-1Ԫ�أ�������ָ��ָ���µĵ�i��Ԫ��
���ʣ�

**************************************************/
// ��ʵ���������ܣ�һ�Ƿ��ر�������cur�������γ��µı�������
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
            lfront = space[lfront].cur;   //���һ��lfrontʵ�����ǵ�i-1��Ԫ�ص��±�
        }
        space[t].cur = lspare;
        space[lspare].cur = space[lfront].cur;  // i-1Ԫ���±��cur��ֵ���µ�iԪ��
        space[lspare].data = e;
        return OK;
    }
    return Error;

}
/*************************************************

Ŀ�ģ���̬�����ɾ������
�쳣��������Χ    ��������Ϊ0
���������������һ��ɾ����һ��Ԫ�أ����轫��Ԫ�ص��α�ָ����������0���α�ָ��1�����һ���α�ָ��2
                 ɾ�����ǵ�һ��Ԫ�أ������ҵ���i-1��Ԫ�أ�����iԪ�ص��α긳ֵ��i-1Ԫ�ص��αꣻԭiԪ���α�
                 ָ����������0���α�ָ��iԪ�ء�
���ʣ�ɾ����������Ϊ0��

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
            ldelete = space[lfirst].cur;             // ��õ�i��Ԫ�ص��±�
            space[lfirst].cur = space[ldelete].cur;  // ����i+1��Ԫ�ص��±긳����i-1Ԫ��
            space[ldelete].cur = lspare;             // ָ��������
            space[ldelete].data = 0;
            space[0].cur = ldelete;
            return OK;
        }
    }
    return Error;



}
