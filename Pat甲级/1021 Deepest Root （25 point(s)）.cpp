#include<iostream>
#include<vector>
#include<cstdio>
#include<set>  
#include<cstring>
using namespace std;
const int MAXN = 1e4 + 10;
vector<int> t;
bool vis[MAXN];
vector<vector<int>> e;
set<int> res;
int n, k; 
int deepest;
void dfs(int deep, int u) {
	if(deep > deepest) {
		deepest = deep;
		t.clear();
		t.push_back(u);
	} else if(deepest == deep) {
		t.push_back(u);
	}
	vis[u] = true;
	for(int v = 0; v < e[u].size(); ++v) if(vis[e[u][v]] == false) dfs(deep + 1, e[u][v]);
}
int main() {
	scanf("%d", &n);
	e.resize(n + 1);
	int a, b;
	for(int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b); e[b].push_back(a);
	}
	int s = 0;
	for(int i = 1; i <= n; ++i) {
		if(vis[i] == false) {
			dfs(1, i);
			if(i == 1) {
				for(int j = 0; j < t.size(); ++j) {
					res.insert(t[j]);
					s = t[j];
				}	
			}
			++k;
		}
	}
	if(k >= 2) printf("Error: %d components", k);
	else {
		t.clear();
		memset(vis, 0, sizeof(vis));
		dfs(1, s);
		for(int i = 0; i < t.size(); ++i) res.insert(t[i]);
		for(set<int>::iterator it = res.begin(); it != res.end(); ++it)	printf("%d\n", *it);
	}
	return 0;
}
