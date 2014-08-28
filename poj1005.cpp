#include <iostream>
#include <cmath>
using namespace std;

float PI = 3.14;

int main () {
	int n;
	cin >> n;
	for(int i=0; i<n;i++) {
		double a,b;
		cin >> a >> b;
		int j = PI *  (a*a + b*b) / 100;
		cout << "Property " << i+1 << ": This property will begin eroding in year " << j+1 <<"." << endl;
	}
	cout << "END OF OUTPUT." << endl;
}
