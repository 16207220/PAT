#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e6;
struct node {
	int addr, key, Next;
	bool operator < (const node& rhs) const {
		return key < rhs.key;
	}
}t[MAXN];;
int n, first, x;
int main() {
	vector<node> res;
	scanf("%d%d", &n, &first);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		t[x].addr = x;
		scanf("%d%d", &t[x].key, &t[x].Next);
	}
	while(first != -1) {
		res.push_back(t[first]);
		first = t[first].Next;
	}
	if(res.size()) {
		sort(res.begin(), res.end());
		printf("%d %05d\n", res.size(), res[0].addr);
		for(int i = 0; i < res.size() - 1; ++i) {
			printf("%05d %d %05d\n", res[i].addr, res[i].key, res[i + 1].addr);
		}
		printf("%05d %d -1", res[res.size() - 1].addr, res[res.size() - 1].key);
	} else printf("%d %d\n%d", 0, -1, -1);
	return 0;
}
