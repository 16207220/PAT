#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2500 + 10;
vector<string> res[MAXN];
int n, k;
string name;
int course, m;
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) {
		cin >> name;
		scanf("%d", &m);
		for(int j = 0; j < m; ++j) {
			scanf("%d", &course);
			res[course].push_back(name);
		}
	}
	for(int i = 1; i <= k; ++i) {
		printf("%d %d\n", i, res[i].size());
		sort(res[i].begin(), res[i].end());
		for(int j = 0; j < res[i].size(); ++j)	printf("%s\n", res[i][j].c_str());
	}
	return 0;
}
