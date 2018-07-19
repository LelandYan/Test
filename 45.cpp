#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char maps[22][22];
int visit[22][22],visited[22][22];
int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int tx,ty,sx,sy,ct,m,n;;
struct node
{
    int x,y,step;
}s;
queue<node> q,qq;
void bfs()
{
    int X,Y,step,nx,ny;
    while(!q.empty())
    {
        s = q.front();q.pop();
        X=s.x;Y=s.y;step=s.step;
        if(maps[X][Y]=='T'){ct=step;return;}
        for(int i=0;i<4;i++)
        {
            nx=X+next[i][0];ny=Y+next[i][1];
            if(nx<m&&ny<n&&nx>=0&&ny>=0&&maps[nx][ny]!='*'&&!visit[nx][ny])
            {
                if(maps[nx][ny]=='|')
                {
                    nx+=next[i][0];ny+=next[i][1];
                    if(nx>=m||ny>=n||nx<0||ny<0||maps[nx][ny]=='*'||visit[nx][ny])continue;
                    if(i%2==0&&step%2==0||i%2&&step%2){visit[nx][ny]=1;s.x=nx;s.y=ny;s.step=step+1;q.push(s);}
                    else if(!visited[nx][ny])visited[nx][ny]=1,s.x=nx,s.y=ny,s.step=step+1;q.push(s);
                }
                else if(maps[nx][ny]=='-')
                {
                    nx+=next[i][0];ny+=next[i][1];
                    if(nx>=m||ny>=n||nx<0||ny<0||maps[nx][ny]=='*'||visit[nx][ny])continue;
                    if(i%2==0&&step%2==0||i%2&&step%2){visit[nx][ny]=1;s.x=nx;s.y=ny;s.step=step+1;q.push(s);}
                    else if(!visited[nx][ny])visited[nx][ny]=1,s.x=nx,s.y=ny,s.step=step+1;q.push(s);
                }
                else
                {
                    visit[nx][ny]=1;s.x=nx;s.y=ny;s.step=step+1;q.push(s);
                }
            }
        }
    }
}
int main()
{
    while(cin>>m>>n)
    {
        q = qq;
        memset(visit,0,sizeof visit);
        memset(visited,0,sizeof visited);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                cin>>maps[i][j];
                if(maps[i][j]=='S'){sx=i;sy=j;}
                if(maps[i][j]=='T'){tx=i;ty=j;}
            }
        s.x=sx;s.y=sy;s.step=0;
        q.push(s);visit[sx][sy]=1;
        bfs();
        cout<<ct<<"\n";
    }
    return 0;
}
