#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct node
{
    string a;
    int b;
}num[maxn];
int bubble(string a)
{
    int cnt = 0;
    for(int i =0; i < a.size();i++)
    {
        for(int j = i+1; j <a.size();j++)
        {
            if(a[i] > a[j])
                cnt++;
        }
    }
    return cnt;
}
bool cmp(struct node n1,struct node n2)
{
    return (n1.b < n2.b);
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> num[i].a;
        num[i].b = bubble(num[i].a);
    }
    sort(num, num+m, cmp);
    for(int i = 0; i < m; i++)
    {
        cout << num[i].a << "\n";
    }
    return 0;
}
