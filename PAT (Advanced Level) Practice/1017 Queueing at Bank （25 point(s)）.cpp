#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
struct node {
	int ct, t; // come time and spent all time
	bool operator < (const node& rhs) const {
		return ct < rhs.ct;
	}
}cus;
int n, k;
int h, m, s, t;
int main() {
	scanf("%d%d", &n, &k);
	vector<node> res;
	for(int i = 0; i < n; ++i) {
		scanf("%d:%d:%d %d", &h, &m, &s, &t);
		if(t > 60) t = 60;
		int ct = h * 3600 + m * 60 + s;
		if(ct >= 17 * 3600) continue;
		cus.ct = ct;
		cus.t = t * 60;
		res.push_back(cus);
	}
	sort(res.begin(), res.end());
	vector<int> win(k, 8 * 3600);
	double total = 0.0;
	for(int i = 0; i < res.size(); ++i) {
		int u = 0, minn = win[0];
		for(int j = 1; j < k; ++j) if(win[j] < minn) {
			minn = win[j];
			u = j;
		}
		if(minn <= res[i].ct) win[u] = res[i].ct + res[i].t;
		else {
			win[u] += res[i].t;
			total += minn - res[i].ct;
		} 
	}
	if(res.size() == 0)
        printf("0.0");
    else
        printf("%.1f", total / 60.0 / res.size());
    return 0;
} 

