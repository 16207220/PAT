#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int MAXN = 510;
bool vis[MAXN];
vector<vector<int>> e; 
int n, even, cnt, a, b, m;
void bfs() {
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		cnt++;
		for(int v = 0; v < e[u].size(); ++v) if(!vis[e[u][v]]) {
			q.push(e[u][v]);
			vis[e[u][v]] = true;
		}
	} 
}
int main() {
	scanf("%d%d", &n, &m);
	e.resize(n + 1); 
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d%c", e[i].size(), i == n ? '\n' : ' ');
		if(e[i].size() % 2 == 0) ++even;
	}
	bfs();
	if(cnt == n && even == n) printf("Eulerian\n");
	else if(cnt == n && even == n - 2) printf("Semi-Eulerian\n");
	else printf("Non-Eulerian\n");
	return 0;
}
