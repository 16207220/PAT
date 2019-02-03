#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> pre, post;
bool isMirror;
int n;
void getpost(int l, int r) {
	if(l > r) return;
	int i = l + 1, j = r;
	if(isMirror  == false) {
		while(i <= r && pre[i] < pre[l]) ++i;
		while(j > l && pre[j] >= pre[l]) --j;
	} else {
		while(i <= r && pre[i] >= pre[l]) ++i;
		while(j > l && pre[j] < pre[l]) --j; 
	}
	if(i - j != 1) return;
	getpost(l + 1, j);
	getpost(i, r);
	post.push_back(pre[l]);
}
int main() {
	int n;
	scanf("%d", &n);
	pre.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	getpost(0, n - 1);
	if(post.size() != n) {
		isMirror = true;
		post.clear();
		getpost(0, n - 1);
	}
	if(post.size() == n) {
		printf("Yes\n");
		for(int i = 0; i < post.size(); ++i) printf("%d%c", post[i], i == post.size() - 1 ? '\n' : ' ');
	} else printf("No\n");
	return 0;
}
