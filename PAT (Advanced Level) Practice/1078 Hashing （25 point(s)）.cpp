#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN = 1e4 + 10;
bool isPrime(int n) {
	if(n <= 1) return false;
	for(int i = 2; i <= sqrt(n); ++i) if(n % i == 0) return false;
	return true;
}
int Hash[MAXN];
int main() {
	int tsize, n, x, step;
	scanf("%d%d", &tsize, &n); 
	while(!isPrime(tsize)) ++tsize;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		int key = x % tsize;
		if(!Hash[key]) {
			Hash[key] = true;
			printf("%d%c", key, i == n - 1 ? '\n' : ' ');
			continue;
		}
		for(step = 1; step <= tsize / 2; ++step) {
			key = (x + step * step) % tsize;
			if(!Hash[key]) {
				Hash[key] = true;
				printf("%d%c", key, i == n - 1 ? '\n' : ' ');
				break;
			}
		}
		if(step == tsize / 2 + 1) printf("-%c", i == n - 1 ? '\n' : ' ');
	} 
	return 0;
}
