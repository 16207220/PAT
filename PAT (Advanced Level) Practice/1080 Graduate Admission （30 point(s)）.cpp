#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct student {
	int rank, id;
	double Ge, Gi, grade;
	vector<int> sch;
	bool operator < (const student& rhs) const {
		return grade != rhs.grade ? grade > rhs.grade : Ge > rhs.Ge; 
	}
};
struct school {
	int nownum, maxnum, lastrank;
	vector<int> child; 
};
int n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	vector<school> sc(m); //school 
	vector<student> st(n); // student
	for(int i = 0; i < m; ++i) scanf("%d", &sc[i].maxnum);
	for(int i = 0; i < n; ++i) {
		st[i].sch.resize(k);
		st[i].id = i;
		scanf("%lf%lf", &st[i].Ge, &st[i].Gi);
		st[i].grade = (st[i].Ge + st[i].Gi) / 2;
		for(int j = 0; j < k; ++j) scanf("%d", &st[i].sch[j]);
	} 
	sort(st.begin(), st.end());
	st[0].rank = 1;
	for(int i = 1; i < n; ++i) st[i].rank = st[i].grade == st[i - 1].grade && st[i].Ge == st[i - 1].Ge ? st[i - 1].rank : i + 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < k; ++j) {
			int schoolid = st[i].sch[j];
			int rank = st[i].rank;
			int id = st[i].id;
			if(sc[schoolid].nownum < sc[schoolid].maxnum || sc[schoolid].lastrank == rank) {
				sc[schoolid].nownum++;
				sc[schoolid].lastrank = rank;
				sc[schoolid].child.push_back(id);
				break;
			}
		}
	}
	for(int i = 0; i < m; ++i) {
		sort(sc[i].child.begin(), sc[i].child.end());
		for(int j = 0; j < sc[i].child.size(); ++j) {
			if(j) printf(" ");
			printf("%d", sc[i].child[j]);
		}
		printf("\n");
	}
	return 0;
}
