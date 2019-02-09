#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int v;
	int l, r;
};
vector<node> t;
vector<int> v;
int index, n;
void build(int u) {
	if(u == -1) return;
	build(t[u].l);
	t[u].v = v[index++];
	build(t[u].r);
} 
int main() {
	scanf("%d", &n);
	t.resize(n); v.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d%d", &t[i].l, &t[i].r);
	for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	build(0);
	printf("%d", t[0].v);
	queue<int> q;
	q.push(0); 
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(u) printf(" %d", t[u].v);
		if(t[u].l != -1) q.push(t[u].l);
		if(t[u].r != -1) q.push(t[u].r);
	}
	return 0;
}
