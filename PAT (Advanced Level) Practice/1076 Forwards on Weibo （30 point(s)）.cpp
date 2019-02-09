#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 1e3 + 10;
struct node {
	int level, id;
};
bool vis[MAXN];
vector<vector<int>> res;
int L, n, k, x, m;
int bfs(node u) {
	memset(vis, 0, sizeof(vis));
	vis[u.id] = true;
	queue<node> q;
	q.push(u);
	int ret = 0;
	while(!q.empty()) {
		u = q.front(); q.pop();
		for(int i = 0; i < res[u.id].size(); ++i) if(vis[res[u.id][i]] ==false && u.level < L) {
			q.push({u.level + 1, res[u.id][i]});
			vis[res[u.id][i]] = true;
			++ret;
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &L);
	res.resize(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &m);
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &x);
			res[x].push_back(i);
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &x);
		printf("%d\n", bfs({0, x}));
	}
	return 0;
}
