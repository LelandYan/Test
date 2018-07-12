#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int mul(int c,int d)
{
    if(c < d)
    {
        int tem = d;
        d = c;
        c = tem;
    }
    return c  / gcd(c,d)* d;
}
int main()
{
    int a;
    cin >>a;
    while(a--)
    {
        int b,c,d;
        cin >> b;
        for(int i = 0; i < b; i++)
        {
            cin >> c;
            if(i>=1)
            {
                d = mul(c,d);
            }
            if(i==0)
            {
                d = c;
            }
        }
        cout << d << endl;
    }
    return 0;
}
