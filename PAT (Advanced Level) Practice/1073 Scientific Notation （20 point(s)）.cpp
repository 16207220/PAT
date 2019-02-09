#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string t, a, n;
	cin >> t;
	int i = 0; 
	while(t[i] != 'E') ++i;
	if(t[0] == '-') printf("-");
	a = t.substr(1, i - 1);
	n = t.substr(i + 1);
	int b = stoi(n);
	if(b < 0) {
		cout << "0.";
		for(int i = 0; i < - b - 1; ++i) cout << "0";
		for(int i = 0; i < a.length(); ++i) if(a[i] != '.') cout << a[i]; 
	} else {
		b += 1;
		int i, j;
		for(i = 0, j = 1; i < a.length() && j <= b; ++i) {
			if(a[i] == '.') continue;
			++j;
			cout << a[i];
		}
		if(j <= b) for(; j <= b; ++j) cout << '0';
		if(i < a.length()) printf(".");
		for(; i < a.length(); ++i) cout << a[i];
	}
	return 0;
} 
