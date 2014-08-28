#include <iostream>
#include <cmath>
using namespace std;

float PI = 3.14;

double getR(int year) {
	return sqrt(year*100/PI);
}

int main () {
	int n;
	cin >> n;
	for(int i=0; i<n;i++) {
		double a,b;
		cin >> a >> b;
		for (int j=1;j<500; j++) {
			double r = getR(j);
			if (r>=a && r>=b) {
				cout << "Property " << i+1 << ": This property will begin eroding in year " << j <<"." << endl;
				break;
			}
		}
	}
	cout << "END OF OUTPUT." << endl;
}
