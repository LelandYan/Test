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
     cout << "1710121108-������\n";
    SqQueue s;
    InitQueue(s);
    cout << "�����Զ��н��г�ʼ��\n";
    int n = 0;
    cout << "������һ������\n";
    cin >> n;
    if(EnQueue(s,n)) cout << "��ӳɹ�\n";
    cout << "������һ������\n";
    cin >> n;
    if(EnQueue(s,n)) cout << "��ӳɹ�\n";
    else cout << "��ջʧ��\n";
    cout << "���ͷԪ��Ϊ�� "<<GetHead(s) << endl;
    if(DeQueue(s,n)) cout << "���ӳɹ�\n";
    else cout << "����ʧ��\n";
    return 0;
}
