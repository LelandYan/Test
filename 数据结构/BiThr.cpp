#include <iostream>
#include<cstring>
#define MAX_MA 1000
#define MAX_ZF 100
using namespace std;
///哈夫曼树的存储表示
typedef struct
{
    int weight;
    int parent,lchild,rchild;
} HTNode,*HuffmanTree;
///哈夫曼编码的存储表示
typedef char **HuffmanCode;

///返回两个双亲域为0的权值最小的点的下标
void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
    for(int i = 1; i <=n; i++)
    {
        if(HT[i].parent == 0)
        {
            s1 = i;
            break;
        }
    }
    for(int i = 1; i <=n; i++)
    {
        if((HT[i].weight < HT[s1].weight) && (HT[i].parent == 0))
            s1 = i;
    }
    for(int i = 1; i <=n ; i++)
    {
        if((HT[i].parent == 0) && (i != s1))
        {
            s2 = i;
            break;
        }
    }
    for(int i = 1; i <=n ; i++)
    {
        if((HT[i].weight < HT[s2].weight) && (HT[i].parent == 0) && (i!= s1))
            s2 = i;
    }
}
void CreateHuffmanTree(HuffmanTree &HT,int n)
{
    if(n<=1)
        return;
    int m = 2 * n - 1;
    HT = new HTNode[m+1];
    for(int i = 1; i <=m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    ///输入前n个单元中叶子结点的权值
    for(int i = 1; i <= n; i++)
        cin>>HT[i].weight;
    int s1,s2;
    for(int i = n+1; i <= m; i++)
    {
        Select(HT,i-1,s1,s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
    HC = new char*[n + 1];///分配存储n个字符编码的编码表空间
    char * cd = new char[n];///分配临时存储的字符编码的动态空间
    cd[n-1] = '\0';
    for(int i = 1; i <=n ; i++)
    {
        int start = n - 1;
        int c = i;
        int f = HT[c].parent;
        while(f !=0)
        {
            --start;
            if(HT[f].lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n-start];
        strcpy(HC[i], &cd[start]);
    }
    delete cd;
}
void TranCode(HuffmanTree HT,char a[],char zf[],char b[],int n)
{
    ///a[]用来传入二进制编码
    ///b[]用来记录译出的字符数组的下标
    ///zf[]是与哈夫曼树的叶子对应的字符
    ///n是字符个数，相当于zf[]数组的长度
    int q = 2 * n -1;
    int k = 0;
    int i = 0;
    for(i = 0; a[i]!='\0'; i++)
    {
        if(a[i] == '0')
            q = HT[q].lchild;
        else if(a[i] == '1')
            q = HT[q].rchild;
        if(HT[q].lchild == 0 && HT[q].rchild == 0)
        {
            b[k++] = zf[q];
            q = 2 * n -1;
        }
    }
    b[k] = '\0';
}
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
void print()
{
    cout<<"******************************************************************"<<endl;
    cout<<"***********1.输入HuffmanTree的参数.                       ********"<<endl;
    cout<<"***********2.初始化HuffmanTree参数.（含有26字母及空格）   ********"<<endl;
    cout<<"***********3.创建HuffmanTree和编码表.                     ********"<<endl;
    cout<<"***********4.输出编码表.                                  ********"<<endl;
    cout<<"***********5.输入编码，并翻译为字符.                      ********"<<endl;
    cout<<"***********6.输入字符，并实现转码.                        ********"<<endl;
    cout<<"***********7.退出.                                        ********"<<endl;
    cout<<"******************************************************************"<<endl;
    cout<<"请输入选择:"<<endl;
}
int main()
{
    int falg;//记录要编码的字符个数
    char a[MAX_MA];//储存输入的二进制字符
    char b[MAX_ZF];//存储译出的字符
    char zf[MAX_ZF];//储存要编码的字符
    HuffmanTree HT = NULL;//初始化树为空数
    HuffmanCode HC = NULL;//初始化编码表为空表
    menu();
    while (true)
    {
        int num;
        cout << "<><请选择功能(1-创建 2-编码 3-译码 4-退出)><>: ";
        cin >> num;
        switch (num)
        {
        case 1 :
            cout << "<><请输入字符个数><>:";
            cin >> falg;
            //动态申请falg个长度的字符数组，用来存储要编码的字符
            /*char *zf = new char[falg];*/
            cout << "<><请依次输入" << falg << "个字符:><>: ";
            for (int i = 1; i <= falg; i++)
                cin >> zf[i];
            cout << "<><请依次输入" << falg << "个字符的权值><>: ";
            CreateHuffmanTree(HT, falg);//调用创建哈夫曼树的函数
            cout << endl;
            cout << "<><创建哈夫曼成功！,下面是该哈夫曼树的参数输出><>：" << endl;
            cout << endl;
            cout << "结点i"<<"\t"<<"字符" << "\t" << "权值" << "\t" << "双亲" << "\t" << "左孩子" << "\t" << "右孩子" << endl;
            for (int i = 1; i <= falg * 2 - 1; i++)
            {
                cout << i << "\t"<<zf[i]<< "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
            }
            cout << endl;
            break;
        case 2:
            CreateHuffmanCode(HT, HC, falg);//调用创建哈夫曼编码表的函数
            cout << endl;
            cout << "<><生成哈夫曼编码表成功！,下面是该编码表的输出><>：" << endl;
            cout << endl;
            cout << "结点i"<<"\t"<<"字符" << "\t" << "权值" << "\t" << "编码" << endl;
            for (int i = 1; i <= falg; i++)
            {
                cout << i << "\t"<<zf[i]<< "\t" << HT[i].weight << "\t" << HC[i] << endl;
            }
            cout << endl;
            break;
        case 3:
            cout << "<><请输入想要翻译的一串二进制编码><>：";
            /*这样可以动态的直接输入一串二进制编码，
            因为这样输入时最后系统会自动加一个结束符*/
            cin >> a;
            TranCode(HT, a, zf, b, falg);//调用译码的函数，
            /*这样可以直接把数组b输出，因为最后有
            在数组b添加输出时遇到结束符会结束输出*/
            cout << endl;
            cout << "<><译码成功！翻译结果为><>：" << b << endl;
            cout << endl;
            break;
        case 4:
            cout << endl;
            cout << "<><退出成功！><>" << endl;
            exit(0);
        default:
            break;
        }
    }
    return 0;
}
