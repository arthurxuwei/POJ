#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	float in = 0.0;
	float sum = 0.0;
	for(int i =0; i < 12; i++) {
		cin >> in;
		sum += in;
	}
	cout << "$" << fixed << setprecision(2) <<sum / 12<< endl;
}
