#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        if(n==0&&k==0)break;
        if(k>n/2)k=n-k;
        long long ans=1;
        for(int i=1;i<=k;i++,n--)
        {
            ans*=n;
            ans/=i;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
