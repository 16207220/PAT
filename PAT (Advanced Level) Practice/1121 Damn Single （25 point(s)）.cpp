#include<iostream>
#include<cstdio>
using namespace std;
int a[6][6];
bool vis[6][6];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
void dfs(int m, int x, int y) {
	if(m == 24) printf("YES");
	for(int i = 0; i < 4; ++i) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 1 && xx <= 5 && yy >= 1 && yy <= 5 && vis[xx][yy] == false) {
			vis[xx][yy] = true;
			dfs(xx, yy, m + 1);
			vis[xx][yy] = false;
		}
	}
}
int main() {
	vis[1][1] = true;
	for(int i = 1; i <= 5; ++i) {
		for(int j = 1; j <= 5; ++j) {
			vis[i][j] = true;
			dfs(1, i, j);
			vis[i][j] = false;
		}
	}
}
