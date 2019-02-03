#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int MAXN = 30; // 30 * 3 > 80
int n1, n2;
char a[MAXN][MAXN];
string t;
int main() {
	cin >> t;
	memset(a, ' ', sizeof(a));
	n1 = (t.size() + 2) / 3, n2 = (t.size() + 2) / 3 + (t.size() + 2) % 3;
	for(int i = 0; i < n1; ++i) a[i][0] = t[i];
	for(int i = 1; i <= n2 - 2; ++i) a[n1 - 1][i] = t[n1 + i - 1];
	for(int i = n1 - 1; i >= 0; --i) a[i][n2 - 1] = t[t.size() - i - 1];
	for(int i = 0; i < n1; ++i) {
		for(int j = 0; j < n2; ++j) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

