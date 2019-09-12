#include<iostream>
#include<string.h>
using namespace std;
int memory[25][25][25];
int func(int a, int b, int c){
	if(a<=0||b<=0||c<=0)return 1;
	else if(memory[a][b][c]!=0)return memory[a][b][c];
	else if(a>20||b>20||c>20)return func(20,20,20);
	else if(a<b&&b<c)memory[a][b][c] = func(a,b,c-1)+func(a,b-1,c-1)-func(a,b-1,c);
	else memory[a][b][c] = func(a-1,b,c)+func(a-1,b-1,c)+func(a-1,b,c-1)-func(a-1,b-1,c-1);
	return memory[a][b][c];
}
int main(){
	int a,b,c;
	while(true){
		cin >> a >> b >> c;
		memset(memory,0,sizeof(memory));
		if(a==-1&&b==-1&&c==-1)return 0;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		if(a>20)a=21;
		if(b>20)b=21;
		if(c>20)c=21;
		cout << func(a,b,c) << endl;
	}
	return 0;
}
