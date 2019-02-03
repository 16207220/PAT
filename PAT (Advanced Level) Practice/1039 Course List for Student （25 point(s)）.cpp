#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN = 26 * 26 * 26 * 10 + 10;
string course;
int getId(const string& s) {
	return (s[0] - 'A') * 26 * 26 * 10 + (s[1] - 'A') * 26 * 10 + (s[2] - 'A') * 10 + s[3] - '0';
}
int n, k;
int id, m;
int courseid;
vector<int> res[MAXN];
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d%d", &id, &m);
		for(int j = 0; j < m; ++j) {
			cin >> course;
			courseid = getId(course);
			res[courseid].push_back(id);
		}
	}
	for(int i = 0; i < n; ++i) {
		cin >> course;
		courseid = getId(course);
		sort(res[courseid].begin(), res[courseid].end());
		printf("%s %d", course.c_str(), res[courseid].size());
		for(int j = 0; j < res[courseid].size(); ++j) printf(" %d", res[courseid][j]);
		printf("\n");
	}
	return 0; 
}

