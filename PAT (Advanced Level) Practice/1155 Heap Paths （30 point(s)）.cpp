#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 3e3 + 10;
vector<int> path;
int t[MAXN];
int n;
void getpath(int root) {
	if(root<<1 > n && root<<1|1 > n) {
		if(root <= n) {
			for(int i = 0; i < path.size(); ++i) printf("%d%c", path[i], i == path.size() - 1 ? '\n' : ' ');
		}
		return ;
	}
	path.push_back(t[root<<1|1]);
	getpath(root<<1|1);
	path.pop_back();
	path.push_back(t[root<<1]);
	getpath(root<<1);
	path.pop_back();
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &t[i]);
	bool isMax = true, isMin = true;
	for(int i = n; i > 1; --i) {
		if(t[i] > t[i / 2]) isMax = false;
		if(t[i] < t[i / 2]) isMin = false;
	}
	path.push_back(t[1]);
	getpath(1);
	printf("%s\n", isMax ? "Max Heap" : (isMin ? "Min Heap" : "Not Heap"));
	return 0;
}
