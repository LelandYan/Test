#include<bits/stdc++.h>
#define MAX_MA 1000
#define MAX_ZF 100
using namespace std;
///���������Ĵ洢��ʾ
typedef struct
{
    int weight;
    int parent,lchild,rchild;
} HTNode,*HuffmanTree;
///����������Ĵ洢��ʾ
typedef char **HuffmanCode;

///��������˫����Ϊ0��Ȩֵ��С�ĵ���±�
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
    ///����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
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
    HC = new char*[n + 1];///����洢n���ַ�����ı����ռ�
    char * cd = new char[n];///������ʱ�洢���ַ�����Ķ�̬�ռ�
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
    ///a[]������������Ʊ���
    ///b[]������¼������ַ�������±�
    ///zf[]�������������Ҷ�Ӷ�Ӧ���ַ�
    ///n���ַ��������൱��zf[]����ĳ���
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
    cout<<"***********1.����HuffmanTree�Ĳ�������ɳ�ʼ��.          ********"<<endl;
    cout<<"***********2.����HuffmanTree�ͱ����.                        ******"<<endl;
    cout<<"***********3.������룬������Ϊ�ַ�.                       *******"<<endl;
    cout<<"***********4.�����ַ�����ʵ��ת��.                         *******"<<endl;
    cout<<"***********5.�˳�.                                        ********"<<endl;
    cout<<"******************************************************************"<<endl;
    cout<<"������ѡ��:";
}
int main()
{
    int falg=0;//��¼Ҫ������ַ�����
    char a[MAX_MA];//��������Ķ������ַ�
    char b[MAX_ZF];//�洢������ַ�
    char zf[MAX_ZF];//����Ҫ������ַ�
    HuffmanTree HT = NULL;//��ʼ����Ϊ����
    HuffmanCode HC = NULL;//��ʼ�������Ϊ�ձ�
    print();
    while (true)
    {
        int num;
        cout << "��ѡ����(1-��������ʼ�� 2-�������벢��ʾ����� 3-���� 4-ת�� 5-�˳�): ";
        cin >> num;
        switch (num)
        {
        case 1 :
            cout << "�������ַ�����:";
            cin >> falg;
            cout << "����������" << falg << "���ַ�: ";
            for (int i = 1; i <= falg; i++)
                cin >> zf[i];
            cout << "����������" << falg << "���ַ���Ȩֵ><>: ";
            CreateHuffmanTree(HT, falg);//���ô������������ĺ���
            cout << endl;
            break;
        case 2:
            CreateHuffmanCode(HT, HC, falg);//���ô��������������ĺ���
            cout << endl;
            cout << "���ɹ����������ɹ���,�����Ǹñ����������" << endl;
            cout << endl;
            cout << "���i"<<"\t"<<"�ַ�" << "\t" << "Ȩֵ" << "\t" << "����" << endl;
            for (int i = 1; i <= falg; i++)
            {
                cout << i << "\t"<<zf[i]<< "\t" << HT[i].weight << "\t" << HC[i] << endl;
            }
            cout << endl;
            break;
        case 3:
        {
            cout << endl;
            cout << "��������Ҫת����ַ�����";
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
            cout << "��������Ҫ�����һ�������Ʊ��룺";
            cin >> a;
            TranCode(HT, a, zf, b, falg);
            cout << endl;
            cout << "����ɹ���������Ϊ:" << b << endl;
            cout << endl;
            break;
        case 5:
            cout << endl;
            cout << "<><�˳��ɹ���><>" << endl;
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
