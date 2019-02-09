#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	int id, rank, num, totalscore;
	vector<int> score;
	bool show;
	bool operator < (const node& rhs) const {
		return totalscore != rhs.totalscore ? totalscore > rhs.totalscore : (num != rhs.num ? num > rhs.num : id < rhs.id);
	}
}t;
int n, k, m;
int main() {
	scanf("%d%d%d", &n, &k, &m);
	vector<int> stand(k + 1);
	for(int i = 1; i <= k; ++i) scanf("%d", &stand[i]);
	vector<node> res(n + 1);
	for(int i = 1; i <= n; ++i) res[i].score.resize(k + 1, -2); // -2表示还没做 , -1表示没编译过... 
	int score, id, num;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d%d", &id, &num, &score);
		res[id].id = id;
		res[id].score[num] = max(score, res[id].score[num]);
		if(score != -1) res[id].show = true;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(res[i].score[j] == stand[j]) res[i].num++;
			if(res[i].score[j] != -1 && res[i].score[j] != -2) res[i].totalscore += res[i].score[j];
		}
	} 
	sort(res.begin() + 1, res.end());
	for(int i = 1; i <= n; ++i) {
		res[i].rank = i;
		if(res[i].totalscore == res[i - 1].totalscore) res[i].rank = res[i - 1].rank; 
	}
	for(int i = 1; i <= n; ++i) if(res[i].show) {
		printf("%d %05d %d ", res[i].rank, res[i].id, res[i].totalscore);
		for(int j = 1; j <= k; ++j) if(res[i].score[j] != -1 && res[i].score[j] != -2) printf("%d%c", res[i].score[j], j == k ? '\n' : ' ');
		else if(res[i].score[j] == -1) printf("0%c", j == k ? '\n' : ' ');
		else printf("-%c", j == k ? '\n' : ' ');
	}
	return 0;
}
