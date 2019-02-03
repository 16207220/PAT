#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string t = "WTL";
int main() {
	float res = 1.0;
	for(int i = 0; i < 3; ++i) {
		int index;
		float maxTemp = 0, temp; 
		for(int j = 0; j < 3; ++j) {
			scanf("%f", &temp);
			if(temp > maxTemp) {
				maxTemp = temp;
				index = j;
			}
		}
		printf("%c ", t[index]);
		res *= maxTemp;
	}
	res = (res * 0.65 - 1) * 2;
	printf("%.2f", res);
	return 0;
}
