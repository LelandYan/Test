#include<iostream>
#include<algorithm>
using namespace std;
struct apple {
	int height;
	int power;
};
bool compare(const apple &a1, const apple &a2){
	return a1.power < a2.power;
}
int main() {
	struct apple apples[5005];
	int n,s,a,b,temp_h,temp_p;
	int cnt = 0;
	cin >> n >> s >> a >> b;
	for(int i = 0; i < n; i++) {
		cin >> temp_h >> temp_p;
		if(temp_h>(a+b)) {
			continue;
		} else {
			apples[cnt].height = temp_h;
			apples[cnt].power = temp_p;
			cnt++;
		}
	}
	sort(apples, apples+cnt, compare);
	int counter = 0;
	for(int i = 0; i < cnt; i++){
		if((s-apples[i].power)>=0){
			s -= apples[i].power;
			counter++;
		}
	}
	cout << counter;
	return 0;
}
