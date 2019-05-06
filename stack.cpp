#include <iostream>
#include <cstdlib>
#define MAXSIZE 100
#define OK 1
#define ERROR -1
typedef int SElemType;
typedef int Status ;
using namespace std;
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
Status InitStack(SqStack &S);
//DestroyStack(SqStack &S);
int ClearStack(SqStack &S);
//StackEmpty(SqStack S);
int StackLength(SqStack S);
SElemType GetTop(SqStack S);
Status Push(SqStack&S,SElemType e);
Status Pop(SqStack&S,SElemType &e);
//StackTraverse(SqStackS);
Status InitStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if(!S.base)exit(ERROR);
    S.top = S.base;
    S.stacksize= MAXSIZE;
    return OK;
}
Status Push(SqStack &S,SElemType e)
{
    if(S.top-S.base == S.stacksize)return ERROR;
    *S.top++=e;
    return OK;
}
Status Pop(SqStack &S,SElemType &e)
{
    if(S.top == S.base)return ERROR;
    e = *--S.top;
    return OK;
}
SElemType GetTop(SqStack S)
{
    if(S.top!=S.base)
    {
        return *(S.top-1);
    }
}
int StackLength(SqStack S)
{
    return (S.top - S.base);
}
int ClearStack(SqStack &S)
{
    S.top = S.base +1;
    return true;
}
int main()
{
    cout << "1710121108-闫相佩\n";
    SqStack s;
    InitStack(s);
    cout << "对线性栈进行初始化\n";
    int n = 0;
    cout << "请输入一个数字\n";
    cin >> n;
    if(Push(s,n)) cout << "入栈成功\n";
    else cout << "入栈失败\n";
    cout << "其栈顶元素为： "<<GetTop(s) << endl;
    if(Pop(s,n)) cout << "出栈成功\n";
    else cout << "出栈失败\n";
    return 0;
}
