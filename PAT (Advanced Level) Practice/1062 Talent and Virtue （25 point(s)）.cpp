#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
	int id, talent, virtue;
	bool operator < (const node& rhs) const {
		if(talent + virtue != rhs.talent + rhs.virtue) return talent + virtue > rhs.talent + rhs.virtue;
		else if(virtue != rhs.virtue) return virtue > rhs.virtue;
		return id < rhs.id;
	} 
}temp;
int n, L, H;
vector<node> res[4];
int main() {
	scanf("%d%d%d", &n, &L, &H);
	int total = n;
	for(int i = 0; i < n; ++i) {
		scanf("%d%d%d", &temp.id, &temp.virtue, &temp.talent);
		if(temp.virtue < L || temp.talent < L) {
			--total;
			continue;
		}
		if(temp.talent >= H && temp.virtue >= H) res[0].push_back(temp);
		else if(temp.virtue >= H && temp.talent < H) res[1].push_back(temp);
		else if(temp.virtue < H && temp.talent < H && temp.virtue >= temp.talent) res[2].push_back(temp);
		else res[3].push_back(temp);
	}
	printf("%d\n", total);
	for(int i = 0; i < 4; ++i) {
		sort(res[i].begin(), res[i].end());
		for(int j = 0; j < res[i].size(); ++j) printf("%08d %d %d\n", res[i][j].id, res[i][j].virtue, res[i][j].talent);
	}
	return 0;
}
