#include <iostream>
#include <cstring>
using namespace std;
const int maxn=25;
int cycl[maxn],cnt=0,id[maxn],n;
int prime[40]= {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
void dfs(int m)
{
    if(m>n)return;
    if(m==n)
        if(prime[cycl[n]+1]==1)
        {
            for(int i=1; i<n; i++)
                cout<<cycl[i]<<" ";
            cout<<cycl[n]<<"\n";
        }
    for(int i=1; i<=n; i++)
    {
        if(id[i]==0&&prime[cycl[m]+i]==1)
        {
            cycl[m+1]=i;
            id[i]=1;
            dfs(m+1);
            id[i]=0;
        }
    }
}
int main()
{
    cnt = 0;
    while(cin>>n)
    {

        memset(id,0,sizeof id);
        memset(cycl,0,sizeof id);
        cycl[1]=1;id[1]=1;
        cnt++;
        cout <<"Case "<<cnt<<":\n";
        dfs(1);
        cout<<"\n";
    }
    return 0;
}
