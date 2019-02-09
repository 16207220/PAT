#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> res;
int main() {
	int n;
	ll p;
	scanf("%ld%lld", &n, &p);
	res.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d", &res[i]);
	sort(res.begin(), res.end());
	int step = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i + step; j < n; ++j) {
			if(res[i] * p >= res[j]) {
				step = max(step, j - i + 1);
			} else break;
		}
	}
	printf("%lld\n", step);
	return 0;
}
