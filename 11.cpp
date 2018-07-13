#include <iostream>
#include <algorithm>
using namespace std;
//最后一题
int fun(int a, int b,int c)
{
    int s = 1;
    while(b)
    {
        if(b%2)
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
    long int a,b,c,d;
    cin >> a;
    while(a--)
    {
        cin >> b >> c >> d;
        cout << fun(b,c,d) << endl;
    }
}
