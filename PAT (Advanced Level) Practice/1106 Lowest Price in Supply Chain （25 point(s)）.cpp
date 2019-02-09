#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
int mindepth = INF, maxnum;
int n, k;
double p, r;
vector<vector<int>> e;
void dfs(int u, int depth) {
	if(e[u].size() == 0) {
		if(mindepth > depth) {
			mindepth = depth;
			maxnum = 0;
		}
		if(mindepth == depth) ++maxnum; 
	}
	for(int v = 0; v < e[u].size(); ++v) dfs(e[u][v], depth + 1);
}
int main() {
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	e.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &k);
		e[i].resize(k);
		for(int j = 0; j < k; ++j) scanf("%d", &e[i][j]);
	}
	dfs(0, 0);
	printf("%0.4f %d\n", p * pow(r + 1, mindepth), maxnum - 1);
	return 0;
}
