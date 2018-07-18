#include <iostream>
#include <cstring>
using namespace std;
const int maxn=25;
int num[maxn];
int id[maxn];
bool dfs(int start,int len,int)
int main()
{
    int n,m,ma=0,avg,sum=0;
    cin >> n;
    while(n--)
    {
        cin>>m;
        memset(id,0,sizeof id);
        for(int i=0;i<m;i++)
        {
            cin>>num[i];
            ma=ma>num[i]?ma:num[i];
            sum+=num[i];
        }
        avg=sum/4;
        if((sum%4)||(ma>avg))
        {
            cout<<"no\n";
            return 0;
        }
        if(dfs())
    }
    return 0;
}
