#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=100005;
int vis[maxn];
int step[maxn];
queue<int> q,qq;
int n,k;
int bfs(int a,int b)
{
    q.push(a);
    int head,next;
    vis[a]=1;step[a]=0;
    while(!q.empty())
    {
        head=q.front();q.pop();
        for(int i=0;i<3;i++)
        {
            if(i==0)next=head+1;
            if(i==1)next=head-1;
            if(i==2)next=head*2;
            if(next<0||next>=maxn)continue;
            if(!vis[next])
            {
                q.push(next);
                step[next]=step[head]+1;
                vis[next]=1;
            }
            if(next==b)return next;
        }
    }
}
int main()
{
    while(cin>>n>>k)
    {
        memset(vis,0,sizeof vis);
        memset(step,0,sizeof step);
        q=qq;
        if(n>=k)cout<<n-k<<"\n";
        else cout<<step[bfs(n,k)]<<"\n";
    }
    return 0;
}
