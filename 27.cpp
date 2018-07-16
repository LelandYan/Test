#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
ll cnt=0;
ll arr[500005];
void mergearray(ll a[], ll first, ll mid, ll last, ll temp[])
{
    ll i = first, j = mid + 1;
    ll m = mid,   n = last;
    ll k = 0;

    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            temp[k++] = a[j++];
            cnt += m-i+1;
        }
    }
    while (i <= m)
        temp[k++] = a[i++];

    while (j <= n)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(ll a[], ll first, ll last, ll temp[])
{
    if (first < last)
    {
        ll mid = (first + last) / 2;
        mergesort(a, first, mid, temp);
        mergesort(a, mid + 1, last, temp);
        mergearray(a, first, mid, last, temp);
    }
}

bool MergeSort(ll a[], ll n)
{
    ll *p = new ll[n];
    if (p == NULL)
        return false;
    mergesort(a, 0, n - 1, p);
    delete[] p;
    return true;
}
int main()
{
    ll a;
    while(cin >> a)
    {
        if(a==0)
        {
            break;
        }
        cnt = 0;
        for(ll i = 0; i < a; i++)
        {
            cin >> arr[i];
        }
        MergeSort(arr,a);
        cout << cnt << "\n";
    }

    return 0;
}
