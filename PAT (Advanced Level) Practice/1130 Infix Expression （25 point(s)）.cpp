#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector> 
using namespace std;
const int MAXN = 22;
int root,  n; 
struct node {
	int l, r;
	string v;
};
vector<node> res;
int book[MAXN];
string getin(int u) {
	if(u == -1) return "";
	if(res[u].l != -1 || res[u].r != -1) {
		res[u].v = getin(res[u].l) + res[u].v + getin(res[u].r);
		if(u != root) res[u].v = "(" + res[u].v + ")";
	}
	return res[u].v;
}
int main() {
	cin >> n;
	res.resize(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> res[i].v >> res[i].l >> res[i].r;
		if(res[i].l != -1) book[res[i].l] = 1;
		if(res[i].r != -1) book[res[i].r] = 1;
	}
	root = find(book + 1, book + n + 1, 0) - book;
	cout << getin(root) << '\n';
	return 0;
}
