#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define size 1005
using namespace std;
struct pix {
	int pos;
	int code;
}outmap[size*8];


int inmap[size][2];
int width, cntp, tot;

int cmp(pix x, pix y) {
	return x.pos < y.pos;
}

int getnum(int pos) {
	int p =0,i=0;
	while(p<pos)
		p+=inmap[i++][1];

	return inmap[i-1][0];
}

int getcode(int pos) {
	int num = getnum(pos), ret=0;

	int row=(pos-1)/width;
	int col=(pos-1)%width;

	for (int i = row-1; i <= row+1; ++i)
		for (int j = col-1; j <= col+1; ++j) {
			int tpos= i*width+j;
			if( i<0 || j<0 || j>=width || tpos >= tot || tpos == pos-1)
				continue;

			int tmp = getnum(tpos+1);
			if(abs(tmp-num)>ret) ret = abs(tmp-num);
		}
	return ret;
}

int main() {
	while ( cin >> width && width) {
		int num, len;
		cntp=tot=0;
		while( cin >> num >> len && num) {
			inmap[cntp][0]=num;
			inmap[cntp++][1]=len;
			tot+=len;
		}
		cout << width << endl;

		int pos=1,k=0;
		for (int p=0; p<= cntp; p++) {
			int row = (pos-1) / width;
			int col = (pos-1) % width;

			for(int i=row-1; i <= row+1; i++) {
				for(int j=col-1; j <= col+1; j++) {
					int tpos = i*width + j;
					if (i<0 || j<0 || j>=width ||tpos >= tot)
						continue;

					outmap[k].pos = tpos+1;
					outmap[k++].code = getcode(tpos+1);
				}
			}
			pos+=inmap[p][1];
		}

		sort(outmap, outmap+k, cmp);

		pix tmp=outmap[0];
		for (int i=0; i<k; ++i) {
			if (outmap[i].code == tmp.code)
				continue;

			cout << tmp.code << ' ' << outmap[i].pos-tmp.pos <<endl;
			tmp = outmap[i];
		}

		cout << tmp.code << ' ' << tot-tmp.pos+1 <<endl;
		cout << "0 0"  << endl;
	}
	cout << "0" << endl;
}
