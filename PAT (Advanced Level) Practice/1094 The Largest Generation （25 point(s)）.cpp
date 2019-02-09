#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 100 + 10;
int level[MAXN];
vector<vector<int>> e;
int n, m, k, x;
void dfs(int u, int depth) {
	level[depth]++;
	for(int v = 0; v < e[u].size(); ++v) dfs(e[u][v], depth + 1);
}
int main() {
	scanf("%d%d", &n, &m);
	e.resize(n + 1);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &x, &k);
		e[x].resize(k);
		for(int j = 0; j < k; ++j) scanf("%d", &e[x][j]);
	}
	dfs(1, 1);
	int maxnum = 0, maxlevel = 0;
	for(int i = 1; i <= n; ++i) if(level[i] > maxnum) {
		maxlevel = i;
		maxnum = level[i];
	}
	printf("%d %d", maxnum, maxlevel);
	return 0;
}
