#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
struct node {
	double product;
	vector<int> dist;
};
double res, r, p;
int n, k;
vector<node> t;
void dfs(int u, int depth) {
	if(t[u].dist.size() == 0) {
		res += t[u].product * pow(r + 1, depth);
		return;
	}
	for(int i = 0; i < t[u].dist.size(); ++i) dfs(t[u].dist[i], depth + 1);
}
int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	t.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &k);
		if(k == 0) scanf("%lf", &t[i].product);
		t[i].dist.resize(k);
		for(int j = 0; j < k; ++j) scanf("%d", &t[i].dist[j]);
	}
	dfs(0, 0);
	printf("%.1f\n", p * res);
	return 0;
}
