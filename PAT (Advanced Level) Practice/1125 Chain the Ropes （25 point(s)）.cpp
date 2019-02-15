#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> t;
int n, res;
int main() {
	scanf("%d", &n); t.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d", &t[i]);
	sort(t.begin(), t.end());
	res = t[0];
	for(int i = 1; i < n; ++i) res = (res + t[i]) / 2;
	printf("%d\n", res);
	return 0;
}
