#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
int e[MAXN][MAXN];
bool vis[MAXN];
int n, m, k;
void dfs(int u) {
	vis[u] = true;
	for(int v = 1; v <= n; ++v) if(vis[v] == false && e[u][v]) dfs(v);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int a, b;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
	} 
	int cnt, city;
	for(int i = 0; i < k; ++i) {
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &city);
		vis[city] = true;
		for(int u = 1; u <= n; ++u) if(vis[u] == false) dfs(u), cnt++;
		printf("%d\n", cnt - 1);
	}
	return 0;
}
