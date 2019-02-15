#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<int> in, post;
vector<vector<int>> level;
void getlevel(int l, int r, int root, int depth) {
	if(l > r) return;
	int i = l;
	while(i <= r && post[root] != in[i]) ++i;
	level[depth].push_back(post[root]);
	getlevel(l, i - 1, root + i - r - 1, depth + 1);
	getlevel(i + 1, r, root - 1, depth + 1);
}
int main() {
	scanf("%d", &n);
	level.resize(n + 1); in.resize(n); post.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d", &in[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &post[i]);
	getlevel(0, n - 1, n - 1, 0);
	printf("%d", level[0][0]);
	for(int i = 1; i <= n; ++i) {
		if(i % 2) for(int j = 0; j < level[i].size(); ++j) printf(" %d", level[i][j]);
		else for(int j = level[i].size() - 1; j >= 0; --j) printf(" %d", level[i][j]);
	}
	return 0;
}
