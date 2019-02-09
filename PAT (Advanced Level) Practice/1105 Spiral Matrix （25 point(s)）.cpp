#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm> 
using namespace std;
int n, m, N;
vector<int> t;
int main() {
	scanf("%d", &N);
	t.resize(N);
	for(int i = 0; i < N; ++i) scanf("%d", &t[i]);
	n = sqrt(N);
	while(N % n) --n;
	m = N / n;
	int tot = 0, x, y;
	sort(t.begin(), t.end(), greater<int>());
	vector<vector<int>> res(m, vector<int>(n, -1));
	res[x = 0][y = 0] = t[tot];
	while(tot + 1 < N) {
		 while(y + 1 < n && res[x][y + 1] == -1) res[x][++y] = t[++tot];
		 while(x + 1 < m && res[x + 1][y] == -1) res[++x][y] = t[++tot];
		 while(y > 0 && res[x][y - 1] == -1) res[x][--y] = t[++tot];
		 while(x > 0 && res[x - 1][y] == -1) res[--x][y] = t[++tot]; 
	}
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) printf("%d%c", res[i][j], j == n - 1 ? '\n' : ' ');
	}
	return 0;
}
