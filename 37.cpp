#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100000//��MAX��Χ�ڵ�����
long long su[MAX],cnt;
bool isprime[MAX];
void prime()
{
    cnt=1;
    memset(isprime,1,sizeof(isprime));//��ʼ����Ϊ��������Ϊ����
    isprime[0]=isprime[1]=0;//0��1��������
    for(long long i=2;i<=40;i++)
    {
        /*if(isprime[i])//��������
        {
            su[cnt++]=i;
        }*/
        for(long long j=i*i;j<=40;j+=i)//�����ı�����Ϊ����
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
