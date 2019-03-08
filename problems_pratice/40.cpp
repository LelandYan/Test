#include<iostream>
#include<cstring>
#include<cmath>
const int maxn=2003;
int arr[maxn][maxn];
using namespace std;
int main()
{
    long long a;
    for(int i=0; i<maxn; i++)
        for(int j=0; j<=i; j++)
        {
            if(j==0||i==j)arr[i][j]=1;
            else arr[i][j]=(arr[i-1][j]+arr[i-1][j-1])%1007;
        }
    cin>>a;
    int n,m;
    while(a--)
    {
        cin>>m>>n;
        cout<<arr[n][m]<<"\n";
    }
    return 0;
}
