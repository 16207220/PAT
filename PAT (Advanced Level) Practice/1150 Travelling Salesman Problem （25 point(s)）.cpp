#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int MAXN = 210;
const int INF = 0x3f3f3f3f;
int e[MAXN][MAXN], v[MAXN];
int n, m, k, a, b, c, cnt;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		e[a][b] = e[b][a] = c;
	}
	scanf("%d", &k);
	int ansid = 0, mindis = INF;
	for(int l = 1; l <= k; ++l) {
		scanf("%d", &cnt);
		set<int> s;
		for(int i = 0; i < cnt; ++i) {
			scanf("%d", &v[i]);
			s.insert(v[i]);
		}
		bool flag = false;
		int dis = 0;
		for(int i = 0; i < cnt - 1; ++i) {
			if(!e[v[i]][v[i + 1]]) flag = true;
			dis += e[v[i]][v[i + 1]];
		}
		if(flag) printf("Path %d: NA (Not a TS cycle)\n", l);
		else if(v[0] != v[cnt - 1] || s.size() != n) printf("Path %d: %d (Not a TS cycle)\n", l, dis);
		else if(cnt != n + 1) {
			printf("Path %d: %d (TS cycle)\n", l, dis);
			if(dis < mindis) {
				ansid = l;
				mindis = dis;
			}
		} else {
			printf("Path %d: %d (TS simple cycle)\n", l, dis);
			if(dis < mindis) {
				mindis = dis;
				ansid = l;
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", ansid, mindis);
	return 0;
}
