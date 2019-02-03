#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long LL;
LL getDec(string s, const int& radix) {
	LL ret = 0;
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.length(); ++i) {
		LL a;
		if(isalpha(s[i])) a = s[i] - 'a' + 10;
		else a = s[i] -'0';
		ret += a * pow(radix, i); 
	}
	return ret;
}
LL getMinRadix(const string& s) {
	LL minRadix = -1;
	for(int i = 0; i < s.length(); ++i) {
		LL a;
		if(isalpha(s[i])) a = s[i] - 'a' + 10;
		else a = s[i] - '0';
		minRadix = max(minRadix, a);
	}
	return minRadix + 1; // 最小的数+1为下界 
}
LL bSearch(LL l, LL r, const LL& num, const string& s) {
	while(l < r) {
		LL m = l + (r - l) / 2;
		LL t = getDec(s, m);
		if(num == t) return m;
		else if(num < t || t < 0) r = m; // 别忘记考虑t溢出变负值的情况。。。 
		else l = m + 1;
	}
	return -1;
}
int main() {
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if(tag == 2) swap(n1, n2);
	LL num = getDec(n1, radix);
	LL l = getMinRadix(n2);
	LL r = max(l, num) + 1; // +1   [l, r) bsearch 
	int flag = bSearch(l, r, num, n2);
	if(flag == -1) printf("Impossible");
	else printf("%lld", flag);
	return 0;
} 
