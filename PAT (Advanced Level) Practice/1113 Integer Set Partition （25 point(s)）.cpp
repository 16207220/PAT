#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, sum, half;
int main() {
	scanf("%d", &n);
	vector<int> res(n);
	for(int i = 0; i < n; ++i) scanf("%d", &res[i]), sum += res[i];
	sort(res.begin(), res.end());
	for(int i = 0; i < n / 2; ++i) half += res[i];
	printf("%d %d\n", n % 2, sum - 2 * half);
	return 0;
} 
