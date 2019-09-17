#include<iostream>
#include<string.h>
using namespace std;
int s[1005]={0};
// 加油站序号 [A,B,C,D,E,F...]
// 加油站所占的公里数 [2,5,6,7,8,9...] 
int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < k+1; i++){
		cin >> s[i];
		if(n < s[i]){
			cout << "No solution";
			return 0;
		}
	}
	int c = n;
	int t = 0;
	int cnt = 0;
	for(int i = 0; i < k+1; i++){
		t += s[i];
		if(t>c){
			cnt++;
			t -=n;
		}
	}
	cout << cnt;
	return 0;
}
