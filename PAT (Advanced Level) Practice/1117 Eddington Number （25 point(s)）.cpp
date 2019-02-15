#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	vector<int> res(n + 1);
	for(int i = 1; i <= n; ++i) scanf("%d", &res[i]);
	sort(res.begin() + 1, res.end(), greater<int>());
	int p = 1;
	while(p <= n && res[p] > p) ++p;
	printf("%d\n", p - 1);
	return 0;
} 
