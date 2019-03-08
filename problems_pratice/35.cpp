#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=25;
int num[maxn];
bool id[maxn];
int avg,m;
bool dfs(int start,int len,int index)
{
    // if(len>ave)return false;
    if(len==avg)return index==3?1:dfs(0,0,index+1);
    else
    {
        for(int i=start; i<m; i++)
            if(!id[i]&&(len+num[i])<=avg)
            {
                id[i]=true;
                if(dfs(i+1,len+num[i],index))return true;
                id[i]=false;
            }
    }

    return false;
}
bool cmp(int a,int b)
{
    return a > b;
}
int main()
{
//    ios::sync_with_stdio(false);
  //  cin.tie(0);
  //  cout.tie(0);
    int n,ma,sum;
    cin >> n;
    while(n--)
    {
        cin>>m;
        ma=0,sum=0;
       //  cout<<"dfdf";
        memset(id,0,sizeof id);
        for(int i=0; i<m; i++)
        {
            cin>>num[i];
            ma=ma>num[i]?ma:num[i];
            sum+=num[i];
        }
        sort(num,num+m,cmp);
        // cout << num[m-1] << endl;
        avg=sum/4;

        if((sum%4)||(ma>avg))
        {
            cout<<"no\n";
            continue;
        }

        else if(dfs(0,0,0))cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
