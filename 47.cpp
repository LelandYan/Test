#include <iostream>
#include <queue>
#include <cstring>
int maps[303][303];
int vis[303][303];
int n,l,x1,y1,x2,y2,cnt;
using namespace std;
void bfs()
{

}
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>l>>x1>>y1>>x2>>y2;
        bfs();
        cout<<cnt<<"\n";
    }
    return 0;
}
