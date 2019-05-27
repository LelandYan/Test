#include<iostream>
#include<stack>
#include<queue>
#define TElemType int
using namespace std;
#define MAX_MA 1000
#define MAX_ZF 100

typedef struct
{
    int weight;
    int parent,lchild,rchild;
} HTNode,*HuffmanTree;
typedef char **HuffmanCode;
void menu()
{
    cout << endl;
    cout << "       ┏〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┓" << endl;
    cout << "       ┃      ★★★★★★★哈夫曼编码与译码★★★★★★★        ┃" << endl;
    cout << "       ┃                   1.  创建哈夫曼树                       ┃" << endl;
    cout << "       ┃                   2.  进行哈夫曼编码                     ┃" << endl;
    cout << "       ┃                   3.  进行哈夫曼译码                     ┃" << endl;
    cout << "       ┃                   4.  退出程序                           ┃" << endl;
    cout << "       ┗〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┛" << endl;
    cout << "                       <><注意：空格字符用'- '代替><>" << endl;
    cout << endl;
}
void CreateHuffmanTree(HuffmanTree &HT,int n)
{
    if(n <= 1)return;
    int m = 2 * n - 1;
    HT = new HTNode[m+1];
    for(int i = 1; i <=m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight;
    }
    int s1,s2;
    for(int i = n+1; i <= m; i++)
    {
        Select
    }
}
int main()
{
    int falg;///记录要编码的字符个数
    char a[MAX_MA];///储存输入的二进制字符
    char b[MAX_ZF];///储存译出的字符
    char zf[MAX_ZF];///储存要编码的字符
    HuffmanTree HT = NULL;
    HuffmanCode HC = NULL;
    menu();
    while(true)
    {
        int num;
        cout << "请选择功能(1-创建 2-编码 3-译码 4-退出)";
        cin >> num;
        switch(num)
        {
        case 1:
            cout << "请输入字符个数:";
            cin >> falg;
            cout << "请依次输入" << falg << "个字符: ";
            for(int i = 1; i <= falg; i++)
            {
                cin >> zf[i];
            }
            cout << "请依次输入" << falg << "个字符的权值";
            CreateHuffmanTree(HT,falg);
            cout << endl;
            cout << "创建哈夫曼树成功!,下面是该哈夫曼树的参数输出" << endl;
            cout << endl;
            cout << "创建哈夫曼成功，下面是该哈夫曼树参数的输出" << endl;
            cout << endl;
            cout << "结点i"<<"\t"<<"字符" << "\t" << "权值" << "\t" << "双亲" << "\t" << "左孩子" << "\t" << "右孩子" << endl;
            for (int i = 1; i <= falg * 2 - 1; i++)
            {
                cout << i << "\t"<<zf[i]<< "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
            }
            cout << endl;
            break;
        }

    }
    return 0;
}


