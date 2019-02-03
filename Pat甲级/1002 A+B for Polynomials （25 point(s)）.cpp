#include<cstdio>
#define EPS 1e-6
using namespace std;
int k, n;
float a;
float result[1010];
int main() {
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d%f", &n, &a);
		result[n] += a;
	} 
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d%f", &n, &a);
		result[n] += a;
	} 
	int cnt = 0;
	for(int i = 0; i < 1001; ++i)  if(result[i] < -EPS || result[i] > EPS) ++cnt;
	printf("%d", cnt);
	for(int i = 1000; i >= 0; --i) if(result[i] < -EPS || result[i] > EPS) printf(" %d %.1f", i, result[i]);
	return 0;
}
