#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int MAXN = 1e5 + 10;
#define lowbit(x) (x & -x)
int c[MAXN];
void update(int x, int v) {
	while(x < MAXN){
		c[x] += v;
		x += lowbit(x);
	}
}
int getsum(int x) {
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i)) sum += c[i];
	return sum;
}
void peekmidean(int v) {
	int l = 1, r = MAXN;
	while(l < r) {
		int mid = l + (r - l) / 2;
		if(getsum(mid) >= v) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
stack<int> s;
int main() {
	int n, t;
	char str[12];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", str);
		if(str[1] == 'u') {
			scanf("%d", &t);
			s.push(t);
			update(t, 1);
		} else if(str[1] == 'o') {
			if(s.empty()) printf("Invalid\n");
			else {
				update(s.top(), -1);
				printf("%d\n", s.top());
				s.pop();
			}
		} else {
			if(s.empty()) printf("Invalid\n");
			else peekmidean((s.size() + 1) / 2);
		}
	}
	return 0;
}
