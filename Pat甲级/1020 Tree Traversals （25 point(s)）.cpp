#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> post, in;
vector<vector<int> > level;
int depth;
void getLevel(int root, int l, int r, int d) {
	if(l > r) {
		depth = max(depth, d);	
		return;
	}
	int i = l;
	while(i < r && in[i] != post[root]) ++i;
	level[d].push_back(post[root]);
	getLevel(root - 1 + i - r, l, i - 1, d + 1);
	getLevel(root - 1, i + 1, r, d + 1);
}
int main() {
	int n;
	scanf("%d", &n);
	level.resize(n); in.resize(n); post.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d", &post[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &in[i]);
	getLevel(n - 1, 0, n - 1, 0);
	for(int i = 0; i < depth; ++i) {
		for(int j = 0; j < level[i].size(); ++j) {
			printf("%d%c", level[i][j], i == depth - 1 && j == level[i].size() - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
