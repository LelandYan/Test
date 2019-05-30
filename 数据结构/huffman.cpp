#include<bits/stdc++.h>
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

void print()
{
    cout<<"*********************************************************************"<<endl;
    cout<<"***********1.输入HuffmanTree的参数并完成初始化.          ********"<<endl;
    cout<<"***********2.创建HuffmanTree和编码表.                        ******"<<endl;
    cout<<"***********3.输入编码，并翻译为字符.                       *******"<<endl;
    cout<<"***********4.输入字符，并实现转码.                         *******"<<endl;
    cout<<"***********5.退出.                                        ********"<<endl;
    cout<<"******************************************************************"<<endl;
    cout<<"请输入选择:";
}
int main()
{
    int falg=0;//记录要编码的字符个数
    char a[MAX_MA];//储存输入的二进制字符
    char b[MAX_ZF];//存储译出的字符
    char zf[MAX_ZF];//储存要编码的字符
    HuffmanTree HT = NULL;//初始化树为空数
    HuffmanCode HC = NULL;//初始化编码表为空表
    print();
    while (true)
    {
        int num;
        cout << "请选择功能(1-创建并初始化 2-创建编码并显示编码表 3-译码 4-转码 5-退出): ";
        cin >> num;
        switch (num)
        {
        case 1 :
            cout << "请输入字符个数:";
            cin >> falg;
            cout << "请依次输入" << falg << "个字符: ";
            for (int i = 1; i <= falg; i++)
                cin >> zf[i];
            cout << "请依次输入" << falg << "个字符的权值><>: ";
            CreateHuffmanTree(HT, falg);//调用创建哈夫曼树的函数
            cout << endl;
            break;
        case 2:
            CreateHuffmanCode(HT, HC, falg);//调用创建哈夫曼编码表的函数
            cout << endl;
            cout << "生成哈夫曼编码表成功！,下面是该编码表的输出：" << endl;
            cout << endl;
            cout << "结点i"<<"\t"<<"字符" << "\t" << "权值" << "\t" << "编码" << endl;
            for (int i = 1; i <= falg; i++)
            {
                cout << i << "\t"<<zf[i]<< "\t" << HT[i].weight << "\t" << HC[i] << endl;
            }
            cout << endl;
            break;
        case 3:
        {
            cout << endl;
            cout << "请输入想要转码的字符串：";
            string str;
            cin >>str;
            for(int i = 0; i < str.size(); i++)
            {
                for(int j = 1; j <=falg; j++)
                {
                    if(zf[j] == str[i])
                    {
                        cout<<HC[j];
                        break;
                    }
                }
            }
            cout << endl;
            break;
        }
        case 4:
            cout << "请输入想要翻译的一串二进制编码：";
            cin >> a;
            TranCode(HT, a, zf, b, falg);
            cout << endl;
            cout << "译码成功！翻译结果为:" << b << endl;
            cout << endl;
            break;
        case 5:
            cout << endl;
            cout << "<><退出成功！><>" << endl;
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
