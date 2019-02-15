#include<iostream>
#include<map>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN = 1e5;
int ran[MAXN];
map<int, bool> have;
int n, k, x;
bool isprime(int m) {
	if(m <= 1) return false;
	for(int i = 2; i <= sqrt(m); ++i) if(m % i == 0) return false;
	return true;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &x), ran[x] = i;
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &x);
		printf("%04d: ", x);
		if(!ran[x]) {
			printf("Are you kidding?\n");
			continue;
		}
		if(have[x]) {
			printf("Checked\n");
			continue;
		}
		have[x] = true;
		if(ran[x] == 1) printf("Mystery Award\n");
		else if(isprime(ran[x])) printf("Minion\n");
		else printf("Chocolate\n");
	}
	return 0;
} 
