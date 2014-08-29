#include <iostream>
#include <cstring>
using namespace std;

void swap(char *&a, char *&b) {
	char *t;
	t = b;
	b = a;
	a = t;
}
/*
int partation(char **a, int begin, int end, int n) {
	int i =begin, j = 0;
	int v = a[begin][n-1] - '0';
	for(j = begin+1; j <= end -1;j++){
		cout << "v1,v2: " << a[i][n-1]-'0' << " " << v << endl;
		if (a[j][n-1] - '0' <= v) {
			++i;
			swap(a[i], a[j], n);
		} 
	}
	swap(a[i], a[begin], n);
	return i;
}


void sort(char **a, int begin, int end, int n) {
	if(begin < end) {
		int p = partation(a, begin, end, n);
		sort(a, begin, p-1,n);
		sort(a, p+1, end, n);
	}
}
*/
void sort(char **a, int m, int n) {
	for( int i=m-1; i >=0; --i) {
		for( int j=0; j < i;++j) {
			if(a[j][n-1]-'0' > a[j+1][n-1]-'0' ){
				swap(a[j], a[j+1]);
			}
		}
	}
}

int main () {
	int n = 0, m = 0;
	cin >> n >> m;
	char **str = new char *[m];
	for( int i=0; i < m; i++)
		str[i] = new char[n+2];
	for(int i=0;i<m;i++){
		cin >> str[i];
		str[i][n+1] = '0';
	}
	int len = 0;
	for(int i=0; i < m; i++) {
		for(int j=0; j<n-1;j++){
			for(int k=j+1; k<n; k++) {
				if(str[i][j] > str[i][k]){
					len++;
				} else continue;
			}
		}
		cout << "t: " << len << endl;
		str[i][n+1] = (char)((int)'0'+len);
		len=0;
	}
	for(int i=0; i< m; i++) {
		cout << "c: " << str[i][n+1] << endl;
	}

	sort(str, m, n+2);

	for( int i=0; i<m; i++) {
		cout << str[i] << endl;
	}

}
