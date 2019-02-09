#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<string>
using namespace std;
vector<string> bit = { "tret","jan", "feb", "mar", "apr","may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };//个位数字
vector<string> digit = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };//十位数字
int n;
int main() {
	string a, b;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		cin >> a;
		if(isdigit(a[0])) {
			int num = stoi(a);
			if(num / 13) cout << digit[num / 13] << (num % 13 ? ' ' : '\n'); 
			if(num % 13 || num / 13 == 0) cout << bit[num % 13] << endl; 
		} else {
			int aa = 0, bb = 0;
			aa = find(bit.begin(), bit.end(), a) - bit.begin();
			if(aa == 13) bb = find(digit.begin(), digit.end(), a) - digit.begin(), aa = 0;
			if(cin.get() != '\n') {
				cin >> b;
				aa = find(bit.begin(), bit.end(), b) - bit.begin();
			}
			cout << bb * 13 + aa << endl;
		}
	}
	return 0;
}  
