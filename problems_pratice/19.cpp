#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int,int>mymap;
    int a = 2, b = 1;
    mymap[1] = 1;
    int tem;
    for(int i = 0; i < n;i++)
    {
        mymap[a]++;
        tem = a;
        a = a + b;
        b = tem;
    }
    for(int i = 1; i <= n; i++)
    {
        if(mymap[i])
        {
            cout << "O";
        }
        else
        {
            cout << "o";
        }
    }
    return 0;
}
