#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    string a;
    while(cin >> n)
    {
        if(n==0)
        {
            break;
        }
        map<string,int> mymap;
        while(n--)
        {
            cin >> a;
            mymap[a]++;
        }
        map<string,int>::iterator itera;
        int mi = 0;
        for(itera= mymap.begin();itera!=mymap.end();itera++)
        {
            if((itera->second) > mi)
            {
                mi = itera->second;
            }
        }
        for(itera= mymap.begin();itera!=mymap.end();itera++)
        {
            if((itera->second) == mi)
            {
                cout << itera->first<<endl;
                break;
            }
        }
    }
    return 0;
}
