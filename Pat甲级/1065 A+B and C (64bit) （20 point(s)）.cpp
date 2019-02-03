#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main() {
	ll a, b, c;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld%lld%lld", &a, &b, &c);
		printf("Case #%d: %s\n", i + 1, c - a < b ? "true" : "false");
	}
	return 0;
} 
