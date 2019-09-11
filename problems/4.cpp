#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int means[10001][11];//搭配方案
int mean[11];
int cnt; //总方案数
int n; //总美味数
void dfs(int k, int t) {
	if(k>10) {
		if(t == n) {
			cnt++;
			for(int i = 1; i <= 10; i++) {
				means[cnt][i] = mean[i];
			}
		}
		return;
	}
	for(int i = 1; i <= 3; i++) {
		if(t+i>n)break;
		mean[k] = i;
		dfs(k+1, t+i);
		mean[k] = 0;
	}
}
int main() {
	cin >> n;
	if(10<=n && n <= 30) {
		cnt = 0;
		dfs(1,0);//1表示第一种配料 0表示美味程度为0
		cout << cnt << endl;
		if(cnt!=0) {
			for(int i = 1; i <= cnt; i++) {
				for(int j = 1; j <= 10; j++) {
					cout << means[i][j] << " ";
				}
				cout << endl;
			}
		}
	}else{
		cout << 0;
	}

	return 0;
}
