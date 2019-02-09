#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> a, b;
void dowajust(int i, int n) {
	int j = 2 * i;
	while(j <= n) {
		if(j + 1 <= n && b[j] < b[j + 1]) ++j;
		if(b[j] > b[i]) {
			swap(b[i], b[j]);
			i = j; j *= 2;
		}
		else break; 
	}
} 
int main() {
	scanf("%d", &n);
	a.resize(n + 1); b.resize(n + 1);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	int p = 2;
	while(p <= n && b[p - 1] <= b[p]) ++p;
	int m = p;
	while(p <= n && a[p] == b[p]) ++p;
	if(p == n + 1) {
		printf("Insertion Sort\n");
		sort(b.begin() + 1, b.begin() + m + 1);
	} else {
		printf("Heap Sort\n");
		p = n;
		while(p > 1 && b[p - 1] <= b[p]) --p;
		swap(b[1], b[p]);
		dowajust(1, p - 1);
	}
	for(int i = 1; i <= n; ++i) printf("%d%c", b[i],  i == n ? '\n' : ' ');
}
