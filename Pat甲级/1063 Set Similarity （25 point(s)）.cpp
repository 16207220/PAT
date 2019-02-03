#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
using namespace std;
vector<set<int>> res;
int nc, nt, n, m, k;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		set<int> t;
		int x;
		scanf("%d", &m);
		for(int j = 0; j < m; ++j) {
			scanf("%d", &x);
			t.insert(x);
		}
		res.push_back(t);
	}
	scanf("%d", &k);
	int a, b;
	for(int i = 0; i < k; ++i) {
		scanf("%d%d", &a, &b);
		nc = 0, nt = res[b - 1].size();
		for(set<int>::iterator it = res[a - 1].begin(); it != res[a - 1].end(); ++it) {
			if(res[b - 1].count(*it)) ++nc;
			else ++nt;
		}
		printf("%.1f%%\n", nc * 1.0 / nt * 100);
	}
	return 0;
} 
