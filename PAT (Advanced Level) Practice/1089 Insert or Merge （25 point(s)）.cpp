#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1e3 + 10;
int a[MAXN], b[MAXN], t[MAXN];
int n;
bool isInsert() {
	memcpy(t, a, sizeof(a));
	for(int i = 2; i <= n; ++i) { //注意第一遍插入排序是两个元素。 
		sort(t, t + i);
		if(equal(t, t + n, b)) {
			sort(t, t + i + 1); return true;
		}
	}
	return false;
} 
bool isMerge() {
	memcpy(t, a, sizeof(a));
	for(int step = 2; step < n; step *= 2) {
		for(int i = 0; i < n; i += step) {
			sort(t + i, i + step < n ? t + i + step : t + n);
		}
		if(equal(t, t + n, b)) {
			for(int i = 0; i < n; i += step * 2) {
				sort(t + i, i + 2 * step < n ? t + i + step * 2 : t + n); 
			}
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &b[i]);
	if(isInsert()) {
		printf("Insertion Sort\n");
	} else if(isMerge()){
		printf("Merge Sort\n");
	}
	for(int i = 0; i < n; ++i) printf("%d%c", t[i], i == n - 1 ? '\n' : ' ');
	return 0;
}
