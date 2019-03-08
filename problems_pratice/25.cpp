#include <bits/stdc++.h>
using namespace std;
struct node
{
    char number[10];
    char name[10];
    int grate;
} T[100005];
int cmp1(struct node a, struct node b)
{
    return strcmp(a.number, b.number)<0;
}
int cmp2(struct node a, struct node b)
{
    if(strcmp(a.name, b.name))
        return strcmp(a.name, b.name)<0;
    else
        return strcmp(a.number, b.number)<0;
}
int cmp3(struct node a, struct node b)
{
    if(a.grate!=b.grate)
        return a.grate<b.grate;
    else
        return strcmp(a.number, b.number)<0;
}
int main()
{
    int n, m;
    int cnt=1;
    while(cin >> n >> m)
    {
        if(n==m)
        {
            break;
        }
        for(int i=0; i<n; i++)
        {
            cin >>T[i].number>>T[i].name>>T[i].grate;
        }
        if(m==1)
            sort(T, T+n, cmp1);
        else if(m==2)
            sort(T, T+n, cmp2);
        else
            sort(T, T+n, cmp3);
        cout << "Case "<<cnt <<":\n";
        for(int i=0; i<n; i++)
            cout << T[i].number<<" "<<T[i].name<<" "<<T[i].grate<<"\n";
        cnt++;
    }

    return 0;
}
