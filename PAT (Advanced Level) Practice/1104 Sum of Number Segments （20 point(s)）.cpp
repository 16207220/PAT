#include<iostream>
#include<cstdio>
using namespace std;
double res, x;
int n;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lf", &x), res += x * (n - i + 1) * i;
	printf("%.2f\n", res);
	return 0;
}
