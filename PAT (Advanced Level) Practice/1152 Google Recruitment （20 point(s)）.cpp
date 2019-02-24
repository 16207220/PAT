#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;
bool isPrime(int x) {
	if(x <= 1) return false;
	for(int i = 2; i <= sqrt(x); ++i) if(x % i == 0) return false;
	return true;
} 
int main() {
	string s;
	int L, k;
	scanf("%d%d", &L, &k);
	cin >> s;
	for(int i = 0; i <= L - k; ++i) {
		if(isPrime(stoi(s.substr(i, k)))) {
			cout << s.substr(i, k) << '\n';
			return 0;
		}
	} 
	printf("404\n");
	return 0;
}
