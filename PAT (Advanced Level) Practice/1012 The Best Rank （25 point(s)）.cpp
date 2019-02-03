#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 2010;
const int MAXM = 1e7;
const int INF = 0x3f3f3f3f;
struct stu {
	int id;
	int best;
	float score[4];
	int rank[4];
}st[MAXN];
int n, m, flag;
int exists[MAXM];
bool cmp(const stu& a, const stu& b) {
	return a.score[flag] > b.score[flag];
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d%f%f%f", &st[i].id, &st[i].score[1], &st[i].score[2], &st[i].score[3]); // A > C > M > E. 
		st[i].score[0] = (st[i].score[1] + st[i].score[2] + st[i].score[3] + 0.5) / 3; //averege
	}
	for(flag = 0; flag < 4; ++flag) {
		sort(st, st + n, cmp);
		st[0].rank[flag] = 1;
		for(int i = 1; i < n; ++i) {
			st[i].rank[flag] = i + 1;
			if(st[i].score[flag] == st[i - 1].score[flag]) st[i].rank[flag] = st[i - 1].rank[flag];
		}
	}
	for(int i = 0; i < n; ++i) {
		int minn = INF;
		for(int j = 0; j < 4; ++j) if(st[i].rank[j] < minn) {
			minn = st[i].rank[j];
			st[i].best = j;
		}
		exists[st[i].id] = i + 1;
	}
	int id;
	string t = "ACME";
	for(int i = 0; i < m; ++i) {
		scanf("%d", &id);
		int temp = exists[id];
		int r = st[temp - 1].best;
		if(temp) {
			printf("%d %c\n", st[temp - 1].rank[r], t[r]);
		} else printf("N/A\n");
	}
	return 0;
}
