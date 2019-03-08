#include <iostream>
#include <cstring>
#include <set>
#include<algorithm>
using namespace std;
int arr[25],n,b[4];
set<pair<int,int> >s;
void dfs(int a)
{
    if(a==n)
    {
        if(b[0]<=b[1]&&b[1]<=b[2]&&b[1]+b[0]>b[2])
            s.insert(make_pair(b[0],b[1]));
        return;
    }
    for(int i=0;i<3;i++)
    {
        b[i]+=arr[a];dfs(a+1);b[i]-=arr[a];
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;s.clear();
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        dfs(0);
        cout<<s.size()<<"\n";
    }
    return 0;
}
