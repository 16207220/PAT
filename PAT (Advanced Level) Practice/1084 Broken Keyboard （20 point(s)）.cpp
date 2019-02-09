#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
map<char, bool> have, insert;
vector<char> res;
string a, b;
int main() {
	cin >> a >> b;
	for(int i = 0; i < b.length(); ++i) have[b[i]] = true;
	for(int i = 0; i < a.length(); ++i) if(!have.count(a[i]) && !insert.count(toupper(a[i]))) {
		insert[toupper(a[i])] = true;
		res.push_back(toupper(a[i]));
	}
	for(int i = 0; i < res.size(); ++i) printf("%c", res[i]);
	return 0;
}
