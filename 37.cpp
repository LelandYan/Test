#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100000//求MAX范围内的素数
long long su[MAX],cnt;
bool isprime[MAX];
void prime()
{
    cnt=1;
    memset(isprime,1,sizeof(isprime));//初始化认为所有数都为素数
    isprime[0]=isprime[1]=0;//0和1不是素数
    for(long long i=2;i<=40;i++)
    {
        /*if(isprime[i])//保存素数
        {
            su[cnt++]=i;
        }*/
        for(long long j=i*i;j<=40;j+=i)//素数的倍数都为合数
        {
            isprime[j]=0;
        }
    }
}
int main()
{
    prime();
    for(long long i=0;i<40;i++)
        printf("%d  ",isprime[i]);
    return 0;
}
