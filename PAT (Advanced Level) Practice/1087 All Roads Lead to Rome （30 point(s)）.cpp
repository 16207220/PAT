#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e2 + 10;
int e[MAXN][MAXN], dis[MAXN], happy[MAXN];
bool vis[MAXN];
vector<int> pre[MAXN], tpath, path;
vector<string> id;
map<string, int> idcache;
int maxtotalhappy, num; 
double maxavghappy;
int ID(string name) {
	if(idcache.count(name)) return idcache[name];
	id.push_back(name);
	return idcache[name] = id.size() - 1;
}
string s, aa, bb;
int a, b, c, n, k;
void dfs(int u) {
	if(u == ID(s)) {
		int totalhappy = 0;
		for(int i = 0; i < tpath.size(); ++i) totalhappy += happy[tpath[i]];
		double avghappy = 1.0 * totalhappy / tpath.size();
		if(totalhappy > maxtotalhappy || totalhappy == maxtotalhappy && avghappy > maxavghappy) {
			maxtotalhappy = totalhappy;
			maxavghappy = avghappy;
			path = tpath;
			path.push_back(u); 
		}
		++num;
		return;
	}
	tpath.push_back(u);
	for(int v = 0; v < pre[u].size(); ++v) dfs(pre[u][v]);
	tpath.pop_back();
}
int main() {
	fill(dis, dis + MAXN, INF);
	fill(e[0], e[0] + MAXN * MAXN, INF);
	cin >> n >> k >> s;
	dis[ID(s)] = 0;
	for(int i = 1; i < n; ++i) {
		cin >> aa >> happy[i];	ID(aa);
	}
	for(int i = 0; i < k; ++i) {
		cin >> aa >> bb >> c;
		a = ID(aa); b = ID(bb);
		e[a][b] = e[b][a] = c;
	}
	for(int i = 0; i < n; ++i) {
		int u = -1, minn = INF;
		for(int j = 0; j < n; ++j) if(vis[j] == false && dis[j] < minn) {
			minn = dis[j];
			u = j;
		}
		if(u == -1) break;
		vis[u] = true;
		for(int v = 0; v < n; ++v) if(vis[v] == false) {
			if(dis[v] > dis[u] + e[u][v]) {
				dis[v] = dis[u] + e[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			} else if(dis[v] == dis[u] + e[u][v]) pre[v].push_back(u);
		}
	}
	dfs(ID("ROM"));
	printf("%d %d %d %d\n", num, dis[ID("ROM")], maxtotalhappy, (int)maxavghappy);
	for(int i = path.size() - 1; i > 0; --i) cout << id[path[i]] << "->"; 
	cout << "ROM";
	return 0;
}
