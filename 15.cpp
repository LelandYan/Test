#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int a,n;
    cin >> a;
    while(a--)
    {
        cin >> n;
        double m = n * log10((double)n);
        double g = m - (long long)m;
        g = pow(10.0,g);
        cout << int(g) << endl;
    }
    return 0;
}
