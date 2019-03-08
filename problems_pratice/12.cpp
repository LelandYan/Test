#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
using namespace std;
set<string> myset;
int main()
{
    string a,b;
    while(cin>>a)
    {
        for(int i = 0; i < a.size();i++)
        {
            if(isalpha(a[i])) a[i] = tolower(a[i]);
            else a[i] = ' ';
        }
        stringstream ss(a);
        while(ss >> b) myset.insert(b);

    }
    set<string>::iterator itera;
    for(itera = myset.begin();itera!=myset.end();itera++)
    {
        cout << *itera << endl;
    }
    return 0;
}
