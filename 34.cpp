#include<iostream>
//#include<string>
#include<algorithm>
using namespace std;
bool used[21];
int arr[21];
int t,m;//t：边长,sum:周长 ,m:输入的根数
bool cmp(int x,int y)
{
    return x>y;
}
bool dfs(int count,int x,int y)
{
    int i;
    //count:完成几条边，x：在遍历第几根，y：距离拼好目标差多少
    if(count==3)
    {//若是已经拼完3根，意味着成功
        return true;
    }
    for(i=x;i<m;i++)
    {
        if(used[i])
            continue;
        used[i]=true;
        if(arr[i]==y)//若是第i个数据与y相等则拼成一条边
        {
            if(dfs(count+1,0,t))
                return true;
        }
        else if(arr[i]<y)//若小于，则遍历下面的边
        {
            if(dfs(count,i+1,y-arr[i]))
                return true;
        }
        used[i]=false;//未成功拼成一条边
    }
    return false;
}
int main()
{
    int i,n,sum;
    cin>>n;
    while(n--)
    {
        cin>>m;
        sum=0;
        for(i=0;i<m;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%4)
        {
            cout<<"no"<<endl;
            continue;
        }
        t=sum/4;
        memset(used,false,sizeof(used));//dev一直提示没有定义memset，但是oj可以通过
        sort(arr,arr+m,cmp);
        if(dfs(0,0,t))
        {
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
Problem Description
Given a set of sticks of various lengths, is it possible to join them end-to-end to form a square?

Input
The first line of input contains N, the number of test cases. Each test case begins with an integer 4 <= M <= 20, the number of sticks. M integers follow; each gives the length of a stick - an integer between 1 and 10,000.

Output
For each case, output a line containing “yes” if is is possible to form a square; otherwise output “no”.

Sample Input
3
4 1 1 1 1
5 10 20 30 40 50
8 1 7 2 6 4 4 3 5

Sample Output
yes
no
yes
