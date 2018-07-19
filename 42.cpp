#include <iostream>
#include <queue>
using namespace std;
const int maxn=105;
char field[maxn][maxn];
int cnt,m,n;
/*struct point
{
    int x,y;
    point(int xx,yy){x=xx;y=yy;}
};
void bfs(int sx,int sy)
{
    queue<point> q;
    q.push(point(sx,sy));
    vis[sx][sy]=true;
}*/
void dfs(int x,int y)
{
    field[x][y]='*';
    for(int i=-1; i<2; i++)
        for(int j=-1; j<2; j++)
        {
            int xx=x+i;
            int yy=y+j;
            if(xx>=0&&yy>=0&&xx<m&&yy<n&&field[xx][yy]=='@')
                dfs(xx,yy);
        }
}
int main()
{
    while(cin>>m>>n)
    {
        if(m==0&&n==0)break;
        cnt=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                cin>>field[i][j];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(field[i][j]=='@')
                {
                    dfs(i,j);
                    cnt++;
                }
        cout<<cnt<<"\n";
    }
    return 0;
}
