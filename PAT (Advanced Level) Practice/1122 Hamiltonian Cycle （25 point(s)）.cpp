#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int n, m, k, nk, a, b; 
vector<vector<int>> e;
vector<int> t;
bool connect(int pre) {
	for(int i = 1; i < t.size(); ++i) {
		if(!e[pre][t[i]]) return false;
		pre = t[i];
	}
	return true;
}
bool hamilton() {
	if(t[0] != t[nk - 1]) return false;
	vector<int> cnt(nk, 0);
	for(int i = 0; i < nk; ++i) cnt[t[i]]++;
	for(int i = 1; i < nk; ++i) if(i == t[0] && cnt[i] != 2 || i != t[0] && cnt[i] != 1) return false;
	return true;
}
int main() {
	scanf("%d%d", &n, &m);
	e.resize(n + 1, vector<int>(n + 1, 0));
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &nk);
		t.resize(nk);
		for(int j = 0; j < nk; ++j) scanf("%d", &t[j]);
		printf("%s\n", (connect(t[0]) && hamilton() && nk == n + 1)? "YES" : "NO");
	}
	return 0;
}
