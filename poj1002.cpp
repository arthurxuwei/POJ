#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 20
char a[SIZE];
char map[256];

struct Phones{
	char str[SIZE];
	int times;
};

bool strCom(char *str1, char *str2) {
	if(*str1 == '\0' || *str2 == '\0') {
		return false;
	}
	for(;*str1!='\0' && *str2!='\0' && *str1 != *str2; str1++,str2++){
		return false;
	}
	return true;
}

bool isLE(char *str1, char *str2) {
	if(*str1 == '\0') {
		return false;
	}
	if(*str2 == '\0') {
		return true;
	}
	
	for(;*str1!='\0'&&*str2!='\0'&&*str1 > *str2; str1++, str2++) {
		return false;
	}
	return true;
}
/*
void sort(Phones p[], int n) {
	bool ex = false;
	for (int j = n; j>0; j--){
	for (int i = 1; i < j; i++) {
//		cout << "isLE: " << isLE(p[i - 1].str,p[i].str) << ". " << p[i-1].str << " with " << p[i].str << endl; 
		if(p[i-1].str[0] == '\0' && p[i].str[0]== '\0') 
			continue;
		if (isLE(p[i - 1].str, p[i].str)) {
		}
		else {
			Phones t = p[i - 1];
			p[i-1] = p[i];
			p[i] = t;
			ex = true;
		}
	}
	if(!ex) {break;}
	}
}
*/

void swap(Phones *t1, Phones *t2) {
	Phones t = *t1;
	*t1 = *t2;
	*t2 = t;
}

void sort(Phones p[], int begin, int end) {
	if(begin>=end) return;
	int min = (begin+end) /2;
	int i=begin, j=end-1;
	while(i <= j){
		if (isLE(p[i].str, p[end].str)){
			i++;continue;
		}
		if (!isLE(p[j].str, p[end].str)){
			j--;continue;
		}

		swap(&p[i], &p[j]);
		++i;
		--j;
	}

	swap(&p[i], &p[end]);
	sort(p, begin, i-1);
	sort(p, i+1, end);
}
int main(int argc, char** argv) {
	int n;
	memset(&map, '0', sizeof(map));
	map['A'] = '2'; map['B'] = '2'; map['C'] = '2';
	map['D'] = '3'; map['E'] = '3'; map['F'] = '3';
	map['G'] = '4'; map['H'] = '4'; map['I'] = '4';
	map['J'] = '5'; map['K'] = '5'; map['L'] = '5';
	map['M'] = '6'; map['N'] = '6'; map['O'] = '6';
	map['P'] = '7'; map['R'] = '7'; map['S'] = '7';
	map['T'] = '8'; map['U'] = '8'; map['V'] = '8';
	map['W'] = '9'; map['X'] = '9'; map['Y'] = '9';

	cin >> n;

	Phones phones[n];
	for(int i=0; i<n; i++) {
		memset(&phones[i].str, '\0', SIZE);
	};

	for(int k = n-1; k>=0;k--) {
		memset(&a, '\0', sizeof(a));
//		cout << "#K: " << k << endl;
		cin >> a;
		int i=0, space=0;
		while (a[i] != '\0') {
			if(a[i] == '-') {
				space++;
			} else if ( a[i] >= 'A' && a[i] <= 'Z' ) {
//				cout << "map: " << a[i] << " to " << map[a[i]] << endl;
				a[i-space] = map[a[i]];
			} else if ( a[i] >= '0' && a[i] <= '9' ) {
				a[i-space] = a[i];
			}
			i++;
		}
		a[7] = '\0';
		int j = n-1;
		for(; j>=0; j--) {
//			cout << "Strat Compare: " << phones[j].str << " and " << a << endl;
//			cout << "compare result: " << strCom(phones[j].str, a) << endl;
			if(strCom(phones[j].str, a)) {
				phones[j].times++;
				break;
			} 
		}
		if (j < 0) 
		{
			memcpy(&phones[k].str, &a, sizeof(a));
			phones[k].times = 1;
		}
	}
//	cout << "Start sorting..." << endl;
	sort(phones, 0, n-1);

//	cout << "End sorting..." << endl;
	int b = 0;
	for(int i=0; i<n; i++) {
		if(phones[i].str[0] != '\0' && phones[i].times > 1){
			cout << phones[i].str[0] << phones[i].str[1] <<phones[i].str[2] << '-' <<phones[i].str[3]  << phones[i].str[4] << phones[i].str[5] << phones[i].str[6] << ' ' << phones[i].times << endl;
		b++;
	}}
	if (b==0) { cout << "No duplicates." << endl;}

	
	return 0;
}
