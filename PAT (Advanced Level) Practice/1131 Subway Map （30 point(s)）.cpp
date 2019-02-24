#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 1e4;
const int INF = 0x3f3f3f3f; 
vector<int> e[MAXN], line[MAXN];
int preLine[MAXN], pre[MAXN], dis[MAXN], cnt[MAXN], vis[MAXN];
int n, m, k, a, b;
void solve(int s, int t) {
	fill(dis, dis + MAXN, INF);
	fill(cnt, cnt + MAXN, INF);
	fill(vis, vis + MAXN, false);
	dis[s] = 0;
	cnt[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for(int i = 0; i < e[u].size(); ++i) {
			int v = e[u][i], l = line[u][i];
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				pre[v] = u;
				preLine[v] = l;
				cnt[v] = cnt[u];
				if(preLine[u] != l) ++cnt[v];
				if(!vis[v]) {
					q.push(v); 
					vis[v] = true;
				}
			} else if(dis[v] == dis[u] + 1) {
				int d = cnt[u];
				if(preLine[u] != l) ++d;
				if(d <= cnt[v]) {
					pre[v] = u;
					preLine[v] = l;
					cnt[v] = d;
					if(!vis[v]) {
						q.push(v); 
						vis[v] = true;
					}
				}
			}
		}
	}
	printf("%d %d\n", dis[t], cnt[t]);
	int curLine = preLine[t], cur = t;
	for(int i = t; i != s; i = pre[i]) {
		if(preLine[i] != curLine) {
			printf("Take Line#%d from %04d to %04d.\n", curLine, cur, i);
			curLine = preLine[i];
			cur = i;
		}
	}
	printf("Take Line#%d from %04d to %04d.\n", curLine, cur, s);
}
int s, t;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d", &m, &a);
		for(int j = 1; j < m; ++j) {
			scanf("%d", &b);
			e[a].push_back(b); e[b].push_back(a);
			line[a].push_back(i); line[b].push_back(i); 
			a = b;
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d%d", &s, &t);
		solve(t, s);
	}
	return 0;
}
/*
2
4 1 4 3 5
3 1 2 3
10
5 1
*/
