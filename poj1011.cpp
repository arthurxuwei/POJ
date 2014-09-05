#include <iostream>
#include <algorithm>
using namespace std;
int a[100];
bool vis[100];

int cmp(const void *a, const void *b) {
	return *(int *)b-*(int *)a;
}

int dfs(int len, int n, int stick, int ret){
	if(stick==n && ret==0)
		return len;
	if(ret==0)
		ret = len;
	int i;
	for(i=0;i<n;i++) {
		if(vis[i] == true) continue;
		if(a[i]>ret) continue;
		vis[i] = true;
		if(dfs(len, n, stick+1, ret-a[i])) return len;
		vis[i] = false;
		if(ret == a[i] || len == ret) break;
		while(a[i] == a[i+1]) ++i;
	}
	return 0;
}
main() {
	int len;
	int i,j,k;
	while(cin >> len) {
		if(len==0){
			return 0;
		}
		int max=0;
		int sum = 0;
		int tmp;
		for(int x=0; x<len;x++) {
			cin >> tmp;
			if(tmp > max) max = tmp;
			sum+=tmp;
			a[x] = tmp;
		}
		qsort(a, len, sizeof(int), cmp);
		for(i = max; i <= sum; ++i) {
			if(sum%i!=0) continue;
			for(j=0; j<len; ++j) 
				vis[j] = false;
			k = dfs(i, len, 0, i);
			if(k!=0) break;
		}
		cout << k << endl;
	}
}
