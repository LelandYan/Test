#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define m 1000000007
using namespace std;
int main()
{
    string a;
    while(cin >> a)
    {
        long long ans=0,cnt=0;
        for(long long i = a.size()-1;i>=0;i--)
        {
            if(a[i]=='b')
            {
                cnt++;
            }
            else
            {
                ans=(ans+cnt)%m;
				cnt=(cnt*2)%m;
            }
        }
        cout << ans<<"\n";
    }
    return 0;
}
