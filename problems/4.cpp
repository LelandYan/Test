#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int means[10001][11];//���䷽��
int mean[11];
int cnt; //�ܷ�����
int n; //����ζ��
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
		dfs(1,0);//1��ʾ��һ������ 0��ʾ��ζ�̶�Ϊ0
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
