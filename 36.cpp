#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[50];
bool flag;
int ave;
bool v[50];
int n;
void dfs(int num,int len,int st)
{
    if(flag)return;
    if(len>ave)return;
    if(num==3)
    {
        flag=1;
        return;
    }
    if(ave==len)dfs(num+1,0,0);
    else for(int i=st;i<=n;i++)
        if(!v[i])
    {
        v[i]=1;
        dfs(num,len+a[i],i+1);
        v[i]=0;
        if(flag)return;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int s=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],s+=a[i];
        if(s%4!=0)cout<<"no\n";
        else
        {
            ave=s/4;
            flag=0;
            memset(v,0,sizeof v);
            dfs(0,0,0);
            cout<<(flag?"yes\n":"no\n");
        }
    }
}
