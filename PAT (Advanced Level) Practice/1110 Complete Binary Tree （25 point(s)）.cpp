#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node {
	int l, r;
};
int n, cnt, last;
vector<int> book;
vector<node> t;
string a, b;
int main() {
	scanf("%d", &n);
	t.resize(n); book.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> a >> b;
		if(a[0] == '-') t[i].l = -1;
		else {
			t[i].l = stoi(a);
			book[t[i].l] = 1;
		}
		if(b[0] == '-') t[i].r = -1;
		else {
			t[i].r = stoi(b);
			book[t[i].r] = 1;
		}
	}
	int root = find(book.begin(), book.end(), 0) - book.begin();
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(u == -1) break;
		if(u != -1) last = u;
		++cnt;
		q.push(t[u].l); q.push(t[u].r);
	}
	if(cnt == n) printf("YES %d\n", last);
	else printf("NO %d\n", root);
	return 0;
}
