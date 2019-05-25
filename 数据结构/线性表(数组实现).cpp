#include <iostream>
#include <string>

using namespace std;
const int MAXSIZE = 100;
# define OK 1
# define ERROR 0
typedef struct
{
    int * elem;
    int length;
} SqList;
void figure(int n);
int initList(SqList& L);
void clearList(SqList & L);
int is_Empty(SqList L);
int get_Length(SqList L);
void getNext(SqList L,int e);
void getbefore(SqList L,int e);
int getElem(SqList L,int i,int &e);
int locateElem(SqList L,int e);
int listInsert(SqList &L,int i,int e);
int listDelete(SqList & L,int i);
void display(SqList L);
int getItem(SqList L,int e);
void figure(int n,SqList & L)

{
    while (true)
    {
        cout << "1-----������Ա�\n";
        cout << "2-----�ж����Ա��Ƿ�Ϊ��\n";
        cout << "3-----��ȡ���Ա�ĳ���\n";
        cout << "4-----��ȡ���Ա��ָ��λ��Ԫ��\n";
        cout << "5-----��ǰ��\n";
        cout << "6-----�����\n";
        cout << "7-----�����Ա�ָ��λ�ò���Ԫ��\n";
        cout << "8-----ɾ�����Ա�ָ��λ��Ԫ��\n";
        cout << "9-----��ʾ���Ա�\n";
        cout << "10-----��ȡԪ�ص�λ��\n";
        cout << "      �˳�������һ��������\n";
        cout << "�������������:";
        int n;
        cin >> n;
        if( n < 0)
            return;
        switch (n)
        {
        case 1:
            clearList(L);
            break;
        case 2:
            if(is_Empty(L))
                cout << "�����Ա�Ϊ��\n";
            else
                cout << "�����Ա�Ϊ��\n";
            break;
        case 3:
            cout << "�����Ա���Ϊ��" <<get_Length(L) << endl;
            break;
        case 4:
            int r,e;
            cout << "������Ҫ��ȡ�����Ա�ָ��Ԫ�ص�λ��: ";
            cin >> r;
            if(getElem(L,r,e))
                cout << "��λ�õ�Ԫ��Ϊ��"<< e << endl;
            else
                cout << "��������ȷ��λ��ֵ\n";
            break;

        case 5:
            int k;
            cout << "������Ҫ��ȡ��ǰ����λ�� :";
            cin >> k;
            getbefore(L,k);
            break;
        case 6:
            int n;
            cout << "������Ҫ��ȡ�ĺ�����λ�� :";
            cin >> n;
            getNext(L,n);
            break;
        case 7:
            {cout << "��������ݣ�λ�ã����ݣ���";
            string str1;
            cin>>str1;
            int b = str1.find('(');
            int c = str1.find(',');
            int d = str1.find(')');
            string n1 = str1.substr(1,c-1);
            string n2 = str1.substr(c+1,d-c-1);
            int p,s;
            p = atoi(n1.c_str());
            s = atoi(n2.c_str());
            if(listInsert(L,p,s))
                cout <<"����ɹ�\n";
            else
                cout << "���벻�Ϸ�������ʧ��\n";
            break;}
        case 8:
            int z;
            cout << "������Ҫɾ��Ԫ�ص�λ��: ";
            cin >>z;
            if(listDelete(L,z))
                cout << "ɾ���ɹ�\n";
            else
                cout << "ɾ��ʧ��\n";
            break;
        case 9:
            display(L);
            break;
        case 10:
            {int e;
            cout << "������Ҫ��λ��Ԫ��:";
            cin >>e;
            int index = getItem(L,e);
            if(index)cout << "��Ԫ�ص�λ��Ϊ:"<< index << endl;
            else cout << "��Ԫ�ز�����!\n";
            break;}
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}
int getItem(SqList L,int e)
{
    for(int i = 0; i < L.length; i++)
    {
        if(L.elem[i]==e){return i+1;break;}
    }
    return ERROR;
}
void display(SqList L)
{
    cout << "���Ա�ĸ���Ԫ��Ϊ��";
    for(int i =0 ; i < L.length; i++)
    {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}
int initList(SqList & L)
{
    L.elem = new int[MAXSIZE];
    if(!L.elem)
        return ERROR;
    L.length = 0;
    return OK;
}
int getElem(SqList L,int i,int &e)
{
    if( (i < 1) || (i > L.length))
        return ERROR;
    e = L.elem[i-1];
    return OK;
}
int locateElem(SqList L,int e)
{
    //��˳����У̲���Ϊ�������Ԫ�ط��������
    for(int i = 0; i < L.length; i++)
    {
        if(L.elem[i] == e)
            return i+1;
    }
    //���鵽ʧ�ܷ���-1
    return -1;
}
int listInsert(SqList &L,int i,int e)
{
    if((i < 1) || (i > MAXSIZE+1))
        return ERROR;
    if(L.length == MAXSIZE)
        return ERROR;
    for(int j = L.length-1; j>=i-1; j--)
    {
        L.elem[j+1] = L.elem[j];
    }
    L.elem[i-1]=e;
    ++L.length;
    return OK;
}
int listDelete(SqList & L,int i)
{
    if((i < 1) || (i > L.length))
        return ERROR;
    for(int j =1; j <= L.length-1; j++)
    {
        L.elem[j-1] = L.elem[j];
    }
    --L.length;
    return OK;
}
void clearList(SqList & L)
{
    int len = get_Length(L);
    for(int i =len; i > 0; i--)
    {
        listDelete(L,i);
    }
    cout << "���Ա��Ѿ����\n";
}
int is_Empty(SqList  L)
{
    if(L.length == 0)
        return OK;
    return ERROR;
}
int get_Length(SqList  L)
{
    return L.length;
}
void getNext(SqList L,int e)
{
    int res = locateElem(L,e);
    if(res==-1||(res+1) >= MAXSIZE){
        cout << "������Ϸ���λ��\n";
        return;
    }
    int next;
    getElem(L,res+1,next);
    cout << "��λ�����Եĺ���Ԫ��Ϊ��" << next << endl;
}
void getbefore(SqList L,int e)
{
    int res = locateElem(L,e);
    if(res==-1||(res-1) <0 ){
        cout << "������Ϸ���λ��\n";
        return;
    }
    int next;
    getElem(L,res-1,next);
    cout << "��λ�����Ե�ǰ��Ԫ��Ϊ��" << next << endl;

}
int main()
{
    int input_num = 1;

    // ��ʾ����̨����ʾ��Ϣ
    SqList lists;
    if(initList(lists))
        cout << "���Ա��ʼ�����: "<<endl;
    figure(input_num,lists);
    return 0;
}
