#include <iostream>
#include <queue>
using namespace std;
int n,m,s,xx[4][2]={{1,0},{0,1},{-1,0},{0,-1}},visit[22][22],vis[22][22];
///xx�Ƿ���visit�Ǽ�¼���ʹ��ĵ㣬vis��¼¥����ǰ�Ƿ��Ѿ��ȴ�����Ϊÿ��¥��ֻ������״̬��������Ҫ�ȵĻ���һ�ξ͹���
int x1,y1,x2,y2;  //������յ������
char map[22][22];  //����
struct ssss
{
    int x,y,step;  //�ṹ���������(x,y)�͵�ǰ����step
}ss;
queue<ssss> q,qq;  //q�������ѣ�qq������ʼ��q
bool god(int x,int y)  //���鷳�����Թ��硢�Ƿ���ʡ��ǲ���*�Ҿ�д�˸�����Ӧ����Դ˵ĵ���--��
{
    if(x>=0&&y>=0&&x<n&&y<m&&visit[x][y]&&map[x][y]!='*')return 1;
    return 0;
}
void bfs()
{
    int i,j,k,l,x,y,X,Y,step;
    while(!q.empty())
    {
        ss=q.front();q.pop();  //ȡ����Ԫ��ͬʱ����Ԫ�س���
        X=ss.x;Y=ss.y;step=ss.step;  //X��Y��step��¼�µ�ǰ������Ͳ���
        if(map[X][Y]=='T'){s=step;return;}  //������յ��ֱ�Ӽ�¼����Ȼ��������
        for(i=k=0;i<4;i++)
        {
            x=X+xx[i][0];
            y=Y+xx[i][1];
            if(god(x,y))  //���������������
            {
                if(map[x][y]=='|')  //����������¥��
                {
                    x+=xx[i][0];y+=xx[i][1];  //�鿴����һ���ĵط�
                    if(!god(x,y))continue;  //���������������������
                    if(i%2==0&&step%2==0||i%2==1&&step%2==1)visit[x][y]=0,ss.x=x,ss.y=y,ss.step=step+1,q.push(ss);
                    else if(vis[x][y])vis[x][y]=0,ss.x=X,ss.y=Y,ss.step=step+1,q.push(ss);  //¥����ÿ���ӱ�һ�Σ�����ֻ������״̬����������ͺ������Ը��ݲ������Լ��㵱ǰ¥�ݵ�״̬��if��������ж��Ƿ�����ߣ���Ȼ���ǵȴ�����ȻҪ����ǰ�ǲ����Ѿ�������ȴ���һ���ˣ���Ȼ�ͻᳬʱ���ڴ��
                }else if(map[x][y]=='-')  //����Ǻ����¥��
                {
                    x+=xx[i][0];y+=xx[i][1];
                    if(!god(x,y))continue;
                    if(i%2==0&&step%2==1||i%2==1&&step%2==0)visit[x][y]=0,ss.x=x,ss.y=y,ss.step=step+1,q.push(ss);
                    else if(vis[x][y])vis[x][y]=0,ss.x=X,ss.y=Y,ss.step=step+1,q.push(ss);
                }else visit[x][y]=0,ss.x=x,ss.y=y,ss.step=step+1,q.push(ss);  //����·��������
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
            visit[i][j]=vis[i][j]=1;  //��ʼ��
            if(map[i][j]=='S')x1=i,y1=j;  //��¼���
            if(map[i][j]=='T')x2=i,y2=j;  //�յ�
        }
        q=qq;ss.x=x1;ss.y=y1;ss.step=0;
        q.push(ss);visit[x1][y1]=0;s=0;
        bfs();
        cout<<s<<endl;
    }
    return 0;
}
