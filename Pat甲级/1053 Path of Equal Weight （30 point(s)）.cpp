#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int w;
	vector<int> child;
}; 
vector<node> t;
vector<int> path;
int n, m, s;
void dfs(int sum, int u, int num) {
	if(sum > s) return;
	if(sum == s) {
		if(t[u].child.size()) return;
		for(int i = 0; i < num; ++i)  printf("%d%c", t[path[i]].w, i == num - 1 ? '\n' : ' ');
	}
	for(int i = 0; i < t[u].child.size(); ++i) {
		int root = t[u].child[i];
		path[num] = root;
		dfs(sum + t[root].w, root, num + 1);
	}
}
bool cmp(int a, int b) {
	return t[a].w > t[b].w;
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	t.resize(n), path.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d", &t[i].w);
	for(int i = 0; i < m; ++i) {
		int root, k;
		scanf("%d%d", &root, &k);
		t[root].child.resize(k);
		for(int j = 0; j < k; ++j) scanf("%d", &t[root].child[j]);
		sort(t[root].child.begin(), t[root].child.end(), cmp);
	}
	dfs(t[0].w, 0, 1);
	return 0;
}
