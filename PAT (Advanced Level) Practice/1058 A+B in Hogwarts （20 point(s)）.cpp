#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	long long a, b, c, d, e, f;
	scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
	long long sum = f + c + (b + e) * 29 + (a + d) * 29 * 17;
	printf("%lld.%lld.%lld\n", sum / 17 / 29, sum / 29 % 17, sum % 29);
	return 0;
}
