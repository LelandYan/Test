#include <iostream>
using namespace std;


typedef int TelemType;

typedef struct BinaryTreeNode
{
    TelemType data;
    struct BinaryTreeNode *Left;
    struct BinaryTreeNode *Right;
}Node;


//������������˳������Ϊ�м�ڵ�->������->������
Node* createBinaryTree()
{
    Node *p;
    TelemType ch;
    cin>>ch;
    if(ch == 0)     //�������Ҷ�ӽڵ㣬�����������������ֱ�ֵΪ0
    {
        p = NULL;
    }
    else
    {
        p = new Node;
        p->data = ch;
        p->Left  = createBinaryTree();  //�ݹ鴴��������
        p->Right = createBinaryTree();  //�ݹ鴴��������
    }
    return p;
}

//�������
void preOrderTraverse(Node* root)
{
    if( root )
    {
        cout<<root->data<<' ';
        preOrderTraverse(root->Left);
        preOrderTraverse(root->Right);
    }
}

//�������
void inOrderTraverse(Node* root)
{
    if( root )
    {
        inOrderTraverse(root->Left);
        cout<<root->data<<' ';
        inOrderTraverse(root->Right);
    }
}

//�������
void lastOrderTraverse(Node* root)
{
    if( root )
    {
        lastOrderTraverse(root->Left);
        lastOrderTraverse(root->Right);
        cout<<root->data<<' ';
    }
}

//�������ڵ�����Ŀ
int Nodenum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return 1+Nodenum(root->Left)+Nodenum(root->Right);

    }
}

//�����������
int DepthOfTree(Node* root)
{
    if(root)
    {
        return DepthOfTree(root->Left)>DepthOfTree(root->Right)?DepthOfTree(root->Left)+1:DepthOfTree(root->Right)+1;
    }
    if( root == NULL )
    {
        return 0;
    }
}

//������Ҷ�ӽڵ���
int Leafnum(Node* root)
{
    if(!root)
    {
        return 0;
    }
    else if(  (root->Left == NULL) && (root->Right == NULL) )
    {
        return 1;
    }
    else
    {
        return  (Leafnum(root->Left) + Leafnum(root->Right)) ;
    }
}


int main()
{
    Node *root = NULL;
    root = createBinaryTree();
    cout <<("�����������ɹ�");
    cout<<endl;

    cout<<"�������ܽڵ���Ϊ��"<<Nodenum(root)<<endl;

    cout<<"���������Ϊ��"<<DepthOfTree(root)<<endl;

    cout<<"������Ҷ�ӽڵ���Ϊ��"<<Leafnum(root)<<endl;

    cout<<"ǰ��������:"<<endl;
    preOrderTraverse(root);
    cout<<endl;

    cout<<"����������:"<<endl;
    inOrderTraverse(root);
    cout<<endl;

    cout<<"����������:"<<endl;
    lastOrderTraverse(root);
    cout<<endl;

    return 0;
}
