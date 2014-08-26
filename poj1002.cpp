#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 50
char a[SIZE];
char map[256];

struct Phones{
	char str[8];
	int times;
};

bool strCom(char *str1, char *str2) {
	for(;*str1!='\0' && *str2!='\0' && *str1 == *str2; str1++,str2++){
	}
	if(*str1=='\0')
		return true;
	return false;
}

bool isLE(char *str1, char *str2) {
	while(*str1 != '\0') {
		if(*str1 > *str2) return false;
		else {str1++;str2++;}
	}
	return true;
}

void swap(Phones *t1, Phones *t2) {
	Phones t = *t1;
	*t1 = *t2;
	*t2 = t;
}

int partition(Phones p[], int begin, int end) {
	int min = (begin+end) /2;
	Phones k = p[begin];
	int i=begin,j;
	for(j=begin+1;j<=end;j++) {
		//cout << "isLE: " << isLE(p[j].str, k.str) << " p: " <<p[j].str << " k: " <<k.str<<endl;
		if(isLE(p[j].str, k.str)) {
			i++;
			swap(&p[i], &p[j]);
		}
	}

	swap(&p[i], &p[begin]);
	return i;
}

void sort(Phones p[], int begin, int end) {
	if(begin < end) {
		int pivot = partition(p, begin, end);

		sort(p, begin, pivot-1);
		sort(p, pivot+1, end);
	}
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
		memcpy(&phones[k].str, &a, 8);
		phones[k].times = 1;
	}
	
//	cout << "Start sorting..." << endl;
	sort(phones, 0, n-1);

//	cout << "End sorting..." << endl;
	for (int i=1,j=0; i<n; i++) {
	//	cout << phones[j].str  << " vs " <<  phones[i].str << " is: " <<strCom(phones[j].str, phones[i].str)<< endl;
		if(strCom(phones[j].str, phones[i].str)) {
			phones[j].times++;
		} else {
			j = i;
		}
	}

	int b = 0;
	for(int i=0; i<n; i++) {
		if(phones[i].str[0] != '\0' && phones[i].times > 1){
			cout << phones[i].str[0] << phones[i].str[1] <<phones[i].str[2] << '-' <<phones[i].str[3]  << phones[i].str[4] << phones[i].str[5] << phones[i].str[6] << ' ' << phones[i].times << endl;
		b++;
	}}
	if (b==0) { cout << "No duplicates." << endl;}

	
	return 0;
}
