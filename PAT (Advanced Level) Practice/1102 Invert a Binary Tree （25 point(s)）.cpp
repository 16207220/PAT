#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> book, in, level;
struct node {
	int l, r;
};
vector<node> t;
void getin(int u) {
	if(u == -1) return;
	getin(t[u].l);
	in.push_back(u);
	getin(t[u].r);
} 
int n;
char a, b;
int main() {
	scanf("%d", &n);
	t.resize(n); book.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%*c%c %c", &a, &b);
		t[i].r = (a == '-' ? -1 : a - '0');
		t[i].l = (b == '-' ? -1 : b - '0');
		if(t[i].l != -1) book[t[i].l] = 1;
		if(t[i].r != -1) book[t[i].r] = 1;
	}
	int root;
	for(int i = 0; i < n; ++i) if(!book[i]) {
		root = i;
		break;
	}
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		level.push_back(u);
		if(t[u].l != -1) q.push(t[u].l);
		if(t[u].r != -1) q.push(t[u].r);
	}
	for(int i = 0; i < n; ++i) printf("%d%c", level[i], i == n - 1 ? '\n' : ' ');
	getin(root);
	for(int i = 0; i < n; ++i) printf("%d%c", in[i], i == n - 1 ? '\n' : ' ');
	return 0;
}
