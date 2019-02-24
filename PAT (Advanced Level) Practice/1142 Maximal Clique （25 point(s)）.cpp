#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 210;
int e[MAXN][MAXN];
int nv, ne, m, k, a, b;
int have[MAXN], v[MAXN];
int main() {
	scanf("%d%d", &nv, &ne);
	for(int i = 0; i < ne; ++i) {
		scanf("%d%d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d", &k);
		memset(have, 0, sizeof(have));
		for(int j = 0; j < k; ++j) {
			scanf("%d", &v[j]);
			have[v[j]] = 1;
		}
		bool maximal = true, clique = true;
		for(int j = 0; j < k; ++j) {
			for(int l = j + 1; l < k; ++l) if(!e[v[j]][v[l]]) {
				clique = false;
				break;
			}
		}
		if(!clique) {
			printf("Not a Clique\n");
			continue;
		}
		for(int j = 1; j <= nv && maximal; ++j) {
			if(have[j]) continue;
			for(int l = 0; l < k; ++l) {
				if(!e[v[l]][j]) break;
				else if(l == k - 1) {
					maximal = false;
					break;
				} 
			} 
		}
		printf("%s\n", maximal ? "Yes" : "Not Maximal");
	}
	return 0;
}
