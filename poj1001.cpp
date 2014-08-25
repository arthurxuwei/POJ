#include <iostream>
#include <cstring>

using namespace std;
#define INSIZE 6
#define OSIZE 1000

char a[INSIZE+1];
char res[OSIZE+1];
char b[5];
char temp[OSIZE+1];

void multi(int n) {
	int p=0;
	for(int i=0,j=0; i<INSIZE; i++){
		if(a[i] == '.') { p = INSIZE - i;}
		else {b[5-j-1] = a[i]; j++;}
	}
	p = (p-1) * n;
	//cout << "p: " << p << endl;
	//multi
	for(int k=0; k<n;k++){	
		int i = 0;
		int overflow = 0;
		memcpy(&temp, &res, OSIZE+1);
		if(k==0) {temp[0]='1';}
		while(temp[i] != '\0') {
			if(i==0) {
				memset(&res, '\0', OSIZE+1);
			}
			int j;
			for(j = 0; j < 5; j++) {
				int t = (temp[i] - '0') * (b[j] - '0') + overflow;
				overflow = t/10;
				if(res[i+j]=='\0')res[i+j]='0';
				int t2 = (res[i+j] - '0') + t%10;
				overflow += t2/10;
				res[i+j] = (char)((int)'0' + t2%10 );
			}
			if(overflow>0) {res[i+j] = (char)((int)'0'+overflow);} 
			//cout << "#i" << i << ": res- " << res << " temp- " << temp << endl;
			i++;overflow=0;
		}
		//cout << "#k" << k << ": " << res << endl;
	}

	//insert a dot
	int len=0;
	while(res[++len] != '\0') {
		
	}
	for(int i=0; len - i > p; ++i){
		res[len-i] = res[len-i-1];	
	}
	res[p] = '.';
	//cout << "res: " << res << endl;
	if(res[len] == '0'){
		res[len] == '\0';
		len--;
	}


	//reverse res array
	len++;
	//cout << "len: " << len << endl;

	int i = 0;
	while (i < len/2){
		char t = res[i];
		res[i] = res[len-i-1];
		res[len-i-1] = t;
		i++;
	}
	//remove '0'
	int l = len-1;
	while(res[l] == '0'){
		res[l] = '\0';
	}
}



int main (int argc, char** argv) {
	int n;
	
	while(cin>>a>>n) {
		memset(res, '\0', sizeof(res));
		multi(n);
		cout << res << endl;
	}

	return 0;
}
