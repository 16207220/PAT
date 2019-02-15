#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
using namespace std;
int k, cnt = 1;
map<char, bool> sure, havep;
vector<char> stuck;
string t;
char pre = '#';
int main() {
	scanf("%d", &k);
	cin >> t;
	t += "#";
	for(int i = 0; i < t.length(); ++i) {
		if(pre != t[i]) {
			if(!sure[pre]) sure[pre] = cnt % k; // 还不知道 
			cnt = 0;
		}
		pre = t[i];
		++cnt;
	}
	for(int i = 0; i < t.length() - 1; ++i) if(!sure[t[i]] && !havep[t[i]]) {
		havep[t[i]] = true;
		printf("%c", t[i]);
	}
	printf("\n");
	for(int i = 0; i < t.length() - 1; sure[t[i]] ? ++i : i += k) printf("%c", t[i]);
	return 0;
}
