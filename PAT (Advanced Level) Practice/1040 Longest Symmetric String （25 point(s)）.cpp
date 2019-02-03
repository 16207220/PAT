#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int MAXN = 2e3 + 10;
string s;
char res[MAXN];
int p[MAXN];
int init() {
	res[0] = '$';
	res[1] = '#';
	int len = 2;
	for(int i = 0; i < s.length(); ++i) {
		res[len++] = s[i];
		res[len++] = '#';
	}
	res[len] = '\0';
	return len;
}
int manacher() {
	int len = init();
	int maxlen = -1;
	int mid, mx = 0;
	for(int i = 1; i < len; ++i) {
		p[i] = i < mx ? min(mx - i, p[2 * mid - i]) : 1;
		while(res[i - p[i]] == res[i + p[i]]) ++p[i];
		if(i + p[i] > mx) {
			mx = i + p[i];
			mid = i;
		}
		maxlen = max(maxlen, p[i] - 1);
	}
	return maxlen;
}
int main() {
	getline(cin, s);
	printf("%d\n", manacher());
	return 0;
}
