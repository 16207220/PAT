#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int MAXN = 256;
int book[MAXN];
int miss;
string s;
int main() {
	cin >> s;
	for(int i = 0; i < s.length(); ++i) book[s[i]]++;
	cin >> s;
	for(int i = 0; i < s.length(); ++i) 
		if(book[s[i]]) --book[s[i]];
		else ++miss;
	if(miss) printf("No %d\n", miss);
	else {
		int cnt = 0;
		for(int i = 0; i < MAXN; ++i) cnt += book[i];
		printf("Yes %d", cnt);
	}
	return 0;
}
