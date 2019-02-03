#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 2e2 + 10;
bool book[MAXM]; //标记那些颜色是需要的， 便于去除其它颜色
int t[MAXN], dp[MAXN], a[MAXN];
int n, m, l, num;
int main() {
	scanf("%d%d", &n, &m);
	int x;
	for(int i = 0; i < m; ++i) {
		scanf("%d", &x);
		a[x] = i;
		book[x] = true;
	}
	scanf("%d", &l);
	for(int i = 0; i < l; ++i) {
		scanf("%d", &x);
		if(book[x]) t[num++] = x;
	}
	int res = 0;
	for(int i = 0; i < num; ++i) {
		dp[i] = 1;
		for(int j = 0; j < i; ++j) if(a[t[j]] <= a[t[i]]) dp[i] = max(dp[i], dp[j] + 1);
		res = max(res, dp[i]);
	}
	printf("%d\n", res);
	return 0;
} 
