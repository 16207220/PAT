#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
bool isPrime(int x) {
	if(x < 2) return false;
	for(int i = 2; i <= sqrt(x); ++i) if(x % i == 0) return false;
	return true;
} 
int msize, n, m, step, x, key;
int main() {
	scanf("%d%d%d", &msize, &n, &m);
	while(!isPrime(msize)) ++msize;
	vector<int> t(msize, 0);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		for(step = 0; step <= msize / 2; ++step) {
			key = (step * step + x) % msize;
			if(!t[key]) {
				t[key] = x;
				break;
			}
		}
		if(step == msize / 2 + 1) printf("%d cannot be inserted.\n", x);
	}
	int res = 0; 
	for(int i = 0; i < m; ++i) {
		scanf("%d", &x);
		for(step = 0; step <= msize; ++step) {
			++res;
			key = (step * step + x) % msize;
			if(t[key] == x || !t[key]) break;
		}
	}
	printf("%.1f\n", 1.0 * res / m);
	return 0;
}
