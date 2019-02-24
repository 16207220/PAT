#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 1e5;
struct node {
	int data, nex;
}t[MAXN]; 
vector<int> res[3];
int n, k, x, first;
int main() {
	scanf("%d%d%d", &first, &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		scanf("%d%d", &t[x].data, &t[x].nex);
	}
	while(first != -1) {
		int data = t[first].data;
		if(data < 0) res[0].push_back(first);
		else if(data >= 0 && data <= k) res[1].push_back(first);
		else res[2].push_back(first);
		first = t[first].nex;
	}
	bool flag = true;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < res[i].size(); ++j) {
			if(flag) { printf("%05d %d ", res[i][j], t[res[i][j]].data); flag = false;}
			else printf("%05d\n%05d %d ", res[i][j], res[i][j], t[res[i][j]].data);
		}
	}
	printf("-1");
	return 0;
} 
