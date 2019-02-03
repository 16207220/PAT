#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string t = "0123456789ABC";
int main() {
	int n;
	printf("#");
	for(int i = 0; i < 3; ++i) {
		scanf("%d", &n);
		printf("%c%c", t[n / 13], t[n % 13]);
	}
	return 0;
} 
