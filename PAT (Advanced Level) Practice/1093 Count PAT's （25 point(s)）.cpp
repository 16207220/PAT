#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
const int mod = 1000000007;
string s;
int cntt, cntp, res;
int main() {
	cin >> s;
	for(int i = 0; i < s.length(); ++i) if(s[i] == 'T') ++cntt;
	for(int i = 0; i < s.length(); ++i) 
		if(s[i] == 'P') cntp++;
		else if(s[i] == 'A') res = (res + cntt * cntp % mod) % mod;
		else if(s[i] == 'T') --cntt;
	printf("%d\n", res);
}
