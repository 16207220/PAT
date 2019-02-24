#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, k, a, b, nv;
vector<vector<int>> e;
int main() {
	scanf("%d%d", &n, &m);
	e.resize(n);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		e[a].push_back(i);
		e[b].push_back(i);
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &nv);
		vector<int> book(m, 0);
		for(int j = 0; j < nv; ++j) {
			scanf("%d", &a);
			for(int l = 0; l < e[a].size(); ++l) book[e[a][l]] = 1;
		}
		if(find(book.begin(), book.end(), 0) == book.end()) printf("Yes\n");
		else printf("No\n");
	} 
	return 0;
}
