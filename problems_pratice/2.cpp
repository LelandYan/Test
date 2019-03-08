#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int t,a,b,c,d,e,f;
    cin >> t;
    while(t--)
    {
        e = f =0;
        cin >> a >> b >> c >>d;
        int m=0,n=0;
        if(b > d)
        {
            m = b;
            n = d;
        }
        else
        {
            m = d;
            n = b;
        }
        f = b * d / gcd(m,n);
        e += f /b * a;
        e += f /d * c;
        if(e > f)
        {
            m = e;
            n = f;
        }
        else
        {
            m = f;
            n = e;
        }
        int q = gcd(m,n);
        cout << e/q << " " << f/q << endl;
    }
    return 0;
}
