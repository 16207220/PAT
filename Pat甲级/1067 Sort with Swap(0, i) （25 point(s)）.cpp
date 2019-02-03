#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN];
int n, x;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		a[x] = i; // xµÄÎ»ÖÃ. 
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] != i) {
			while(a[0] != 0) {
				swap(a[0], a[a[0]]);
				++cnt;
			}
			if(a[i] != i) {
				swap(a[0], a[i]);
				++cnt; 
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
