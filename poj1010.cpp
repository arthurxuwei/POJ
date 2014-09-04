#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int size = 26;

int value[size];
int pv;
int times[size];

bool flag;
bool flag_tie;
int solve[6];
int BestSolve[6];

void dfs(int need, int num, int type, int pre);
int max4(int* s);
void best(int num, int type);

main (){
	while(true) {
		pv=0;
		int type[size]={0};

		int tmp;
		while(true) {
			cin >> tmp;
			if(cin.eof())
				return 0;
			if(tmp==0) break;

			if(type[tmp] < 5) {
				type[tmp]++;
				value[pv++]=tmp;
			}
		}
		sort(value, value+pv);
		int need;
		while(cin>>need && need) {
			flag = false;
			flag_tie = false;
			memset(solve, 0, sizeof(solve));
			memset(BestSolve, 0, sizeof(BestSolve));
			memset(times, 0, sizeof(times));

			dfs(need, 0, 0, 0);

			cout << need;
			if(BestSolve[0] == 0)
				cout <<" ---- none" << endl;
			else {
				cout << " (" << BestSolve[5] << "):";
				if(flag_tie)
					cout << " tie" << endl;
				else {
					sort(BestSolve+1, BestSolve+5);
					for(int i=1; i<=4; i++) {
						if(BestSolve[i] == 0) continue;
						cout<< ' ' << BestSolve[i];
					}
					cout << endl;
				}
			}
		}
	}
}

void dfs(int need, int num, int type, int pre) {
	if( num == 5) return;
	if( need == 0 ) {
		if( !flag ) {
			if(type == BestSolve[5]) {
				if(num == BestSolve[0]) {
					int Maxs = max4(solve);
					int MaxBs = max4(BestSolve);
					if(Maxs == MaxBs)
						flag_tie = true;
					else if( Maxs>MaxBs ) {
						flag_tie = false;
						best(num, type);
					}
				} else if( num < BestSolve[0] ) {
					flag_tie = false;
					best(num, type);
				}
			} else if (type > BestSolve[5]) {
				flag_tie = false;
				best(num, type);
			}
		} else {
			flag = true;
			best(num, type);
		}
		return;
	}
	for(int i=pre; i<pv; i++) {
		if(need>=value[i]) {
			solve[num+1] = value[i];

			if(times[i]!=0) {
				times[i]++;
				dfs(need-value[i], num+1, type, i);
			} else {
				times[i]++;
				dfs(need-value[i], num+1, type+1, i);
			}

			solve[num+1] = 0;
			times[i]--;
		} else return;
	}
	return;
}

int max4(int* s) {
	int a = s[1] > s[2] ? s[1]:s[2];
	int b = s[3] > s[4] ? s[3]:s[4];
}

void best(int num, int type) {
	BestSolve[0] = num;
	BestSolve[5] = type;
	for(int k=1; k<=4; k++) BestSolve[k] = solve[k];
}
