#include<iostream>
#include<string>
#include<cstdio>
#include<stack>
using namespace std;
string t[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
stack<string> result;
string s;
int n;
int main() {
	cin >> s;
	for(int i = 0; i < s.length(); ++i) n += s[i] - '0';
	while(n) {
		result.push(t[n % 10]);
		n /= 10;
	}
	if(result.empty()) cout << t[0] << '\n';  // 别忘记了sum为0的情况哦 
	while(!result.empty()) {
		string temp = result.top(); 
		result.pop();
		cout << temp << (result.empty() ? '\n' : ' ');
	}
	return 0;
} 
