#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 510;
const int MAXM = 1e5 + 10;
int book[MAXN], t[MAXM];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
		++book[t[i]];
	}
	sort(t, t + n);
	int i;
	for(i = 0; i < n; ++i) {
		--book[t[i]];
		if(book[m - t[i]]) break;
	}	
	if(i == n) printf("No Solution\n");
	else printf("%d %d\n", t[i], m - t[i]);
	return 0;
}
