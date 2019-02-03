#include<iostream>
#include<map>
#include<cstdio>
#include<cctype>
using namespace std;
int main() {
	string t;
	getline(cin, t);
	map<string, int> res;
	string s = "";
	for(int i = 0; i < t.length(); ++i) {
		if(isalnum(t[i])) {
			t[i] = tolower(t[i]);
			s += t[i];
		}
		else if(!isalnum(t[i]) || i == t.length() - 1) {
			if(s.length()) res[s]++;
			s = ""; 
		}
	} 
	string u;
	int maxn = 0;
	for(map<string, int>::iterator it = res.begin(); it != res.end(); ++it) if(it->second > maxn) {
		maxn = it->second;
		u = it->first;
	}
	cout << u << " " << maxn << '\n';
	return 0;
} 
