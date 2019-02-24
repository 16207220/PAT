#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e3 + 10;
int a[MAXN];
int k, n;
int main() {
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &n);
		bool flag = true;
		for(int j = 0; j < n; ++j) {
			scanf("%d", &a[j]);
			for(int l = 0; l < j; ++l) if(!flag || a[l] == a[j] || j - l == abs(a[j] - a[l])) {
				flag = false;
				break;
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}
