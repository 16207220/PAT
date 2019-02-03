#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 54;
int a[MAXN], res[MAXN], op[MAXN];
int k;
int main() {
	scanf("%d", &k);
	for(int i = 0; i < MAXN; ++i) a[i] = i;
	for(int i = 0; i < MAXN; ++i) scanf("%d", &op[i]);
	for(int i = 0; i < k; ++i) {
		for(int j = 0; j < MAXN; ++j)	res[op[j] - 1] = a[j];
		memcpy(a, res, sizeof(res));
	}
	string t = "SHCTJ";
	for(int i = 0; i < MAXN; ++i) printf("%c%d%c", t[res[i] / 13], res[i] % 13 + 1, i == MAXN - 1 ? '\n' : ' ');
	return 0;
} 
