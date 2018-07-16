#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 100005;
string id[maxn],sn[maxn],sg[maxn];
bool c1(string a,string b)
{
    return a < b;
}
int main()
{
    int n,c;
    int cnt = 1;
    while(cin>>n>>c)
    {
        if(n==0&&c==0)
        {
            break;
        }
        int i;
        map<string,string>map1;
        map<string,string>map2;
        for(i = 0; i < n; i++)
        {
            cin >> id[i] >> sn[i] >> sg[i];
            map1[id[i]] = sn[i];
            map2[id[i]] = sg[i];
        }
        if(c==1)
        {
            sort(id,id+n,c1);
        }
        else if(c==2)
        {
            bool flag = true;
            for(int i = 0; i < n-1; i++)
            {
                if(sn[i] != sn[i+1])
                    flag = false;
                break;
            }
            if(!flag)
                sort(sn,sn+n,c1);
            else
                sort(id,id+n,c1);
        }
        else if(c==3)
        {
            bool flag = true;
            for(int i = 0; i < n-1; i++)
            {
                if(sg[i] != sg[i+1])
                    flag = false;
            }
            if(!flag)
                sort(sg,sg+n,c1);
            else
                sort(id,id+n,c1);
        }
        cout << "Case "<<cnt <<":\n";
        map<string,string>::iterator iter;
        map<string,string>::iterator iter2;
        for(int i = 0; i < n; i++)
        {
            iter=map1.begin();
            iter2=map2.begin();
            for(; iter!=map1.end(); iter++)
            {
                if(iter->first==id[i])
                    cout << iter->first << " " << iter->second << " " << iter2->second<<"\n";
                iter2++;
            }
        }
        cnt++;
    }
    return 0;
}



/*void mergearry(int a,first,mid,last,int temp)
{
    int i=first,m=mid;//�������Ŀ�ͷ���β����
    int j=mid+1,n=last;//�ұ�����Ŀ�ͷ���β����
    int k=0;//��ʱ���������
    while(i <=m && j <= n)
    {
        if(a[i] < b[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i <= m)
        temp[k++] = a[i++];
    while(j <= n)
        temp[k++] = a[j++];
    for(i = 0; i < k; i++)
        a[first + i] = temp[i];///
}
void mergesort(int a[],first,last,int temp)
{
    int mid = (first + last)/2;
    mergesort(int a[],first,mid,temp);//��֤��������������
    mergesort(int a[],mid+1,last,temp);//��֤�����ұ��������
    mergearry(int a[],first,mid,last,temp);//��������кϲ�
}
//����arr����ʱҪ��������飬n��ʾ�����������ĳ���
void MergeSort(int arr[],int n)
{
    int *p = new int[n];//����һ����ʱ����
    mergesort(arr,0,n-1,p);
    delete [] p;
}*/
