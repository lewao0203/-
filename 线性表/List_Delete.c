// 目的：删除第i个元素，并将其返回给e
// 异常：i不在线性表范围内；
// 操作：1,i不为最后一个元素将第i个元素返回给e，且线性表i后元素从后往前依次覆盖前一元素
//       2,i为最后一个元素，则直接删除最后一个元素
//       3，将最后一个元素设为0；
//       4，线性表长度减一
// 注：线性表从1开始，数组从0开始；
// 疑问：删除之后设为0？

#define Error 0
#define OK 1
#define MaxSize 20
typedef int Status;
typedef int ElemType;

// 定义线性表结构
typedef Structure
{
    ElemType data[MaxSize];
    int length;
}SqList;

Statue ListDelete(SqList *L,int i,ElemType *e)
{
    while(i<1||i>L.length)
        return Error;
    *e = L.data[i-1];  // 放在最外面，若放在if里面，则若删除最后一个，就无法返回
    if (i<L.length)
        for(int k=i;k<L.length;k++)
            {

                L.data[k-1]=L.data[k];
            }
    L.data[L.length]=0;
    L。length--;
    return Ok;
}





