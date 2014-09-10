#include<iostream>
using namespace std;
int val = 0;
bool find(int a[], int n, int cur, int sum) {
	//cout << "sum: " << sum << " cur: " << cur << endl;
	if( sum == val )
		return true;
	else if(sum > val)
		return false;
	else for(int i=cur; i < n; i++ ){
		if(find(a, n, i+1, sum+a[i])) return true;
	}
	return false;
}

main() {
	int n = 1;
	int arr[] = {0,0,0,0,0,0};
	int sum=0;
	int count=0;
	while(1) {
		sum=0; val=0; count=0;
		for(int i = 0; i<6;i++){
			cin >> arr[i];
			count+=arr[i];
		}
		if(count == 0) break;

		for(int i = 0; i<6;i++){
			sum += arr[i]*(i+1);
		}
		if(sum%2) {
			cout << "Collection #" << n << ":\nCan't be divided." << endl;  
			continue;
		}
		val = sum / 2;
	//	cout << "val: " << val << endl;
		int t[count];
		for(int i=0,j=0; i<6;){
			if(arr[i]) {
				t[j++] = i+1;
				arr[i]--;
			}else i++;
		}
		for(int i=0; i<count;i++)
			cout << t[i];
		cout << endl;
		if(find(t, count, 0, 0))
			cout << "Collection #" << n << ":\nCan be divided." << endl;  
		else
			cout << "Collection #" << n << ":\nCan't be divided." << endl;  
	}
}

