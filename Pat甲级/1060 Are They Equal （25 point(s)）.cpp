#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int len;
string tran(string s, int& n) {
	while(s.length() && s[0] == '0') s.erase(s.begin()); // 去除首部0 
	if(s[0] == '.') { // 小数 
		s.erase(s.begin());
		while(s.length() && s[0] == '0') {
			s.erase(s.begin());
			--n;
		}
	}else { //  > 1 
		for(int i = 0; i < s.length() && s[i] != '.'; ++i) ++n;
		if(s.length() > n) s.erase(s.begin() + n); // 可能是i >= s.length()退出  
	}
	if(s.length() == 0) n = 0; // 0.0的情况 
	string res = "";
	for(int i = 0; i < len; ++i) //
		if(i < s.length()) res += s[i];
		else res += "0";
	return res;
} 
int main() {
	string a, b;
	int n, alen = 0, blen = 0;
	cin >> len >> a >> b;
	a = tran(a, alen); b = tran(b, blen);
	if(a == b && alen == blen) printf("YES 0.%s*10^%d", a.c_str(), alen);
	else printf("NO 0.%s*10^%d 0.%s*10^%d", a.c_str(), alen, b.c_str(), blen);
	return 0;
}
