#include <iostream>
using namespace std;

float arr[300];
int main() {
	arr[0] = 0.5;
	for (int i = 1; i < 300; i++) {
		arr[i] = arr[i-1] + (1.0 / (i+2));
	}
/*
	for (int i = 0; i < 300; i++) {
		cout << arr[i] << " ";
	}
*/
	float in = 0.0;
	while (cin >> in) {
		if ( in == 0.00 ) break;
		for (int i = 0; i <300;) {
			if ( arr[i] - in >=0 ) {
				cout << i+1 << " card(s)" << endl;
				break;
			} else {
				i++;
			}
		}
	}
	return 0;
}
