#include<iostream>
using namespace std;
int main() {
	double s,x,v=7,t=0;
	cin >> s >> x;
	while(t<(s-x)) {
		t += v;
		v *= 0.98;
	}
	if(v*0.98>(s-x-t))cout<<"n";
	else cout << "y";
	return 0;
}
