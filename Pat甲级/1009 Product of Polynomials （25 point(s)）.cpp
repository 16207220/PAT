#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1000010;
const int MAXM = 1001;
#define EPS 1e-6
float result[MAXN], ans[MAXM];
int cnt, k, n;
float a;
int main() {
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d%f", &n, &a);
		ans[n] = a;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d%f", &n, &a);
		for(int j = 0; j < MAXM; ++j) result[j + n] += ans[j] * a;
	}
	int cnt = 0;
	for(int i = 0; i < MAXN; ++i)  if(result[i] < -EPS || result[i] > EPS) ++cnt;
	printf("%d", cnt);
	for(int i = MAXN; i >= 0; --i) if(result[i] < -EPS || result[i] > EPS) printf(" %d %.1f", i, result[i]);
	return 0;
} 
