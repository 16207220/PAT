#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, k, m, cnt;
struct node {
	string name;
	int h;
	bool operator < (const node& rhs) const {
		return h != rhs.h ? h > rhs.h : name < rhs.name;
	}
};
vector<node> t;
int main() {
	scanf("%d%d", &n, &k);
	t.resize(n);
	for(int i = 0; i < n; ++i) cin >> t[i].name >> t[i].h;
	sort(t.begin(), t.end());
	for(int i = 0; i < k; ++i) {
		int size = i == 0 ? n / k + n % k : n / k;
		m = size / 2 + 1;
		vector<string> res(size);
		res[m - 1] = t[cnt].name;
		for(int j = m - 2, l = cnt + 1; j >= 0; --j, l += 2) res[j] = t[l].name;
		for(int j = m, l = cnt + 2; j < size; ++j, l += 2) res[j] = t[l].name;
		for(int j = 0; j < size; ++j) printf("%s%c", res[j].c_str(), j == size - 1 ? '\n' : ' ');
		cnt += size; 
	}
	return 0;
} 
