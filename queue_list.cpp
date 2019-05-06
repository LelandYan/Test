#include <iostream>
#include <cstdlib>
#define MAXSIZE 100
#define OK 1
#define ERROR -1
typedef int QElemType;
typedef int Status ;
using namespace std;
typedef struct QNode
{
    QElemType data;
    struct QNode * next;
}QNode,*QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
Status InitQueue(LinkQueue & Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
    return OK;
}
Status EnQueue(LinkQueue &Q,QElemType e)
{
    QueuePtr p = new QNode;
    p->data= e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}
Status DeQueue(LinkQueue &Q,QElemType &e)
{
    if(Q.front == Q.rear)return ERROR;
    QueuePtr p = Q.front->next;
    e=p->data;
    Q.front->next = p->next;
    if(Q.rear == p)Q.rear = Q.front;
    delete p;
    return OK;
}
QElemType GetHead(LinkQueue Q)
{
    if(Q.front != Q.rear)return Q.front->next->data;
}
int main()
{
     cout << "1710121108-闫相佩\n";
    LinkQueue s;
    InitQueue(s);
    cout << "对链式队列进行初始化\n";
    int n = 0;
    cout << "请输入一个数字\n";
    cin >> n;
    if(EnQueue(s,n)) cout << "入队成功\n";
    cout << "请输入一个数字\n";
    cin >> n;
    if(EnQueue(s,n)) cout << "入队成功\n";
    else cout << "入栈失败\n";
    cout << "其队头元素为： "<<GetHead(s) << endl;
    if(DeQueue(s,n)) cout << "出队成功\n";
    else cout << "出队失败\n";
    return 0;
}
