#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
vector<int> pre, in, post;
void getpost(int root, int l, int r) {
	if(l > r) return;
	int i = l;
	while(pre[root] != in[i]) ++i;
	getpost(root + 1, l, i - 1);
	getpost(root + i - l + 1, i + 1, r);
	post.push_back(pre[root]);
}
int n, x;
stack<int> s;
string op;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < 2 * n; ++i) {
		cin >> op;
		if(op.length() == 4) {
			scanf("%d", &x);
			pre.push_back(x);
			s.push(x);
		}
		else {
			in.push_back(s.top());
			s.pop();
		}
	}
	getpost(0, 0, n - 1);
	for(int i = 0; i < n; ++i) printf("%d%c", post[i], i == n - 1 ? '\n' : ' ');
	return 0;
}
