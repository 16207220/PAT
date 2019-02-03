#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm> 
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 1e2 + 10;
int m, n;
int w[MAXN], dp[MAXM], choice[MAXN][MAXM];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &w[i]);
	sort(w + 1, w + 1 + n, greater<int>());
	for(int i = 1; i <= n; ++i) 
		for(int j = m; j >= w[i]; --j) if(dp[j] < dp[j - w[i]] + w[i]) {
			choice[i][j] = true;
			dp[j] = dp[j - w[i]] + w[i];
		}
	if(dp[m] != m) printf("No Solution\n");
	else {
		vector<int> res;
		int index = n, v = m;
		while(v > 0) {
			if(choice[index][v]) {
				res.push_back(w[index]);
				v -= w[index];
			}
			--index;
		}
		for(int i = 0; i < res.size(); ++i) printf("%d%c", res[i], i == res.size() - 1 ? '\n' : ' ');
	}
	return 0;
} 
