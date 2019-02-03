#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 5e5;
int book[MAXN];
int main() {
	for(int i = 2; i < MAXN; ++i)
		for(int j = 2 * i; j < MAXN; j += i) book[j] = 1;
	long int n;
	scanf("%ld", &n);
	bool state = false;
	printf("%ld=", n);
	if(n == 1) printf("1");
	for(int i = 2; n > 1; ++i) {
		int cnt = 0;
		while(!book[i] && n % i == 0) {
			++cnt;
			n /= i;
		}
		if(cnt) {
			if(state) printf("*");
			state = true;
			printf("%d", i);
		}
		if(cnt > 1) printf("^%d", cnt); 
	}
	return 0;
}
