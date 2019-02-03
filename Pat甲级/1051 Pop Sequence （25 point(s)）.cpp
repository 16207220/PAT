#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
const int MAXN = 1010;
int t[MAXN];
int n, m, k, x;
int main() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 0; i < k; ++i) {
		stack<int> s;
		queue<int> q;
		for(int j = 0; j < n; ++j) {
			scanf("%d", &x);
			q.push(x);
		}
		for(int j = 1; j <= n; ++j) {
			s.push(j);
			if(s.size() > m) break;
			while(!q.empty() && !s.empty() && s.top() == q.front()) {
				s.pop();
				q.pop();
			}
		}
		printf("%s\n", s.empty() ? "YES" : "NO");
	} 
	return 0;
}
