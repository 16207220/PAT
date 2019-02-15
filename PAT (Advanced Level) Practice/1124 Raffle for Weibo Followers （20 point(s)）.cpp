#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int m, n, s, flag;
string name;
map<string, bool> have;
int main() {
	scanf("%d%d%d", &m, &n, &s);
	for(int i = 1; i <= m; ++i) {
		cin >> name;
		if(have[name]) s += 1;
		if(!have[name] && s == i) {
			have[name] = true;
			flag = 1;
			cout << name << '\n';
			s += n;
		}
	}
	if(!flag) cout << "Keep going..." << '\n';
	return 0;
}
