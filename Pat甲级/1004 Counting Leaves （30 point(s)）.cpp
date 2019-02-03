#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 110;
int level[MAXN];
int maxdepth = -1;
vector<vector<int>> t;
void dfs(int root, int depth) {
	if(t[root].size() == 0) {
		maxdepth = max(maxdepth, depth);
		level[depth]++;
		return;
	}
	for(int i = 0; i < t[root].size(); ++i) dfs(t[root][i], depth + 1);
}
int n, m, k, root, c;
int main() {
	scanf("%d%d", &n, &m);
	t.resize(n + 1);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &root, &k);
		for(int j = 0; j < k; ++j) {
			scanf("%d", &c);
			t[root].push_back(c);
		}
	}
	dfs(1, 1);
	for(int i = 1; i <= maxdepth; ++i) printf("%d%c", level[i], i == maxdepth ? '\n' : ' ');
	return 0;
}
