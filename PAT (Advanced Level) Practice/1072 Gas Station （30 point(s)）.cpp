#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3 + 20;
const int INF = 0x3f3f3f3f;
int e[MAXN][MAXN], dis[MAXN];
bool vis[MAXN];
int n, m, k, ds;
int a, b, c;
string aa, bb;
int main() {
	fill(e[0], e[0] + MAXN * MAXN, INF);
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for(int i = 0; i < k; ++i) {
		cin >> aa >> bb;
		if(aa[0] == 'G') {
			aa = aa.substr(1);
			a = n + stoi(aa);
		} else a = stoi(aa);
		if(bb[0] == 'G') {
			bb = bb.substr(1);
			b = n + stoi(bb);
		} else b = stoi(bb);
		scanf("%d", &c);
		e[a][b] = e[b][a] = c;
	}
	int ansid = -1;
	double ansdis = -1, ansavg = INF;
	for(int index = n + 1; index <= n + m; ++index) {
		fill(vis, vis + MAXN, false);
		fill(dis, dis + MAXN, INF);
		dis[index] = 0;
		double mindis = INF, minavg = 0;
		for(int i = 0; i < n + m; ++i) {
			int u = -1, minn = INF;
			for(int j = 1; j <= n + m; ++j) if(vis[j] == false && dis[j] < minn) {
				minn = dis[j];
				u = j;
			}
			if(u == -1) break;
			vis[u] = true;
			for(int v = 1; v <= n + m; ++v) if(vis[v] == false && dis[v] > dis[u] + e[u][v]) dis[v] = dis[u] + e[u][v];
		}
		for(int i = 1; i <= n; ++i) {
			if(dis[i] > ds) mindis = -1;
			else if(dis[i] < mindis) mindis = dis[i];
			minavg += dis[i];
		}
		if(mindis == -1) continue;
		minavg /= n;
		if(mindis > ansdis) {
			ansdis = mindis;
			ansid = index;
			ansavg = minavg;
		} else if(mindis == ansdis && minavg < ansavg) {
			ansid = index;
			ansavg = minavg;
		}
	}
	if(ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansavg);
}
