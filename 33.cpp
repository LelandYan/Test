#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 102;
char po[maxn][maxn];
int id[maxn][maxn],m,n;;
void dfs(int a,int b,int c)
{
    if(a>=m||b>=n||a<0||b<0)return;
    if(po[a][b]!='@'||id[a][b]>0)return;
    id[a][b]=c;
    for(int i=-1;i<2;i++)
        for(int j=-1;j<2;j++)
            if(i!=0||j!=0)dfs(i+a,j+b,c);
}
int main()
{
    while(cin>>m>>n)
    {
        if(m==0&&n==0)break;
        for(int i=0;i<m;i++)cin>>po[i];
        memset(id,0,sizeof(id));
        int cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(po[i][j]=='@'&&id[i][j]==0)dfs(i,j,++cnt);
        cout << cnt <<"\n";
    }
    return 0;
}
