#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string res;
int n;
int main() {
	cin >> res >> n;
	for(int i = 0; i < n - 1; ++i) {
		char pre = res[0];
		int cnt = 1;
		string t = "";
		t += res[0];
		for(int j = 1; j < res.length(); ++j) {
			if(res[j] != pre) {
				t += to_string(cnt) + res[j];
				cnt = 1;
			} else ++cnt;
			pre = res[j];
		}
		res = t + to_string(cnt);
	}	
	cout << res << '\n';
	return 0;
} 
