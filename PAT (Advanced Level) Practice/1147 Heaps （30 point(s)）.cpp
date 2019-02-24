#include<cstdio>
using namespace std;
const int MAXN = 1e3 + 10;
int n, m;
int t[MAXN];
void getpost(int root) {
	if(root > n) return;
	getpost(root<<1);
	getpost(root<<1|1);
	printf("%d%c", t[root], root == 1 ? '\n' : ' '); 
}
bool isMaxHeap() {
	for(int i = n; i > 1; --i) if(t[i] > t[i / 2]) return false;
	return true;
}
bool isMinHeap() {
	for(int i = n; i > 1; --i) if(t[i] < t[i / 2]) return false;
	return true;
}
int main() {
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; ++i) {
		for(int j = 1; j <= n; ++j) scanf("%d", &t[j]);
		printf("%s\n", isMinHeap() ? "Min Heap" : (isMaxHeap() ? "Max Heap" : "Not Heap"));
		getpost(1);
	}
	return 0;
}
