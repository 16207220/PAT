#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN = 1e6;
const int MAXM = 1e4 + 10;
struct node {
	int key, addrnext;
}t[MAXN];
vector<int> res, dup;
int book[MAXN];
int main() {
	int first, n, x;
	scanf("%d%d", &first, &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		scanf("%d%d", &t[x].key, &t[x].addrnext);
	}
	while(first != -1) {
		if(book[abs(t[first].key)] == 0) {
			book[abs(t[first].key)] = 1;
			res.push_back(first);
		} else dup.push_back(first);
		first = t[first].addrnext;
	}
	if(res.size()){
		for(int i = 0; i < res.size() - 1; ++i) printf("%05d %d %05d\n", res[i], t[res[i]].key, res[i + 1]);
		printf("%05d %d -1\n", res[res.size() - 1], t[res[res.size() - 1]].key); 
	}
	if(dup.size()) {
		for(int i = 0; i < dup.size() - 1; ++i) printf("%05d %d %05d\n", dup[i], t[dup[i]].key, dup[i + 1]);
		printf("%05d %d -1\n", dup[dup.size() - 1], t[dup[dup.size() - 1]].key);
	}
	return 0;
}
