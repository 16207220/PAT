#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	string result = to_string(a + b);
	int len = result.length();
	for(int i = 0; i < len; ++i) {
		printf("%c", result[i]);
		if(result[i] == '-') continue;
		if((i + 1) % 3 == len % 3 && len - 1 != i) printf(",");
	}
	return 0;
} 
