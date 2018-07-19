#include <iostream>
#include <queue>
using namespace std;
char arr[22][22];
int w,h;
int dfs(int x,int y)
{
    if(x<0||y<0||x>=w||y>=h||arr[x][y]=='#')return 0;
    else
    {
        arr[x][y]='#';
        return 1+dfs(x-1,y)+dfs(x+1,y)+dfs(x,y+1)+dfs(x,y-1);
    }

}
int main()
{
    while(cin>>h>>w)
    {
        if(h==0&&w==0)break;
        /*for(int i=0; i<w; i++)
            cin>>arr[i];*/
        for(int i=0; i<w; i++)
            for(int j=0; j<h; j++)
            {
                cin>>arr[i][j];
                    //return 0;
            }
        for(int i=0; i<w; i++)
            for(int j=0; j<h; j++)
            {
                if(arr[i][j]=='@')
                    cout<<dfs(i,j)<<"\n";
                    //return 0;
            }
    }
    return 0;
}
