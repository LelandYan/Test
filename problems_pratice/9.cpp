#include <iostream>
#include <map>
using namespace std;
int arr[10000];
int main()
{
    int n,q;
    int cnt = 1;
    while(cin >> n >> q)
    {
        map<int,int> mymap;
        //int cnt = 1;
        if(n==0&&q==0)
        {
            break;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> mymap[i];
        }
        for(int i = 0; i < q; i++)
        {
            cin >> arr[i];
        }
        map<int,int>::iterator iter;
        cout << "CASE# "<<cnt<<":\n";
        for(int i = 0; i < q; i++)
        {
            bool flag = false;
            for(iter=mymap.begin(); iter!=mymap.end(); iter++)
            {
                if(iter->second == arr[i])
                {

                    cout << arr[i] << " found at "<<iter->first+2<<endl;
                    flag = true;
                    break;
                }
            }
            if(!flag)
            {
                cout << arr[i] << " not found\n";
            }
        }
        cnt++;
    }
    return 0;
}
