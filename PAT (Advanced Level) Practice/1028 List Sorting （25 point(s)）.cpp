#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node {
	int id;
	string name;
	int grade;
};
int n, c;
bool cmp1(const node& a, const node& b) {
	return a.id < b.id;
}
bool cmp2(const node& a, const node& b) {
	return a.name < b.name;
}
bool cmp3(const node& a, const node& b) {
	return a.grade == b.grade ? a.id < b.id : a.grade < b.grade;
}
int main() {
	scanf("%d%d", &n, &c);
	vector<node> res(n);
	for(int i = 0; i < n; ++i) cin >> res[i].id >> res[i].name >> res[i].grade;
	if(c == 1) sort(res.begin(), res.end(), cmp1);
	else if(c == 2)	sort(res.begin(), res.end(), cmp2);
	else sort(res.begin(), res.end(), cmp3);
	for(int i = 0; i < n; ++i) printf("%06d %s %d\n", res[i].id, res[i].name.c_str(), res[i].grade); 
	return 0;
}

