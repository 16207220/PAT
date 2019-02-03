#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 2e3 + 10; //1000 * 2
vector<string> name; // »À√˚ 
map<string, int> idcache;
int n, k;
int e[MAXN][MAXN], w[MAXN];
bool vis[MAXN];
int ID(string x) {
	if(idcache.count(x)) return idcache[x];
	name.push_back(x);
	return idcache[x] = name.size() - 1;
} 
void dfs(int u, int& head, int &num, int &totalw) {
	vis[u] = true;
	++num;
	if(w[u] > w[head]) head = u;
	for(int v = 0; v < name.size(); ++v) {
		if(e[u][v]) {
			totalw += e[u][v];
			e[u][v] = e[v][u] = 0;
			if(vis[v] == false) dfs(v, head, num, totalw);
		}
	} 
}
map<string, int> ret;
void solve() {
	for(int i = 0; i < name.size(); ++i) if(vis[i] == false) {
		int head = i, totalw = 0, num = 0;
		dfs(i, head, num, totalw);
		if(num > 2 && totalw > k) ret[name[head]] = num;
	}
}
int main() {
	scanf("%d%d", &n, &k);
	int t;
	string a, b;
	for(int i = 0; i < n; ++i) {
		cin >> a >> b >> t;
		int aa = ID(a), bb = ID(b);
		e[aa][bb] += t, e[bb][aa] += t;
		w[aa] += t, w[bb] += t;
	}
	solve();
	printf("%d\n", ret.size());
	for(map<string, int>::iterator it = ret.begin(); it != ret.end(); ++it) {
		cout << it->first << " " << it->second << '\n';
	}
	return 0;
}
