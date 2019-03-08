#include <iostream>
#include <string>
#include <map>
using namespace std;
string ip[1005];
string order[10005];
int main()
{
    int n,m;
    map<string,string> mymap;
    map<string,string>::iterator iter;
    cin >> n >> m;
    string a,b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        b+=";";
        a = "#"+a;
        mymap[b] = a;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> order[i] >> ip[i];
    }
    for(int i = 0; i < m; i++)
    {
        for(iter=mymap.begin();iter!=mymap.end();iter++)
        {
            if(iter->first==ip[i])
            {
                cout << order[i] << " " << iter->first<<" " << iter->second<<"\n";
            }
        }
    }
    return 0;
}
