#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 20;
int s[1<<maxn+5];
int main()
{
    int line;
    while(cin>>line)
    {
        if(line==-1)break;
        int d,l;
        while(line--)
        {
            cin>>d>>l;
            memset(s,0,sizeof(s));
            int k,n=(1<<d)-1;
            for(int i=0; i<l; i++)
            {
                k = 1;
                while(true)
                {
                    s[k] = !s[k];
                    k=s[k]?k*2:k*2+1;
                    if(k>n)break;
                }
            }
            cout << k/2<<"\n";
        }
    }
    return 0;
}
