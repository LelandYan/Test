#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int c ,q =1;
    while((c=getchar())!=EOF)
    {
        if(c == '"')
        {
            //cout << 132;
            if(q)
            {
                cout << "``";
            }
            else
            {
                cout << "''";
            }
            q = !q;
        }
        else
        {
            cout << char(c);
        }
    }

}
