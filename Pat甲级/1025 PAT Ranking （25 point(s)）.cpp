#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	long long id;
	int score;
	int finalRank;
	int localNum;
	int localRank;
	bool operator < (const node& rhs) const {
		return score == rhs.score ? id < rhs.id : score > rhs.score;
	}
};
vector<node> final;
int n, k;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &k);
		vector<node> t(k);
		for(int j = 0; j < k; ++j)  scanf("%lld%d", &t[j].id, &t[j].score), t[j].localNum = i;
		sort(t.begin(), t.end());
		t[0].localRank = 1;
		final.push_back(t[0]);
		for(int j = 1; j < k; ++j) {
			t[j].localRank = j + 1;
			if(t[j].score == t[j - 1].score) t[j].localRank = t[j - 1].localRank;
			final.push_back(t[j]);
		}
	}
	sort(final.begin(), final.end());
	final[0].finalRank = 1;
    for(int j = 1; j < final.size(); j++)
        final[j].finalRank = (final[j].score == final[j - 1].score) ? (final[j - 1].finalRank) : (j + 1);
    printf("%d\n", final.size());
	for(int i = 0; i < final.size(); ++i) {
		printf("%lld %d %d %d\n", final[i].id, final[i].finalRank, final[i].localNum, final[i].localRank);
	}
	return 0;
}
