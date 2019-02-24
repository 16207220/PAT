#include<cstdio>
#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, bool> have;
int n, x;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		have[x] = true;
	}
	int res;
	for(res = 1; ; ++res) if(!have[res]) break;
	printf("%d\n", res);
	return 0; 
}
