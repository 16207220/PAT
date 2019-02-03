#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e4 + 10;
int a[MAXN];
int main() {
	int n;
	scanf("%d", &n);
	vector<int> res(n);
	for(int i = 0; i < n; ++i) scanf("%d", &res[i]), a[res[i]]++;
	int i;
	for(i = 0; i < n; ++i) if(a[res[i]] == 1) break;
	if(i != n) printf("%d", res[i]);
	else printf("None");
	return 0;
} 
