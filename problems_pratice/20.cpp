#include <iostream>
#include <string>
#include <map>
using namespace std;
#define ll long long
int main()
{
    ll n;
    while(cin >> n)
    {
        ll tot=1;
        for(ll i = 2; i*i <=n; i++)
        {
            if(n%i==0)
            {
                tot*=i;
                while(n%i==0)
                {
                    n/=i;
                }
            }
        }
        cout << tot*n<<"\n";
    }

    return 0;
}
