#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
set<int> res;
int getsum(int x) {
	int ret = 0;
	while(x) ret += x % 10, x /= 10; 
	return ret;
}
int n, x;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		res.insert(getsum(x));
	}
	printf("%d\n", res.size());
	for(set<int>::iterator it = res.begin(); it != res.end(); ++it) {
		if(it != res.begin()) printf(" ");
		printf("%d", *it);
	}
	return 0;
} 
