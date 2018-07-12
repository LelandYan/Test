#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int a,b;
    while(cin >> a>>b)
    {
        bool falg = false;
        char s[100];
        int cnt = 0;
        if(a < 0)
        {
            a = -a;
            falg = true;
        }
        if(b > 10)
        {
            if(falg)
                cout << "-";
            while(a)
            {
                if((a%b)>=10)
                {
                    s[cnt] = char(a%b+55);
                    cnt++;
                } //cout << char(a%b+55);
                else
                {
                    s[cnt] = char(a % b + 48);
                    cnt++;
                }//cout << a % b;
                a /= b;
            }
            for(int i = cnt-1; i >=0; i--)
            {
                cout << s[i];
            }
        }
        else
        {
            if(falg)
                cout << "-";
            while(a)
            {
                //cout << a % b;
                s[cnt] = char(a % b + 48);
                cnt++;
                a /= b;
            }
            for(int i = cnt-1; i >=0; i--)
            {
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
