#include<iostream>
#include<cstdio>
using namespace std;
const int INF = 0x3f3f3f3f;
int first, last, sum, temp, cnt;
int n, l, a[10000];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	l = a[0]; temp = -INF;
	for(int i = 0; i < n; ++i) {
		sum += a[i];
		if(sum > temp) {
			first = l;
			last = a[i];
			temp = sum;	
		}
		if(sum < 0) {
			l = a[i + 1];
			sum = 0;
			cnt++;	
		}
	}
	if(cnt == n) printf("0 %d %d", a[0], a[n - 1]);
	else	printf("%d %d %d", temp, first, last);
	return 0;
}
