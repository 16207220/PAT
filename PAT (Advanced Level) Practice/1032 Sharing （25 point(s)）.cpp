#include<cstdio>
using namespace std;
const int MAXN = 1e6;
struct node {
	char data;
	int nextaddr;
	bool flag;
}word[MAXN];
int a, b, n, addr, data, nextaddr;
int main() {
	scanf("%d%d%d", &a, &b, &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%*c%c%d", &addr, &data, &nextaddr);
		word[addr].data = data, word[addr].nextaddr = nextaddr;
	}
	while(a != -1) {
		word[a].flag = true;
		a = word[a].nextaddr;
	}
	while(b != -1) {
		if(word[b].flag) {
			printf("%05d", b);
			break;
		}
		b = word[b].nextaddr;
	}
	if(b == -1) printf("-1");
	return 0;
}
