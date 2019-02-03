#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 510;
const int INF = 0x3f3f3f3f;
int w[MAXN], e[MAXN][MAXN], dis[MAXN], num[MAXN], weight[MAXN];
bool vis[MAXN];
int n, m, c1, c2;
int main() {
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i = 0; i < n; ++i) scanf("%d", &weight[i]);
	fill(e[0], e[0] + MAXN * MAXN, INF);
	fill(dis, dis + MAXN, INF);
	int a, b, c;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}
	num[c1] = 1, dis[c1] = 0, w[c1] = weight[c1];
	for(int i = 0; i < n; ++i) {
		int u = -1, minn = INF;
		for(int j = 0; j < n; ++j) if(vis[j] == false && dis[j] < minn) {
			minn = dis[j];
			u = j;
		}
		if(u == -1) break;
		vis[u] = true;
		for(int v = 0; v < n; ++v) if(vis[v] == false) {
			if(dis[v] > dis[u] + e[u][v]) {
				dis[v] = dis[u] + e[u][v];
				num[v] = num[u];
				w[v] = w[u] + weight[v];
			} else if(dis[v] == dis[u] + e[u][v]) {
				num[v] += num[u];
				if(w[v] < weight[v] + w[u]) w[v] = weight[v] + w[u];
			}
		} 
	}
	printf("%d %d", num[c2], w[c2]);
	return 0;
}
