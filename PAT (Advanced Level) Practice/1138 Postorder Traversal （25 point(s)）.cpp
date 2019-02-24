#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
vector<int> pre, in, post;
void getpost(int l, int r, int root) {
	if(l > r) return;
	int i = l;
	while(i <= r && in[i] != pre[root]) ++i;
	getpost(l, i - 1, root + 1);
	getpost(i + 1, r, root + i - l + 1);
	post.push_back(pre[root]);
}
int n;
int main() {
	scanf("%d", &n);
	pre.resize(n); in.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &in[i]);
	getpost(0, n - 1, 0);
	printf("%d\n", post[0]);
	return 0;
} 
