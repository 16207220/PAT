#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
const int MAXN = 1e6 + 10;
using namespace std;
struct node {
	int data;
	int neaddr;
}link[MAXN];
int first, cnt, L, K, x;
vector<int> res;
int main() {
	scanf("%d%d%d", &first, &L, &K);
	for(int i = 0; i < L; ++i) {
		scanf("%d", &x);
		scanf("%d%d", &link[x].data, &link[x].neaddr);
	}
	while(first != -1) {
		res.push_back(first);
		first = link[first].neaddr;
	}
	for(int i = 0; i + K <= res.size(); i += K) reverse(res.begin() + i, res.begin() + i + K);
	for(int i = 0; i < res.size() - 1; ++i) printf("%05d %d %05d\n", res[i], link[res[i]].data, res[i + 1]);
	printf("%05d %d -1\n", res[res.size() - 1], link[res[res.size() - 1]].data);
	return 0;
} 
