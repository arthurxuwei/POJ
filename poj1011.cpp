#include <iostream>
using namespace std;

main() {
	int len;
	while(cin >> len) {
		if(len==0){
			return 0;
		}
		int a[len];
		int max=0;
		int sum=0;
		int tmp;
		for(int i=0; i<len;i++) {
			cin >> tmp;
			if(tmp > max) max = tmp;
			sum+=tmp;
			a[i] = tmp;
		}
		for(int i=0; i<50; i++) {
			if (sum%(max+i) == 0) {
				cout << max+i << endl;
				break;
			}
		}
	}
}
