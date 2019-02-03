#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN = 22;
string s;
int a[MAXN];
int carry, bit, flag;
int main() {
	cin >> s;
	for(int i = s.length() - 1; i >= 0; --i) {
		bit = s[i] - '0';
		a[bit]--;
		int t = bit * 2 + carry;
		carry = t / 10;
		s[i] = t % 10 + '0';
		a[t % 10]++;
	}
	for(int i = 0; i < 10; ++i) if(a[i]) flag = 1;
	if(carry || flag) printf("No\n1");
	else printf("Yes\n");
	cout << s;
	return 0;
} 
