#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool is_p(int x){
	for(int i = 2; i <= sqrt(x); i++){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	int x;
	int t;
	cin >> x;
	for(int i=2; i <= x-4; i++){
		for(int j = 2; j <= x-4; j++){
			t = x - i - j;
			if((is_p(t)+is_p(i)+is_p(j))==3){
				 cout << i << " " << j << " " << t;
				 return 0;
			} 
		}
	}
	return 0;
}
