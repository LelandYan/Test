#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int arr[100002];
#define ins 1000000005
int main()
{
    int a,b;
    cin >> a >> b;
    int ma=-ins,mi=ins;
    for(int i = 0; i < a; i++)
    {
        cin >> arr[i];
        if(arr[i] > ma) ma = arr[i];
        if(arr[i] < mi) mi = arr[i];
    }
    if(b==1)
        cout << mi<<endl;
    else if(b > 2)
        cout << ma<<endl;
    else if(b==2)
        cout << max(arr[0],arr[a-1]);
    //sort(arr,arr+a);
    return 0;
}
