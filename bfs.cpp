#include <iostream>
#include <queue>
using namespace std;
int n,m,s,xx[4][2]={{1,0},{0,1},{-1,0},{0,-1}},visit[22][22],vis[22][22];
///xx是方向，visit是记录访问过的点，vis记录楼梯面前是否已经等待，因为每个楼梯只有两种状态，所以我要等的话等一次就够了
int x1,y1,x2,y2;  //起点与终点的坐标
char map[22][22];  //输入
struct ssss
{
    int x,y,step;  //结构体包含坐标(x,y)和当前步数step
}ss;
queue<ssss> q,qq;  //q用来广搜，qq用来初始化q
bool god(int x,int y)  //怕麻烦，所以过界、是否访问、是不是*我就写了个函数应对这对此的调用--！
{
    if(x>=0&&y>=0&&x<n&&y<m&&visit[x][y]&&map[x][y]!='*')return 1;
    return 0;
}
void bfs()
{
    int i,j,k,l,x,y,X,Y,step;
    while(!q.empty())
    {
        ss=q.front();q.pop();  //取队首元素同时队首元素出队
        X=ss.x;Y=ss.y;step=ss.step;  //X，Y，step记录下当前的坐标和步数
        if(map[X][Y]=='T'){s=step;return;}  //如果是终点就直接记录步数然后跳出来
        for(i=k=0;i<4;i++)
        {
            x=X+xx[i][0];
            y=Y+xx[i][1];
            if(god(x,y))  //当可以走这个坐标
            {
                if(map[x][y]=='|')  //如果是纵向的楼梯
                {
                    x+=xx[i][0];y+=xx[i][1];  //查看多走一步的地方
                    if(!god(x,y))continue;  //如果不能走这个坐标就跳过
                    if(i%2==0&&step%2==0||i%2==1&&step%2==1)visit[x][y]=0,ss.x=x,ss.y=y,ss.step=step+1,q.push(ss);
                    else if(vis[x][y])vis[x][y]=0,ss.x=X,ss.y=Y,ss.step=step+1,q.push(ss);  //楼梯是每分钟变一次，但是只有两种状态，就是纵向和横向，所以根据步数可以计算当前楼梯的状态，if里面就是判断是否可以走，不然就是等待，当然要看先前是不是已经在这里等待过一次了，不然就会超时超内存的
                }else if(map[x][y]=='-')  //如果是横向的楼梯
                {
                    x+=xx[i][0];y+=xx[i][1];
                    if(!god(x,y))continue;
                    if(i%2==0&&step%2==1||i%2==1&&step%2==0)visit[x][y]=0,ss.x=x,ss.y=y,ss.step=step+1,q.push(ss);
                    else if(vis[x][y])vis[x][y]=0,ss.x=X,ss.y=Y,ss.step=step+1,q.push(ss);
                }else visit[x][y]=0,ss.x=x,ss.y=y,ss.step=step+1,q.push(ss);  //正常路就正常走
            }
        }
    }
}
int main (void)
{
    int i,j,k,l;
    while(cin>>n>>m)
    {
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            cin>>map[i][j];
            visit[i][j]=vis[i][j]=1;  //初始化
            if(map[i][j]=='S')x1=i,y1=j;  //记录起点
            if(map[i][j]=='T')x2=i,y2=j;  //终点
        }
        q=qq;ss.x=x1;ss.y=y1;ss.step=0;
        q.push(ss);visit[x1][y1]=0;s=0;
        bfs();
        cout<<s<<endl;
    }
    return 0;
}
