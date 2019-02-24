#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
const int MAXN = 1e4 + 10;
typedef pair<int, int> P;
vector<P> e;
int n, m, k, a, b;
int color[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e.push_back(P(a, b));
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		bool flag = true;
		set<int> s;
		for(int j = 0; j < n; ++j) {
			scanf("%d", &color[j]);
			s.insert(color[j]);
		}
		for(int j = 0; j < m; ++j) if(color[e[j].first] == color[e[j].second]) flag = false;
		if(flag) printf("%d-coloring\n", s.size());
		else printf("No\n");
	}
	return 0;
} 
