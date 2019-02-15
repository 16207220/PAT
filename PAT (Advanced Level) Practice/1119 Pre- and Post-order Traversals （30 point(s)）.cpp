#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> pre, in, post;
bool unique = true;
void getin(int prel, int prer, int postl, int postr) {
	if(prel == prer) {
		in.push_back(pre[prel]);
		return;
	}
	int i = prel + 1;
	while(i <= prer && pre[i] != post[postr - 1]) ++i;
	if(i != prel + 1) getin(prel + 1, i - 1, postl, postl + i - prel - 1 - 1);
	else unique = false;
	in.push_back(pre[prel]);
	getin(i, prer, postl + i - prel - 1, postr - 1);
}
int n;
int main() {
	scanf("%d", &n);
	pre.resize(n); post.resize(n);
	for(int i = 0; i < n; ++i) scanf("%d", &pre[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &post[i]);
	getin(0, n - 1, 0, n - 1);
	printf("%s\n", unique ? "Yes" : "No");
	for(int i = 0; i < n; ++i) printf("%d%c", in[i], i == n - 1 ? '\n' : ' ');
	return 0;
}
