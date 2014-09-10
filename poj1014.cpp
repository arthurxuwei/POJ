#include<iostream>
using namespace std;
int val = 0;
bool flag=false;
int arr[] = {0,0,0,0,0,0};
void find(int cur, int sum) {
	cout << "sum: " << sum << " cur: " << cur << endl;
	if(flag)return;
	if( sum == val ){
		flag = true;
		return;
	}
	for(int i=cur; i < 6; i++ ){
		if(arr[i]) {
			if(sum + arr[i] <= val) { 
				arr[i]--;	
				find(i, sum+(i+1));
				if(flag) break;

			}
		}
	}
	return;
}

main() {
	int n = 1;
	int sum=0;
	int count=0;
	while(1) {
		sum=0; val=0; count=0;
		flag = false;
		for(int i = 0; i<6;i++){
			cin >> arr[i];
			count+=arr[i];
		}
		if(count == 0) break;

		for(int i =1; i<=6;i++) {
			sum+=(i*arr[i-1]);
		}
		if(sum%2) {
			cout << "Collection #" << n << ":\nCan't be divided." << endl;
			n++;
			continue;
		}
		val = sum / 2;
		cout << "val: " << val << endl;
		find(0, 0);
		if(flag)
			cout << "Collection #" << n << ":\nCan be divided." << endl;  
		else
			cout << "Collection #" << n << ":\nCan't be divided." << endl;  
		n++;
	}
}

