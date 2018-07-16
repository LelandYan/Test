#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll a[100005];
int main()
{
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int i,j=0;
    for(i=0; i <n; i++)
    {
        if(a[i] > a[j])
            j++;
    }
    cout << j << "\n";
    return 0;

}
