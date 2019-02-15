#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 50;
char a[MAXN], buf[MAXN];
int n, cnt;
double sum, t;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", buf);
		sscanf(buf, "%lf", &t);
		sprintf(a, "%.2f", t);
		bool flag = false;
		for(int j = 0; j < strlen(buf); ++j) if(a[j] != buf[j]) {
			flag = true;
			break;
		}
		if(flag || t < -1000 || t > 1000) {
			printf("ERROR: %s is not a legal number\n", buf);
			continue;
		}
		sum += t;
		++cnt;
	}
	if(cnt == 1) printf("The average of 1 number is %.2f\n", sum);
	else if(cnt == 0) printf("The average of 0 numbers is Undefined\n");
	else {
		printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
	}
	return 0;
}
