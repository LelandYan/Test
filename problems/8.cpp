#include<iostream>
#include<string.h>
using namespace std;
int s[1005]={0};
// ����վ��� [A,B,C,D,E,F...]
// ����վ��ռ�Ĺ����� [2,5,6,7,8,9...] 
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
