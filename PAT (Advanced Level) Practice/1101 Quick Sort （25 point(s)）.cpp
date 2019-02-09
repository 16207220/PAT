#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000000;
int n, cnt;
int t[MAXN], a[MAXN], b[MAXN];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(a, a + n);
	int maxn = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] == b[i] && a[i] > maxn) {
			t[cnt++] = a[i];
		}
		if(b[i] > maxn) maxn = b[i]; //获取左边最大数. 
	} 
	printf("%d\n", cnt);
	for(int i = 0; i < cnt; i ++) {
		if(i) printf(" ");
		printf("%d", t[i]);
	}
	printf("\n");
	return 0;
}
