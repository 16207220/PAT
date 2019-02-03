#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1010;
int a[MAXN];
bool isPalin(int* a, int len) {
	for(int i = 0; i < len / 2; ++i) if(a[i] != a[len - 1 - i]) return false;
	return true;
}
int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	int len = 0;
	do {
		a[len++] = n % b;
		n /= b;
	}while(n);
	if(isPalin(a, len)) printf("Yes\n");
	else printf("No\n");
	reverse(a, a + len);
	for(int i = 0; i < len; ++i) printf("%d%c", a[i], i == len - 1 ? '\n' : ' ');
	return 0;
}
