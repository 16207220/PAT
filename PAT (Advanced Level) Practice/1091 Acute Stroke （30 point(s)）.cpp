#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int MAXN = 130;
const int MAXM = 80;
#define judge(x, y, z) x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < l
int m, n, l, t;
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
int vis[MAXN * 10][MAXN][MAXM], e[MAXN * 10][MAXN][MAXM];
struct node {
	int x, y, z;
};
int bfs(node u) {
	int cnt = 0;
	queue<node> q;
	vis[u.x][u.y][u.z] = true;
	q.push(u);
	while(!q.empty()) {
		u = q.front(); q.pop();
		++cnt;
		for(int i = 0; i < 6; ++i) {
			int x = u.x + dx[i];
			int y = u.y + dy[i];
			int z = u.z + dz[i];
			if(judge(x, y, z) && e[x][y][z] == 1 && !vis[x][y][z]) {
				q.push({x, y, z});
				vis[x][y][z] = true;
			}
		}
	}
	if(cnt >= t) return cnt;
	return 0;
}
int main() {
	scanf("%d%d%d%d", &m, &n, &l, &t);
	int x, y, z;
	int res = 0;
	for(int k = 0; k < l; ++k) 
		for(int i = 0; i < m; ++i) 
			for(int j = 0; j < n; ++j) scanf("%d", &e[i][j][k]);
	for(int k = 0; k < l; ++k) 
		for(int i = 0; i < m; ++i) 
			for(int j = 0; j < n; ++j) if(vis[i][j][k] == false && e[i][j][k] == 1) res += bfs({i, j, k});
	printf("%d\n", res);
	return 0;
}
