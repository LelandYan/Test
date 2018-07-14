#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 30;
void sm(vector<string>&obj,string b)
{
    char a = b[b.size()-1];
    bool flag = false;
    //cout <<"**" <<obj.size()<<" "<<a<<" "<<b <<"***\n";
    for(int i=0; i < obj.size(); i++)
    {
        if(obj[i][obj[i].size()-1]==a)
        {
            if(b.size()>obj[i].size())
            {
                obj[i] = b;
            }
            flag = true;
        }
    }
    if(!flag)
        obj.push_back(b);
}
int main()
{
    int n,num;
    string strn,strp;
    while(cin>>n)
    {
        vector<string>phone[maxn];
        map<string,int>mymap;
        for(int i= 1; i <= n; i++)
        {
            cin >> strn >> num;
            bool flag = false;
            if(!mymap[strn]) mymap[strn] = i;
            for(int j = 0; j < num; j++)
            {
                cin >> strp;
                if(!flag)
                    (phone[mymap[strn]-1]).push_back(strp);
                flag = true;
                sm(phone[mymap[strn]-1],strp);
            }
        }
        map<string,int>::iterator iter;
        cout << mymap.size()<<"\n";
        for(iter=mymap.begin(); iter!=mymap.end(); iter++)
        {
            cout << iter->first << " ";
            sort(phone[iter->second-1].begin(),phone[iter->second-1].end());
            phone[iter->second-1].erase(unique(phone[iter->second-1].begin(), phone[iter->second-1].end()), phone[iter->second-1].end());
            cout << (phone[iter->second-1]).size() << " ";
            for(int i = 0; i < (phone[iter->second-1]).size(); i++)
            {

                cout << phone[iter->second-1][i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
