#include <iostream>

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
void figure(int n,SqList & L)

{
    while (true)
    {
        cout << "1-----清空线性表\n";
        cout << "2-----判断线性表是否为空\n";
        cout << "3-----求取线性表的长度\n";
        cout << "4-----获取线性表的指定位置元素\n";
        cout << "5-----求前驱\n";
        cout << "6-----求后驱\n";
        cout << "7-----在线性表指定位置插入元素\n";
        cout << "8-----删除线性表指定位置元素\n";
        cout << "9-----显示线性表\n";
        cout << "      退出：输入一个负数！";
        cout << "请输入操作代码:";
        int n;
        cin >> n;
        if( n < 0)return;
        switch (n)
        {
        case 1:
            clearList(L);
            break;
        case 2:
            if(is_Empty(L))cout << "该线性表为空\n";
            else cout << "该线性表不为空\n";
            break;
        case 3:
            cout << "该线性表长度为：" <<get_Length(L) << endl;
            break;
        case 4:
            int r,e;
            cout << "请输入要获取的线性表指定元素的位置: ";
            cin >> r;
            if(getElem(L,r,e))
                cout << "该位置的元素为："<< e << endl;
            else cout << "请输入正确的索引\n";
            break;

        case 5:
            int k;
            cout << "请输入要获取的前驱的索引值 :";
            cin >> k;
            getbefore(L,k);
            break;
        case 6:
            int n;
            cout << "请输入要获取的后驱的索引值 :";
            cin >> n;
            getNext(L,n);
            break;
        case 7:
            int p,s;
            cout << "请输入要插入的索引值: ";
            cin >> p;
            cout << "请输入要插入的元素的值：";
            cin >> s;
            if(listInsert(L,p,s))
                cout <<"插入成功\n";
            else
                cout << "插入失败\n";
            break;
        case 8:
            int z;
            cout << "请输入要删除元素的索引值: ";
            cin >>z;
            if(listDelete(L,z))cout << "删除成功\n";
            else cout << "删除失败\n";
            break;
        case 9:
            display(L);
            break;
        default:
            break;
        }
    system("pause");
    system("cls");
    }
}
void display(SqList L)
{
    cout << "线性表的各个元素为：";
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
    //在顺序表中Ｌ查找为ｅ的数据元素返回其序号
    for(int i = 0; i < L.length; i++)
    {
        if(L.elem[i] == e)
            return i+1;
    }
    //若查到失败返回-1
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
    for(int i =len-1; i >= 0; i--){
        listDelete(L,i);
    }
    cout << "线性表已经清空\n";
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
    if(res==-1||(res+1) >= MAXSIZE)
        cout << "请输入合法的索引\n";
        return;
    int next;
    getElem(L,res+1,next);
    cout << "该索引所对的后驱元素为：" << next << endl;
}
void getbefore(SqList L,int e)
{
    int res = locateElem(L,e);
    if(res==-1||(res-1) <0 )
        cout << "请输入合法的索引\n";
        return;
    int next;
    getElem(L,res-1,next);
    cout << "该索引所对的前驱元素为：" << next << endl;

}
int main()
{
    int input_num = 1;

    // 显示控制台的提示信息
    SqList lists;
    if(initList(lists))cout << "线性表初始化完成: "<<endl;
    figure(input_num,lists);
    return 0;
}
