#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1e4 + 10;
int father[MAXN], book[MAXN], cnt[MAXN];
int find(int x) {
	return x == father[x] ? x : father[x] = find(father[x]);
} 
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;
	father[x] = y;
}
int n, k, x, y, q;
int main() {
	for(int i = 0; i < MAXN; ++i) father[i] = i;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &k, &x); 
		book[x] = 1;
		for(int j = 0; j < k - 1; ++j) {
			scanf("%d", &y);
			unite(x, y);
			book[y] = 1;
		}
	}
	for(int i = 0; i < MAXN; ++i) if(book[i]) {
		x = find(i);
		cnt[x]++;
	}
	int numt = 0, numb = 0;
	for(int i = 0; i < MAXN; ++i) if(book[i] && cnt[i]) {
		numt++;
		numb += cnt[i];
	}
	printf("%d %d\n", numt, numb);
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		scanf("%d%d", &x, &y);
		printf("%s\n", find(x) == find(y) ? "Yes" : "No");
	}
	return 0;
}
