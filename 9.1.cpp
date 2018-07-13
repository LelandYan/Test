#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 10000;
int main()
{
    int n,q,x,a[maxn],kase = 0,b[maxn];
    while(cin >> n >> q)
    {
        if( n == 0 && q ==0)
        {
            break;
        }
        for(int i = 0;  i < n; i++)
            cin >> a[i];
        sort(a,a+n);
        for(int i = 0; i < q; i++)
        {
            cin >> b[i];

        }
        cout << "CASE# "<<++kase<<":\n";
        for(int i = 0; i < q; i++)
        {
            int p = lower_bound(a,a+n,b[i]) - a;
            if(a[p]==b[i]) cout << b[i] <<" found at " << p+1 << endl;
            else cout << b[i] << " not found\n";
        }

    }
}
