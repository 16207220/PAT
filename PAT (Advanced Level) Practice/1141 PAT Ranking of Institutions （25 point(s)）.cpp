#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	string school;
	int tws, ns;
	bool operator < (const node& rhs) const {
		return tws != rhs.tws ? tws > rhs.tws : (ns != rhs.ns ? ns < rhs.ns : school < rhs.school);
	}
};
unordered_map<string, double> sum;
unordered_map<string, int> cnt;
vector<node> res;
int n;
int main() {
	scanf("%d", &n);
	string id, school;
	double score;
	for(int i = 0; i < n; ++i) {
		cin >> id >> score >> school;
		for(int j = 0; j < school.length(); ++j) school[j] = tolower(school[j]);
		if(id[0] == 'B') score /= 1.5;
		else if(id[0] == 'T') score *= 1.5;
		sum[school] += score;
		cnt[school]++; 
	} 
	for(unordered_map<string, double>::iterator it = sum.begin(); it != sum.end(); ++it) {
		res.push_back({it->first, (int)it->second, cnt[it->first]});
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	int prescore = -1, rank = 0; // 莫非真的有0分呢。。。
	for(int i = 0; i < res.size(); ++i) {
		if(prescore != res[i].tws) rank = i + 1;
		printf("%d %s %d %d\n", rank, res[i].school.c_str(), res[i].tws, res[i].ns);
		prescore = res[i].tws;
	} 
	return 0;
}
