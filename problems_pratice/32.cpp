#include <iostream>
#include <cstring>
using namespace std;
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
            int k = 1;
            for(int i=0; i<d-1;i++)
            {
                if(l%2){k=k*2;l=(l+1)/2;}
                else{k=k*2+1;l/=2;}
            }
            cout << k<<"\n";
        }
    }

    return 0;
}
