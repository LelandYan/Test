#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
void mergearray(int a[],int first,int mid,int last,int temp[])
{
    int i = first,j=mid+1;
    int m = mid,n=last,k=0;
    while(i<m&&j<n)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<m)
        temp[k++] = a[i++];
    while(j<m)
        temp[k++] = a[j++];
    for(int i =0; i<k;i++)
    {
        a[i] = temp[i];
    }
}
void mergesort(int a[],int first,int last,int temp[])
{
    if(first < last)
    {
int mid = (first+last)/2;
    mergesort(a,first,mid,temp);
    mergesort(a,mid+1,last,temp);
    mergearray(a,first,mid,last,temp);
    }

}

void MergeSort(int a[],int n)
{
    int *p = new int[n];//创建一个临时数组，这里也可以不使用动态数组
    mergesort(a,0,n-1,p);
    delete []p;
}
int main()
{
    int a[5] = {5,6,4,2,8};
    MergeSort(a,5);
    for(int i=0;i<5;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
