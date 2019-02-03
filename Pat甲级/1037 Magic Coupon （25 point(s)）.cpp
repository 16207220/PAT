#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n, m;
int main() {
	scanf("%d", &n);
	vector<int> u(n);
	for(int i = 0; i < n; ++i) scanf("%d", &u[i]);
	scanf("%d", &m);
	vector<int> v(m);
	for(int i = 0; i < m; ++i) scanf("%d", &v[i]);
	sort(u.begin(), u.end());
	sort(v.begin(), v.end());
	int p = 0, q = 0, res = 0;
	while(p < n && q < m && u[p] < 0 && v[q] < 0) {
		res += u[p] * v[q];
		++p, ++q;
	} 
	p = n - 1, q = m - 1;
	while(p >= 0 && q >= 0 && u[p] > 0 && v[q] > 0) {
		res += u[p] * v[q];
		--p;
		--q;
	}
	printf("%d\n", res);
	return 0;
}
