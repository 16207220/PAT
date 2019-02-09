#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	int len = 0, s, t, first;
	for(int i = 2; i <= sqrt(n); ++i) {
		s = i;
		t = n;
		while(t % s == 0) {
			t /= s;
			++s;	
		}
		if(s - i > len) {
			len = s - i;
			first = i;
		}
	} 
	if(len) {
		printf("%d\n", len);
		for(int i = 0; i < len; ++i) printf("%d%c", first + i, i == len - 1 ? '\n' : '*'); 
	} else printf("1\n%d", n);
	return 0;
} 
