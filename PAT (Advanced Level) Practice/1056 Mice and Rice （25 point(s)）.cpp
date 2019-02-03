#include<iostream>
#include<vector>
using namespace std;
int np, ng;
int main() {
	scanf("%d%d", &np, &ng);
	vector<int> w(np), ord(np), rk(np);
	for(int i = 0; i < np; ++i) scanf("%d", &w[i]);
	for(int i = 0; i < np; ++i) scanf("%d", &ord[i]);
	while(ord.size() > 1) {
		np = ord.size();
		int group = np % ng ? np / ng + 1 : np / ng;
		vector<int> t;
		for(int i = 0; i < ord.size();) {
			int u, maxn = -1;
			for(int j = 0; j < ng && i < ord.size(); ++j, ++i) {
				rk[ord[i]] = group + 1;
				if(maxn < w[ord[i]]) {
					u = ord[i];
					maxn = w[ord[i]];
				}
			}
			t.push_back(u); 
		}
		ord = t;
	}
	rk[ord[0]] = 1;
	for(int i = 0; i < rk.size(); ++i) printf("%d%c", rk[i], i == rk.size() - 1 ? '\n' : ' ');
	return 0;
}

