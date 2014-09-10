#include<iostream>
using namespace std;
int val = 0;
int find(int a[], int n, int cur, int sum) {
	//cout << "sum: " << sum << " cur: " << cur << endl;
	if( sum == val )
		return 1;
	else if(sum > val)
		return 2;
	else for(int i=cur; i < n; i++ ){
		int v = find(a, n, i+1, sum+a[i]);
		if(v==2) break;
		else if(v==1) return 1;
		while(a[i] == a[i+1]) ++i;
	}
	return 0;
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

		int t[count];
		for(int i=0,j=0; i<6;){
			if(arr[i]) {
				t[j++] = i+1;
				sum += (i+1);
				arr[i]--;
			}else i++;
		}
		if(sum%2) {
			cout << "Collection #" << n << ":\nCan't be divided." << endl;  
			continue;
		}
		val = sum / 2;
	//	cout << "val: " << val << endl;
//		for(int i=0; i<count;i++)
//			cout << t[i];
//		cout << endl;
		if(find(t, count, 0, 0)==1)
			cout << "Collection #" << n << ":\nCan be divided." << endl;  
		else
			cout << "Collection #" << n << ":\nCan't be divided." << endl;  
		n++;
	}
}

