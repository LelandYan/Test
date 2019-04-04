#include <iostream>
#include <cstdlib>
#define MAXSIZE 100
#define OK 1
#define ERROR -1
typedef int QElemType;
typedef int Status ;
using namespace std;
typedef struct
{
    QElemType *base;
    int font;
    int rear;
}SqQueue;
Status InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXSIZE];
    if(!Q.base)exit(ERROR);
    Q.font = Q.rear = 0;
    return OK;
}
Status QueueLength(SqQueue Q)
{
    return (Q.rear-Q.font+MAXSIZE)%MAXSIZE;
}
Status EnQueue(SqQueue &Q,QElemType e)
{
    if((Q.rear+1)%MAXSIZE==Q.font)return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXSIZE;
    return OK;
}
Status DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.font == Q.rear)return ERROR;
    e= Q.base[Q.font];
    Q.font = (Q.font+1)%MAXSIZE;
    return OK;
}
QElemType GetHead(SqQueue Q)
{
    if(Q.font!=Q.rear)
    {
        return Q.base[Q.font];
    }
}
int main()
{
    return 0;
}
