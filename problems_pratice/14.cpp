#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;
map<string,int> mymap;
vector<string> origion;
string rep(const string & s)
{
    string a=s;
    for(int i = 0; i < a.size(); i++)
    {
        a[i] = tolower(a[i]);
    }
    sort(a.begin(),a.end());
    return a;
}
int main()
{
    string str;
    map<string,int>::iterator iter;
    while(cin >> str)
    {
        if(str[0]=='#')
        {
            break;
        }
        origion.push_back(str);
        string a = rep(str);
        mymap[a]++;
    }
    vector<string> news;
    for(int i= 0; i < origion.size();i++)
    {
        if(mymap[rep(origion[i])]==1)
            news.push_back(origion[i]);
    }
    sort(news.begin(),news.end());
    for(int i= 0; i <news.size();i++)
    {
        cout << news[i] << endl;
    }
    return 0;
}
