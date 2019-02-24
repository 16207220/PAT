#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 1e3 + 10;
vector<int> e[MAXN];
int in[MAXN], t[MAXN];
int n, m, a, b, k;
bool space;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		in[b]++;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		bool flag = true;
		memcpy(t, in, sizeof(in));
		for(int j = 0; j < n; ++j) {
			scanf("%d", &a);
			if(t[a]) flag = false;
			for(int l = 0; l < e[a].size(); ++l) --t[e[a][l]]; 
		} 
		if(flag) continue;
		if(space) printf(" ");
		printf("%d", i);
		space = true;
	}
	return 0;
} 
