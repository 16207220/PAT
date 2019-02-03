#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 1010;
const int MAXM = 21;
struct node {
	int window;
	int start;
	int finish;
	bool operator < (const node& rhs) const {
		return rhs.finish == finish ? window > rhs.window : finish > rhs.finish; 
	}
}cus[MAXN];
int t[MAXN], winLast[MAXM];
int n, m, k, q;
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 1; i <= k; ++i) scanf("%d", &t[i]);
	int cnt = 0;
	priority_queue<node> p;
	for(int i = 1; i <= m && cnt < k; ++i) {
		for(int j = 1; j <= n && cnt < k; ++j) {
			++cnt; // 
			cus[cnt].window = j;
			cus[cnt].start = winLast[j];
			cus[cnt].finish = winLast[j] = cus[cnt].start + t[cnt];
			p.push(cus[cnt]);
		}
	}
	for(int i = cnt + 1; i <= k; ++i) {
		node u = p.top(); p.pop();
		int win = u.window;
		cus[i].window = win;
		cus[i].start = winLast[win];
		cus[i].finish = winLast[win] = cus[i].start + t[i];
		p.push(cus[i]);
	}
	for(int i = 0; i < q; ++i) {
		int query;
		scanf("%d", &query);
		node u = cus[query];
		if(u.start >= (17 - 8) * 60) printf("Sorry\n");
		else printf("%02d:%02d\n", u.finish / 60 + 8, u.finish % 60); 
	}
	return 0;
} 
