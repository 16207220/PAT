#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN = 1e4 + 10;
struct node {
	string name;
	int Gp, mid = -1, final = -1, G;
	bool operator < (const node& rhs) const {
		return G != rhs.G ? G > rhs.G : name < rhs.name;
	} 
}res[MAXN];
int p, n, m;
int Gp, mid, final, cnt = 1;
string name;
map<string, int> Cache;
int main() {
	scanf("%d%d%d", &p, &m, &n);
	for(int i = 0; i < p; ++i) {
		cin >> name >> Gp;
		if(Gp < 200) continue;
		res[cnt].Gp = Gp; res[cnt].name = name;
		Cache[name] = cnt++;
	}
	for(int i = 0; i < m; ++i) {
		cin >> name >> mid;
		if(!Cache[name]) continue;
		res[Cache[name]].mid = mid;
	}
	for(int i = 0; i < n; ++i) {
		cin >> name >> final;
		if(!Cache[name]) continue;
		res[Cache[name]].final = final;
	}
	for(int i = 1; i < cnt; ++i) {
		res[i].G = res[i].mid > res[i].final ? (res[i].mid * 0.4 + res[i].final * 0.6 + 0.5) : res[i].final;
	}
	sort(res + 1, res + cnt);
	for(int i = 1; i < cnt; ++i) if(res[i].G >= 60 && res[i].G <= 100) {
		printf("%s %d %d %d %d\n", res[i].name.c_str(), res[i].Gp, res[i].mid, res[i].final, res[i].G);
	}
	return 0;
} 
