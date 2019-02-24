#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 110;
int a[MAXN], t[MAXN];
int n;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &t[i]);
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			fill(a, a + MAXN, 1);
			a[i] = a[j] = -1; // ¼ÙÉèi, jÊÇÀÇÈË¡£
			vector<int> lie;
			for(int k = 1; k <= n; ++k) if(t[k] * a[abs(t[k])] < 0) lie.push_back(k);
			if(lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
				printf("%d %d\n", i, j);
				return 0;
			}
		}
	} 
	printf("No Solution\n");
	return 0;
}
