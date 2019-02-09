#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string t, res;
int n;
int main() {
	scanf("%d%*c", &n);
	getline(cin, res);
	reverse(res.begin(), res.end());
	for(int i = 0; i < n - 1; ++i) {
		getline(cin, t);
		reverse(t.begin(), t.end());
		int cnt = res.length() < t.length() ? res.length() : t.length();
		for(int i = cnt; i >= 0; --i) if(res.substr(0, i) == t.substr(0, i)) {
			res = res.substr(0, i);
			break;
		}
	} 
	reverse(res.begin(), res.end());
	if(res.length()) cout << res << '\n';
	else cout << "nai" << '\n';
	return 0;
}
