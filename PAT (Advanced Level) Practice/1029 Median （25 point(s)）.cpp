#include<cstdio>
using namespace std;
const int MAXN = 2e5 + 10;
int n, m, t;
int v[MAXN];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
	scanf("%d", &m);
	int cnt = (m + n + 1) / 2, index = 1;
	for(int i = 0; i < m; ++i) {
		scanf("%d", &t);
		while(v[index] < t && index <= n) {
			--cnt;
			if(!cnt) printf("%d", v[index]);
			index++;
		}
		--cnt;
		if(!cnt) printf("%ld", t);
	}
	while(index <= n) {
		--cnt;
		if(!cnt) printf("%d", v[index]);
		++index;
	}
	return 0;
}
