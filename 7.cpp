#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int arr[100][100];
char str[10000];
int main()
{
    int a;
    int cnt = 1;
    cin >> a;
    for(int i = 0;i <a;i++)
    {
        for(int j =0; j < a;j++)
        {
            cin >> a[i][j];
        }
    }
    str[0] = arr[0][0];
    for(int i = 1; i < a; i++)
    {
        if(i%2!=0)
        {
            int c = i;
            for(int j = 0; j <= i; j++)
            {
                str[cnt] = arr[j][c];
                c--;
                cnt++;
            }
        }
        else
        {
            int c = i;
            for(int j = 0; j <= i; j++)
            {
                str[cnt] = arr[c][j];
                c--;
                cnt++;
            }
        }
    }
    for(int i = n-2;i<0;i--)
    {
        if(i%2!=0)
        {
            int c = n - i-1;
            for(int j = n-1; j >=n-1-i; j--)
            {
                str[cnt] = arr[c][j];
                c++;
                cnt++;
            }
        }
        else
        {
            int c = n - i+1;
            for(int j = 2; j <= i+1; j++)
            {
                str[cnt] = arr[j][c];
                c--;
                cnt++;
            }
        }
    }
    return 0;
}
