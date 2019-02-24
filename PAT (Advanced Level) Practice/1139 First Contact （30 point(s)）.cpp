#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e4;
struct node {
	int x, y;
	bool operator < (const node& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	} 
};
vector<int> v[MAXN];
map<int, bool> mp;
int n, m, k;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; ++i) {
		string a, b;
		cin >> a >> b;
		if(a.length() == b.length()) {
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		mp[abs(stoi(a)) * 10000 + abs(stoi(b))] = mp[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		vector<node> res;
		for(int j = 0; j < v[abs(a)].size(); ++j) {
			for(int l = 0; l < v[abs(b)].size(); ++l) {
				if(v[abs(a)][j] == abs(b) || v[abs(b)][l] == abs(a)) continue;
				if(mp[v[abs(a)][j] * 10000 + v[abs(b)][l]]) res.push_back(node{v[abs(a)][j], v[abs(b)][l]});
			}
		}
		sort(res.begin(), res.end());
		printf("%d\n", res.size());
		for(int j = 0; j < res.size(); ++j) {
			printf("%04d %04d\n", res[j].x, res[j].y);
		}
	}
	return 0;
}
