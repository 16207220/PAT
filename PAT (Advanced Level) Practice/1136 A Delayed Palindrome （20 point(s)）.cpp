#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
bool isPalin(string a) {
	string b = a; reverse(a.begin(), a.end());
	return a == b;
}
string add(string a, string b) {
	string ret = "";
	int carry = 0, cur;
	for(int i = a.length() - 1; i >= 0; --i) {
		cur = a[i] - '0' + b[i] - '0' + carry;
		carry = cur / 10;
		cur %= 10;
		ret += to_string(cur);
	}
	if(carry) ret += to_string(carry); 
	reverse(ret.begin(), ret.end());
	return ret;
}
int main() {
	string a, b, t;
	bool flag = false;
	cin >> t;
	if(isPalin(t)) flag = true;
	else {
		for(int i = 0; i < 10; ++i) {
			b = a = t; reverse(b.begin(), b.end());
			t = add(a, b);
			printf("%s + %s = %s\n", a.c_str(), b.c_str(), t.c_str());
			if(isPalin(t)) {
				flag = true;
				break;
			}
		}
	}
	if(flag) printf("%s is a palindromic number.\n", t.c_str());
	else printf("Not found in 10 iterations.\n");
	return 0;
}
