#include <iostream>
#include <algorithm>
using namespace std;
//���һ��
long long fun(long long  a, long long b,long long c)
{
    int s = 1;
    while(b)
    {
        if(b%2==1)
        {
            s %= c;
            a %= c;
            s = s * a;
        }
        a %= c;
        a =a*a;
        b /= 2;
    }
    return s%c;
}
int main()
{
    long long a,b,c,d;
    cin >> a;
    while(a--)
    {
        cin >> b >> c >> d;
        cout << fun(b,c,d) << endl;
    }
}
