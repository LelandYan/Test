#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int n,m,t,dx,dy,wall;
bool flag;
char field[52][10];
int vis[52][10];
void dfs(int sx,int sy,int step)
{
    int tx,ty;int go[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    if(flag)return;
    if(sx==dx&&sy==dy&&step==t){flag=true;return;}
    int tem=t-step-abs(sx-dx)-abs(sy-dy);
    if(tem<0||tem%2)return;
    for(int i=0;i<4;i++)
    {
        tx=sx+go[i][0];ty=sy+go[i][1];
        if(tx>=n||ty>=m||tx<0||ty<0)continue;
        if(field[tx][ty]!='X'&&!vis[tx][ty])
        {
            vis[tx][ty]=1;
            dfs(tx,ty,step+1);
            if(flag)return;
            vis[tx][ty]=0;
        }
    }
}
int main()
{
    int sx,sy;
    while(cin>>n>>m>>t)
    {
        wall=0;flag=false;
        if(n==0&&m==0&&t==0)break;
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++)
             cin>>field[i];
        for(int i=0;i<n; i++)
            for(int j=0;j<m;j++)
            {
                if(field[i][j]=='S'){sx=i;sy=j;}
                if(field[i][j]=='D'){dx=i;dy=j;}
                if(field[i][j]=='X'){wall++;}
            }
        if(t>n*m-wall-1){cout<<"NO\n";continue;}
        vis[sx][sy]=1;
        dfs(sx,sy,0);
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
