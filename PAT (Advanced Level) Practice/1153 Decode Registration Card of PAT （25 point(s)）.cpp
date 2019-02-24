#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
	string key;
	int val;
	bool operator < (const node& rhs) const {
		return val != rhs.val ? val > rhs.val : key < rhs.key;
	}
};
vector<node> v;
int n, m, num;
string t;
int main() {
	scanf("%d%d", &n, &m);
	v.resize(n);
	for(int i = 0; i < n; ++i) cin >> v[i].key >> v[i].val;
	for(int l = 0; l < m; ++l) {
		cin >> num >> t;
		printf("Case %d: %d %s\n", l + 1, num, t.c_str());
		vector<node> res;
		int cnt = 0, sum = 0;
		if(num == 1) {
			for(int i = 0; i < n; ++i) if(v[i].key[0] == t[0]) res.push_back(v[i]);
		} else if(num == 2) {
			for(int i = 0; i < n; ++i) if(v[i].key.substr(1, 3) == t) {
				cnt++;
				sum += v[i].val;
			}
			if(cnt) printf("%d %d\n", cnt, sum);
		} else {
			unordered_map<string, int> m;
			for(int i = 0; i < n; ++i) if(v[i].key.substr(4, 6) == t) m[v[i].key.substr(1, 3)]++;
			for(auto it : m) res.push_back({it.first, it.second});
		}
		sort(res.begin(), res.end());
		for(int i = 0; i < res.size(); ++i) printf("%s %d\n", res[i].key.c_str(), res[i].val);
		if((num == 1 || num == 3) && res.size() == 0 || num == 2 && cnt == 0) printf("NA\n");
	}
	return 0;
} 
