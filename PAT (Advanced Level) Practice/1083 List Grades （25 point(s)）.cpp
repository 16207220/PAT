#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
	string name, id;
	int grade;
	bool operator < (const node& rhs) const {
		return grade > rhs.grade;
	}
}temp;
int n, grade1, grade2;
vector<node> t, res;
int main() {
	scanf("%d", &n);
	t.resize(n);
	for(int i = 0; i < n; ++i) cin >> t[i].name >> t[i].id >> t[i].grade;
	scanf("%d%d", &grade1, &grade2);
	for(int i = 0; i < n; ++i) if(t[i].grade >= grade1 && t[i].grade <= grade2) res.push_back(t[i]);
	sort(res.begin(), res.end());
	if(res.size()) {
		for(int i = 0; i < res.size(); ++i) printf("%s %s\n", res[i].name.c_str(), res[i].id.c_str());
	} else printf("NONE\n");
}
