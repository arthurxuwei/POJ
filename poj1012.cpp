#include <iostream>

using namespace std;

int joseph(int a[], int n,int m) {
	
	int k =1;
	int i = -1;

	while(1) {
		for(int j=0; j <m;) {
			i = (i+1) %n;
			if(a[i] != 0)
				j++;		
		}
		if(k<=n/2 && a[i] <= n/2) return 0;
		if(k==n) break;
	//	cout << a[i] << ",";
		a[i] = 0;
		k++;
	}
	//cout << a[i] << endl;
	return 1;
}
int factorial(int n) {
	int t = 1;
	for(int i=n; i>0; i--){
		t *= i;
	}
	return t;
}

main() {
	int n;
	while(true) {
		cin >> n;
		if(n == 0) break;
		int a[2*n];
		int times= factorial(2*n);
	//	cout << "times: " << times << endl;

		for(int i=n; i<times; i++){
			if( i%(2*n) < n ) continue;
			for(int j=0; j<2*n; j++)
				a[j] = j+1;
			if(joseph(a, 2*n, i+1)){
				cout << i+1 << endl;
				break;
			}
		}
	}
}
