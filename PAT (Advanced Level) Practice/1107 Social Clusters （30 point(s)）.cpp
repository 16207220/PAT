#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;
const int MAXN = 1e3 + 10;
vector<int> father, ran, root;
int n;
int h[MAXN];
int find(int x) {
	return x == father[x] ? x : father[x] = find(father[x]);
} 
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(ran[x] < ran[y]) father[x] = y;
	else {
		father[y] = x;
		if(ran[x] == ran[y]) ++ran[x];
	}
}
int x, k;
int main() {
	scanf("%d", &n);
	father.resize(n + 1); ran.resize(n + 1); root.resize(n + 1);
	for(int i = 1; i <= n; ++i) father[i] = i, ran[i] = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d:", &k);
		for(int j = 0; j < k; ++j) {
			scanf("%d", &x);
			if(!h[x]) h[x] = i;
			unite(i, find(h[x]));
		}
	}
	for(int i = 1; i <= n; ++i) root[find(i)]++;
	sort(root.begin(), root.end(), greater<int>());
	int cnt = 0;
	for(int i = 0; i < n; ++i) if(root[i]) ++cnt;
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; ++i) printf("%d%c", root[i], i == cnt - 1 ? '\n' : ' ');
	return 0;
}
