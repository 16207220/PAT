#include<iostream>
#include<cstdio>
using namespace std;
int n, t, current, request;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &request);
		if(request > current) t += (request - current) * 6;
		else if(request < current) t += (current - request) * 4;
		current = request;
		t += 5;
	}
	printf("%d", t);
	return 0;
}
