#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 510;
int e[MAXN][MAXN], dis[MAXN], w[MAXN];
bool vis[MAXN];
vector<int> pre[MAXN], path, temppath;
int minneed = INF, minback = INF;
int cmax, n, s, m;
void dfs(int u) {
	if(u == 0) {
		int need = 0, back = 0;
		for(int i = path.size() - 1; i >= 0; --i) {
			int id = path[i];
			if(w[id] > 0) back += w[id];
			else {
				if(back > (-w[id])) back += w[id];
				else {
					need += -w[id] - back;
					back = 0;
				}
			} 
		}
		if(need < minneed || need == minneed && back < minback) {
			minneed = need;
			minback = back;
			temppath = path;
		}
		return;
	}
	path.push_back(u);
	for(int v = 0; v < pre[u].size(); ++v)	dfs(pre[u][v]);
	path.pop_back();
}
int main() {
	fill(e[0], e[0] + MAXN * MAXN, INF);
	fill(dis, dis + MAXN, INF);
	scanf("%d%d%d%d", &cmax, &n, &s, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &w[i]);
		w[i] -= cmax / 2;
	} 
	int a, b, c;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}
	dis[0] = 0;
	for(int i = 0; i <= n; ++i) {
		int u = -1, minn = INF;
		for(int j = 0; j <= n; ++j) if(vis[j] == false && dis[j] < minn) {
			u = j;
			minn = dis[j];
		}
		vis[u] = true;
		if(u == -1) break;
		for(int v = 0; v <= n; ++v) if(vis[v] == false) {
			if(dis[v] > dis[u] + e[u][v]) {
				pre[v].clear();
				pre[v].push_back(u);
				dis[v] = dis[u] + e[u][v];
			} else if(dis[v] == dis[u] + e[u][v]) {
				pre[v].push_back(u);
			}
		} 
	}
	dfs(s);
    printf("%d 0", minneed);
    for(int i = temppath.size() - 1; i >= 0; i--)
        printf("->%d", temppath[i]);
    printf(" %d", minback);
    return 0;
}
