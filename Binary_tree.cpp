#include<iostream>
#include<stack>
#include<queue>
#define TElemType int
using namespace std;
typedef struct BiTNode
{
    TElemType data;///结点数据域
    struct BiTNode *lchild,*rchild;///左右孩子指针
} BiTNode,*BiTree;
void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
void InOrderTraverse2(BiTree T)
{
    stack<BiTree> s;
    BiTree p = T;
    BiTree q = new BiTNode;
    while(p||!s.empty())
    {
        if(p)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            q = s.top();
            s.pop();
            cout << q->data;
            p = q->rchild;
        }
    }
}
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}
void LevelOrderTraverse(BiTree T)
{
    queue<BiTree> myq;
    BiTree p = T;
    BiTree q = new BiTNode;
    myq.push(p);
    while(!myq.empty())
    {
        q = myq.front();
        cout << q->data;
        myq.pop();
        if(q->lchild!=NULL)myq.push(q->lchild);
        if(q->lchild!=NULL)myq.push(q->lchild);

    }
}
void CreateBiTree(BiTree &T)
{
    char ch= '#';
    cin >> ch;
    if(ch=='#')T=NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void Copy(BiTree T,BiTree &NewT)
{
    if(T==NULL)
    {
        NewT = NULL;
        return;
    }else
    {
        NewT = new BiTNode;
        NewT->data = T->data;///复制根节点
        Copy(T->lchild,NewT->lchild);///递归复制左子树
        Copy(T->rchild,NewT->rchild);///递归复制右子树
    }
}
int Depth(BiTree T)
{

    if(T == NULL)return 0;
    else
    {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m > n)return m+1;
        else return n+1;
    }
}
int NodeCount(BiTree T)
{
    if(T==NULL)return 0;
    else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
int main()
{

    return 0;
}
