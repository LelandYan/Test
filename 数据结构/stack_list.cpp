#include <iostream>
#include <cstdlib>
#define MAXSIZE 100
#define OK 1
#define ERROR -1
typedef int SElemType;
typedef int Status ;
using namespace std;
typedef struct StackNode
{
    SElemType data;
    struct StackNode * next;
}StackNode,*linkStack;
Status StackEmpty(linkStack S)
{
    return (S == NULL);
}
Status InitStack(linkStack &S)
{
    S = NULL;
    return OK;
}
Status Push(linkStack &S,SElemType e)
{
    linkStack p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return OK;
}
Status Pop(linkStack &S,SElemType &e)
{
    if(S == NULL)return ERROR;
    e = S->data;
    linkStack p = S;
    S = S->next;
    delete p;
    return OK;
}
SElemType GetTop(linkStack S)
{
    if(S != NULL)
        return S->data;
}
void conversion(int N)
{
    linkStack S = new StackNode;
    InitStack(S);
    while(N)
    {
        Push(S,N%8);
        N = N / 8;
    }
    while(!StackEmpty(S))
    {
        int e = 0;
        Pop(S,e);
        cout <<e;
    }
}
Status Matching()
{
    linkStack S = new StackNode;
    InitStack(S);
    int flag = 1;
    char ch;
    int x;
    cin >> ch;
    while(ch!='#'&&flag)
    {
        switch(ch)
        {
        case '[':
        case '(':
            Push(S,ch);
            break;
        case ')':
            if(!StackEmpty(S)&&GetTop(S)=='(')
                Pop(S,x);
            else flag = 0;
            break;
        case ']':
            if(!StackEmpty(S)&&GetTop(S)==']')
                Pop(S,x);
            else flag = 0;
            break;
        }
        cin >> ch;
    }
    if(StackEmpty(S)&&flag)return true;
    else return false;
}
int main()
{
    cout << "1710121108-闫相佩\n";
    linkStack s = new StackNode;
    InitStack(s);
    cout << "对链式栈进行初始化\n";
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
