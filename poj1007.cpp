#include <iostream>
#include <cstring>
using namespace std;

struct DNA{
	char *dna;
	int dis;
};
void swap(DNA *a, DNA *b) {
	DNA t = *b;
	*b = *a;
	*a = t;
}

int partation(DNA a[], int begin, int end) {
	int i =begin, j = 0;
	int v = a[begin].dis;
	for(j = begin+1; j <= end -1;j++){
		if (a[j].dis <= v) {
			++i;
			swap(&a[i], &a[j]);
		} 
	}
	swap(&a[i], &a[begin]);
	return i;
}


void sort(DNA a[], int begin, int end) {
	if(begin < end) {
		int p = partation(a, begin, end);
		sort(a, begin, p-1);
		sort(a, p+1, end);
	}
}
/*
void sort(char **a, int m, int n) {
	for( int i=m-1; i >=0; --i) {
		for( int j=0; j < i;++j) {
			if(a[j][n-1]-'0' > a[j+1][n-1]-'0' ){
				swap(a[j], a[j+1]);
			}
		}
	}
}
*/

int main () {
	int n = 0, m = 0;
	cin >> n >> m;
	DNA arr[m];
	for(int i=0;i<m;i++){
		arr[i].dna = new char[n+1];
		cin >> arr[i].dna;
	}
	int len = 0;
	for(int i=0; i < m; i++) {
		for(int j=0; j<n-1;j++){
			for(int k=j+1; k<n; k++) {
				if(arr[i].dna[j] > arr[i].dna[k]){
					len++;
				} else continue;
			}
		}
		arr[i].dis = len;
		len = 0;
	}
	for(int i=0; i< m; i++) {
		cout << "c: " << arr[i].dis << endl;
	}

	sort(arr, 0, m);

	for( int i=0; i<m; i++) {
		cout << arr[i].dna << endl;
	}

}
