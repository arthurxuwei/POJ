#include <iostream>
using namespace std;

int main() {
	int p,e,t,d;
	int t1, t2, t3;
	int n = 0;
	while(cin >> p >> e >> t >> d) {
		n++;
		if (p == -1) break;
		int find = 0;	
		for(int i = 0; i<924; ++i){
			if (find) break;
			t1 = 23 *(i+1) + p;
			if(t1 >=21252) {
				t1 = 21252;
			}
			
			for(int i = 0; i<759; ++i){
				if (find) break;
				t2 = 28 *(i+1) + e;
				if(t2 >=21252) {
					t2 = 21252;
				}
				for(int i=0; i<644; ++i){
					if (find) break;
					t3 = 33 * (i+1) + t;
					if(t3 >=21252) {
						t3 = 21252;
					}

					if(t1 == t2 && t2 == t3 && t1 >= d) {
						find = 1;
						cout << "Case " << n << ": the next triple peak occurs in " << t1 - d << " days." << endl;
					} 
				}
			}	
		}
	}
	
	
}
