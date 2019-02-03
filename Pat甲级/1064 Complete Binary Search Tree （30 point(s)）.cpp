#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define LL root<<1
#define RR root<<1|1
vector<int> in, level;
int n, index;
void getlevel(int root) {
	if(root > n) return;
	getlevel(LL);
	level[root] = in[index++];
	getlevel(RR);
} 

int main() {
	scanf("%d", &n);
	in.resize(n); level.resize(n + 1);
	for(int i = 0; i < n; ++i) scanf("%d", &in[i]);
	sort(in.begin(), in.end());
	getlevel(1);
	for(int i = 1; i <= n; ++ i) printf("%d%c", level[i], i == n ? '\n' : ' ');
	return 0;
}
