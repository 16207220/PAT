#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
unordered_map<int, int> pos;
vector<int> in, pre;
int n, m;
void lca(int l, int r, int root, int u, int v) {
	int uin = pos[u], vin = pos[v], rootin = pos[pre[root]];
	if(uin < rootin && vin < rootin) {
		lca(l, rootin - 1, root + 1, u, v);
	} else if(uin > rootin && vin > rootin) {
		lca(rootin + 1, r, root + rootin - l + 1, u, v);
	} else if(uin < rootin && vin > rootin || uin > rootin && vin < rootin) {
		printf("LCA of %d and %d is %d.\n", u, v, pre[root]);
	} else if(uin == rootin || vin == rootin) {
		printf("%d is an ancestor of %d.\n", uin == rootin ? u : v, uin == rootin ? v : u);
	}
}
int main() {
	scanf("%d%d", &m, &n);
	pre.resize(n + 1); in.resize(n + 1);
	for(int i = 1; i <= n; ++i) scanf("%d", &in[i]), pos[in[i]] = i;
	for(int i = 1; i <= n; ++i) scanf("%d", &pre[i]);
	for(int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(!pos[u] && !pos[v]) printf("ERROR: %d and %d are not found.\n", u, v);
		else if(!pos[u] || !pos[v]) printf("ERROR: %d is not found.\n", !pos[u] ? u : v);
		else lca(1, n, 1, u, v);
	}
	return 0;
}
