#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
const double s = sqrt(2);
int fun( int x, int y)
{
    int total = 0;
    for( int i = 1; i <= x + y - 1; i++)
    {
        total += i;
    }
    total += x;
    return total;
}
double fun2(int a, int b)
{
    double total = 0;
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    for(int i = b; i < a; i++)
    {
        total += sqrt(i*i+(i+1)*(i+1));
    }
    return  total;
}
int main()
{
    ios::sync_with_stdio(false);
    int a , x1, y1, x2, y2,c,d;
    double x;
    cin >> a;
    while(a--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        x = 0;
        c = x1 + y1;
        d = x2 + y2;
        x = fabs(fun(x1,y1)-fun(x2,y2))*s;
        x = x + fun2(c,d);
        cout << setprecision(3) << fixed << x << endl;
    }
    return 0;
}
