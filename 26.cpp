#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define ll long long
const int maxn = 1e6 + 5;
ll arr[maxn];
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,cnt;
    cin >> n;
    for(int i =1; i <= n;i++)
    {
        cin >> arr[i];
    }

    for(int i= 1; i <=n; i++)
    {
        while(arr[i] != i)
        {
            swap(arr[i],arr[arr[i]]);
            cnt++;
        }
    }
    if((3*n-cnt)%2==0)
        cout << "Petr\n";
    else
        cout << "Um_nik\n";
    return 0;
}
/*void mergearry(int a[],int first,int mid,int last,int temp[])
{
    int i=first,m=mid;//�������Ŀ�ͷ���β����
    int j=mid+1,n=last;//�ұ�����Ŀ�ͷ���β����
    int k=0;//��ʱ���������
    while(i <=m && j <= n)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i <= m)
        temp[k++] = a[i++];
    while(j <= n)
        temp[k++] = a[j++];
    for(i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(int a[],int first,int last,int temp[])
{
    int mid = (first + last)/2;
    mergesort(a,first,mid,temp);//��֤��������������
    mergesort(a,mid+1,last,temp);//��֤�����ұ��������
    mergearry(a,first,mid,last,temp);//��������кϲ�
}
//����arr����ʱҪ��������飬n��ʾ�����������ĳ���
void MergeSort(int arr[],int n)
{
    int *p = new int[n];//����һ����ʱ����
    mergesort(arr,0,n-1,p);
    delete [] p;
}*/
