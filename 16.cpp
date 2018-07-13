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
int arr[1000002];
using namespace std;
int main()
{
    int a,b,c;
    int cnt=1,cnt2=0;
    while(cin >> a)
    {
        cnt2=0;
        map<int,int>team;
        queue<int>q,qq[1010];
        if(a == 0)break;
        for(int i = 0; i < a; i++)
        {
            cin >> b;
            while(b--)
            {
                cin >> c;
                team[c] = i;
            }
        }
        char s[15];
        int tem;
        while(cin >> s)
        {
            if(s[0]=='E')
            {
                cin >> tem;
                int t = team[tem];
                if(qq[t].empty())
                    q.push(t);
                qq[t].push(tem);
            }
            else if(s[0]=='D')
            {
                int t = q.front();
                arr[cnt2]=qq[t].front();
                qq[t].pop();
                if(qq[t].empty())
                    q.pop();
                cnt2++;

            }
            else if(s[0]=='S')
            {
                break;
            }
        }
        cout <<"Scenario #"<<cnt<<endl;
        for(int i = 0; i < cnt2; i++)
        {
            cout << arr[i]<<endl;
        }
        cout << endl;
        cnt++;
    }
    return 0;
}
