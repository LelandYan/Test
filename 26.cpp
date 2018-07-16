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
    int i=first,m=mid;//左边数组的开头与结尾索引
    int j=mid+1,n=last;//右边数组的开头与结尾索引
    int k=0;//临时数组的索引
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
    mergesort(a,first,mid,temp);//保证数组左边是有序的
    mergesort(a,mid+1,last,temp);//保证数组右边是有序的
    mergearry(a,first,mid,last,temp);//对数组进行合并
}
//这里arr数组时要排序的数组，n表示的是你的数组的长度
void MergeSort(int arr[],int n)
{
    int *p = new int[n];//创建一个临时数组
    mergesort(arr,0,n-1,p);
    delete [] p;
}*/
