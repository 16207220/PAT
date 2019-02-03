#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
map<int, int> res;
int n, m, x;
int main() {
	scanf("%d%d", &m, &n);
	int half = m * n / 2;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &x);
			res[x]++;
			if(res[x] > half) printf("%d\n", x);
		}
	}
	return 0;
} 
