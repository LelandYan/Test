#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int ex[3] = {2,3,5};
int main()
{

    priority_queue<ll,vector<ll>,greater<ll> >p;
    set<ll>s;
    p.push(1);
    s.insert(1);
    for(int i=1;;i++)
    {
        ll x = p.top();
        p.pop();
        if(i==1500)
        {
            cout << "The 1500'th ugly number is "<<x<<"."<<endl;
            break;
        }
        for(int j = 0; j < 3; j++)
        {
            ll x2 = x * ex[j];
            if(!s.count(x2))
            {
                s.insert(x2);
                p.push(x2);
            }
        }
    }
    return 0;
}
