#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
bool isPrime(int n) {
	if(n <= 1) return false;
	for(int i = 2; i <= sqrt(n); ++i) if(n % i == 0) return false;
	return true; 
}
int getDec(const string &s, const int &radix) {
	int ret = s[0] - '0';
	for(int i = 1; i < s.length(); ++i) {
		ret = ret * radix + s[i] - '0';
	}
	return ret;
}
int main() {
	int n, radix;
	while(scanf("%d", &n) == 1 && n >= 0) {
		scanf("%d", &radix);
		if(isPrime(n) == false) {
			printf("No\n");
			continue;
		}
		string s = "";
		while(n) {
			s += to_string(n % radix);
			n /= radix;
		}
		int rev = getDec(s, radix);
		if(isPrime(rev)) printf("Yes\n");
		else printf("No\n"); 
	}
	return 0;
}
