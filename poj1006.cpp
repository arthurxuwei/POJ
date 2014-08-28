#include <iostream>
using namespace std;

int arr1[924];
int arr2[759];
int arr3[644];

int has(int a[], int size, int v) {
	int left = 0, right = size - 1;
	int m;
	while (left <= right) {
		m = (left + right)/2;
		if ( a[m] > v ) {
			right = m - 1;
		} else if (a[m] < v) {
			left = m + 1;
		} else return 1;
	}
	return 0;
}

int main() {
	int p,e,t,d;
	int n=0;
	while(cin >> p >> e >> t >> d) {
		n++;
		if (p == -1) break;
		for(int i = 0; i<924; ++i){
			arr1[i] = 23 *(i+1) +p;
			if (arr1[i] > 21252) {
				arr1[i] = 21252;break;
			}
		}
		for(int i = 0; i<759; ++i){
			arr2[i] = 28 *(i+1) + e;
			if (arr2[i] > 21252) {
				arr2[i] = 21252;break;
			}
		}
		for(int i=0; i<644; ++i){
			arr3[i] = 33 * (i+1) + t;
			if (arr3[i] > 21252) {
				arr3[i] = 21252;break;
			}
		}

		for (int i = 0; i < 924; ++i) {
//			cout << has(arr2, 759, arr1[i]) << has(arr3, 644, arr1[i]) << endl;
			if( has(arr2, 759, arr1[i]) && has(arr3, 644, arr1[i]) && arr1[i] >= d) {
				cout << "Case " << n << ": the next triple peak occurs in " << arr1[i] - d << " days." << endl;
				break;
			}
		}
	}
	
	
}
