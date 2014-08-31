#include <iostream>
#include <cstring>

using namespace std;
const char *month[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

const char *days[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};


int main () {
	int n = 0;
	cin >> n;
	cout << n << endl;
	while(n>0) {
		char a[4];
		char b[10];
		int year;
		cin >> a >> b >> year;

		int day = 0;
		for(int i =0; a[i] != '.'; i++) {
			day = day*10 + a[i] - '0';
		}

		int mon = 0;
		for(int i = 0; i < 19; ++i) {
//		cout << "com: " << strcmp(month[i], b) << endl;
			if(strcmp(month[i], b) == 0) {
				mon = i;
				break;
			}
		}		
		mon = mon*20;
		int sum = year*365 + mon + day;
//		cout << "sum: " << sum << " day: " << day << " month: " << mon << " year: " << year << endl;	
		int year2 = sum / 260;
		int temp = sum % 260;
		int day2 = temp % 20;
		int mon2 = (temp % 13) +1;
		cout << mon2 << " " << days[day2] << " " << year2 << endl;
		--n;
	}
	return 0;	
}
