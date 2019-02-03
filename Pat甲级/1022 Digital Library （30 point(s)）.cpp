#include<iostream>
#include<set>
#include<map>
#include<cstdio>
#include<sstream>
using namespace std;
map<string, set<int>> title, author, keyWords, pub, year;
void find(map<string, set<int>>& m, const string& s) {
	if(m.count(s)) {
		for(set<int>::iterator it = m[s].begin(); it != m[s].end(); ++it) printf("%07d\n", *it);
	} else printf("Not Found\n");
}
int main() {
	int id, n, m, num;
	string s, st, sa, sk, sp, sy;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%*c", &id);
		// ³Ôµô»Ø³µ·û 
		//getchar();
		getline(cin, st);
		title[st].insert(id);
		getline(cin, sa);
		author[sa].insert(id);
		getline(cin, s);
		stringstream ss(s);
		while(ss >> sk) keyWords[sk].insert(id);
		getline(cin, sp);
		pub[sp].insert(id);
		getline(cin, sy);
		year[sy].insert(id);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		scanf("%d: ", &num);
		getline(cin, s);
		printf("%d: %s\n", num, s.c_str());
		if(num == 1) find(title, s);
		else if(num == 2) find(author, s);
		else if(num == 3) find(keyWords, s);
		else if(num == 4) find(pub, s);
		else find(year, s);
	}
	return 0;
}
