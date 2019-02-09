#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
using namespace std;
struct node {
	char id[8];
	int t, status; // 时间 and 状态. 
}; 
int n, k, maxtime = -1; // 莫非真的存在不停车呢。。。 
vector<node> t, res;
bool cmp1(const node& a, const node& b) {
	return strcmp(a.id, b.id) == 0 ? a.t < b.t : strcmp(a.id, b.id) < 0;
}
bool cmp2(const node& a, const node& b) {
	return a.t < b.t;
}
map<string, int> st; // 花费时间 
int main() {
	scanf("%d%d", &n, &k);
	int h, m, s;
	char status[4];
	t.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%s %d:%d:%d %s", t[i].id, &h, &m, &s, status);
		t[i].status = strcmp(status, "in") == 0 ? 1 : -1; // in 表示1， -1表示out，便于后面计算车辆
		t[i].t = h * 3600 + m * 60 + s; 
	}
	sort(t.begin(), t.end(), cmp1);
	for(int i = 1; i < n; ++i) if(strcmp(t[i - 1].id, t[i].id) == 0 && t[i - 1].status == 1 && t[i].status == -1) {
		res.push_back(t[i - 1]); res.push_back(t[i]);
		st[t[i].id] += t[i].t - t[i - 1].t;
		if(maxtime < st[t[i].id]) maxtime = st[t[i].id];
	}
	sort(res.begin(), res.end(), cmp2);
	vector<int> cnt(n, 0);
	for(int i = 0; i < res.size(); ++i) {
		cnt[i] = i == 0 ? res[i].status : cnt[i - 1] + res[i].status;
	}
	int index = 0, j; // 查询开始下标. 
	for(int i = 0; i < k; ++i) {
		scanf("%d:%d:%d", &h, &m,&s);
		int time = h * 3600 + m * 60 + s;
		for(j = index; j < res.size(); ++j) 
			if(time < res[j].t) {
				printf("%d\n", cnt[j - 1]);
				break;
			} else if(j == res.size() - 1) {
				printf("%d\n", cnt[j]);
			}
		index = j;
	}
	for(map<string, int>::iterator it = st.begin(); it != st.end(); ++it) if(it->second == maxtime) {
		printf("%s ", (it->first).c_str());
	}
	printf("%02d:%02d:%02d", maxtime / 3600, maxtime % 3600 / 60, maxtime % 60);
	return 0;
}
