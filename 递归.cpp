#include <iostream>
using namespace std;
long Fact(long n)
{
    if(n == 0)return 1;
    else return n*Fact(n-1);
}
long Fib(long n)
{
    if(n == 1 || n == 2)return 1;
    else return Fib(n-1)+Fib(n-2);
}
int m = 0;
void move(char A,int n,char C)
{
    cout << ++m << "," << n << "," << A << ","<<C << endl;
}
void Hanoi(int n,char A,char B,char C)
{
    if(n==1)move(A,1,C);
    else
    {
        Hanoi(n-1,A,C,B);
        move(A,n,C);
        Hanoi(n-1,B,A,C);
    }
}
int main()
{
    Hanoi(3,'A','B','C');
    return 0;
}
