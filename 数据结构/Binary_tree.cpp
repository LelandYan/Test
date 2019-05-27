#include<iostream>
#include<stack>
#include<queue>
#define TElemType char
using namespace std;
typedef struct BiTNode
{
    TElemType data;///结点数据域
    struct BiTNode *lchild,*rchild;///左右孩子指针
} BiTNode,*BiTree;
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if(ch=='#')T=NULL;
    else
    {
        ///生成根结点
        T = new BiTNode;
        ///根结点数据域设置为ch
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);

    }
}
void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
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
        if(q->rchild!=NULL)myq.push(q->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{
    if(T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->lchild);
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
            p=q->rchild;
        }
    }
}
int Depth(BiTree T)
{
    if(T==NULL)return 0;
    else
    {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m>n)return m+1;
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
    cout << "二叉树前序创建\n";
    cout << "请输入序列:";
    BiTree tree = new BiTNode;
    CreateBiTree(tree);
    cout << "前序遍历结果：";
    PreOrderTraverse(tree);
    cout << endl;
    cout << "中序遍历结果：";
    InOrderTraverse(tree);
    cout << endl;
    cout << "后序遍历结果：";
    PostOrderTraverse(tree);
    cout << endl;
    cout << "层序遍历结果：";
    LevelOrderTraverse(tree);
    cout << endl;
    cout << "二叉树的深度为：";
    cout <<Depth(tree);
    return 0;
}
