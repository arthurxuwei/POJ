#include <iostream>

using namespace std;

int temp[13] = {0};
int joseph(int k) {
	
	int n =2*k;
	int ans[30] = {0};
	int m = 1;
	for(int i=1;i<=n/2;i++){
		ans[i] = (ans[i-1]+m-1)%(n-i+1);
		if(ans[i] <k) {
			i=0;
			m++;
		}
	}
	temp[k] = m;
	return m;
}

main() {
	int n;

	while(true) {
		cin >> n;
		if(n == 0) break;
		if(temp[n]) {
			cout << temp[n] << endl;
			continue;
		}
		cout <<	joseph(n) << endl;
	}
}
