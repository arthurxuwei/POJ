#include <iostream>
using namespace std;


int main() {
	int p,e,t,d;
	int n=0,j =0;
	while(cin >> p >> e >> t >> d) {
		if(p == -1 && e == -1 &&t== -1 && d==-1) break;
		n=0;
		j++;
		while(true) {
			n++;
			if((d+n-p)%23==0 && (d+n-e)%28==0 && (d+n-t)%33==0)
				break;
		}
		cout <<"Case " <<j << ": the next triple peak occurs in "<<n<<" days."<<endl;
	}
	return 0;
	
	
}
