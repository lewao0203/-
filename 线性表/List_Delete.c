// Ŀ�ģ�ɾ����i��Ԫ�أ������䷵�ظ�e
// �쳣��i�������Ա�Χ�ڣ�
// ������1,i��Ϊ���һ��Ԫ�ؽ���i��Ԫ�ط��ظ�e�������Ա�i��Ԫ�شӺ���ǰ���θ���ǰһԪ��
//       2,iΪ���һ��Ԫ�أ���ֱ��ɾ�����һ��Ԫ��
//       3�������һ��Ԫ����Ϊ0��
//       4�����Ա��ȼ�һ
// ע�����Ա��1��ʼ�������0��ʼ��
// ���ʣ�ɾ��֮����Ϊ0��

#define Error 0
#define OK 1
#define MaxSize 20
typedef int Status;
typedef int ElemType;

// �������Ա�ṹ
typedef Structure
{
    ElemType data[MaxSize];
    int length;
}SqList;

Statue ListDelete(SqList *L,int i,ElemType *e)
{
    while(i<1||i>L.length)
        return Error;
    *e = L.data[i-1];  // ���������棬������if���棬����ɾ�����һ�������޷�����
    if (i<L.length)
        for(int k=i;k<L.length;k++)
            {

                L.data[k-1]=L.data[k];
            }
    L.data[L.length]=0;
    L��length--;
    return Ok;
}





