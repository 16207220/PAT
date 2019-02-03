#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 510;
const int INF = 0x3f3f3f3f;
int e[MAXN][MAXN], dis[MAXN], cost[MAXN][MAXN];
bool vis[MAXN];
vector<vector<int>> pre;
vector<int> path, temppath;
int mincost = INF;
int n, m, s, d;
void dfs(int u) {
	if(u == s) {
		path.push_back(u);
		int tempcost = 0;
		for(int i = path.size() - 1; i >= 1; --i) {
			int id = path[i], nextid = path[i - 1];
			tempcost += cost[id][nextid];
		}
		if(tempcost < mincost) {
			temppath = path;
			mincost = tempcost;
		}
		path.pop_back();
	}
	path.push_back(u);
	for(int v = 0; v < pre[u].size(); ++v) dfs(pre[u][v]);
	path.pop_back();
}
int main() {
	fill(dis, dis + MAXN, INF);
	fill(e[0], e[0] + MAXN * MAXN, INF);
	scanf("%d%d%d%d", &n, &m, &s, &d);
	int a, b, c, t;
	pre.resize(n);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &t);
		e[a][b] = e[b][a] = c;
		cost[a][b] = cost[b][a] = t;
	}
	dis[s] = 0;
	for(int i = 0; i < n; ++i) {
		int u = -1, minn = INF;
		for(int j = 0; j < n; ++j) if(vis[j] == false && dis[j] < minn) {
			u = j;
			minn = dis[j];
		}
		if(u == -1) break;
		vis[u] = true;
		for(int v = 0; v < n; ++v) if(vis[v] == false) {
			if(dis[v] > dis[u] + e[u][v]) {
				dis[v] = dis[u] + e[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			} else if(dis[v] == dis[u] + e[u][v]) {
				pre[v].push_back(u);
			}
		}
	}
	dfs(d);
	for(int i = temppath.size() - 1; i >= 0; --i) printf("%d ", temppath[i]);
	printf("%d %d", dis[d], mincost);
	return 0;
}
