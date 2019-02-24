#include<iostream>
#include<set>
#include<cstdio>
using namespace std;
const int MAXN = 5e4 + 10;
struct node {
	int item, cnt;
	bool operator < (const node& rhs) const {
		return cnt != rhs.cnt ? cnt > rhs.cnt : item < rhs.item;
	}
};
set<node> s;
int n, k, x;
int book[MAXN];
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &x);
		if(i) {
			printf("%d:", x);
			int j = 0;
			for(set<node>::iterator it = s.begin(); it != s.end() && j < k; ++it, ++j) printf(" %d", (*it).item);
			printf("\n");			
		}
		if(book[x]) s.erase({x, book[x]});
		++book[x];
		s.insert({x, book[x]});
	}
}
