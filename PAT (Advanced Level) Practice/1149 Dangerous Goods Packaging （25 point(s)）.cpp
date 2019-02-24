#include<iostream>
#include<vector>
#include<cstdio>
#include<unordered_map>
#include<cstring>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 1e5;
int n, m, a, b, k;
unordered_map<int, vector<int>> t; 
int res[MAXN], v[MAXM];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		t[a].push_back(b);
		t[b].push_back(a);
	}
	for(int i = 0; i < m; ++i) {
		memset(v, 0, sizeof(v));
		scanf("%d", &k);
		for(int j = 0; j < k; ++j) {
			scanf("%d", &res[j]);
			v[res[j]] = 1;
		}
		bool flag = true;
		for(int j = 0; j < k; ++j) {
			for(int l = 0; l < t[res[j]].size(); ++l) {
				if(v[t[res[j]][l]]) flag = false;
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}

