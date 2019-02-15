#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1e3 + 10;
int level[MAXN];
int maxdepth, n;
struct node {
	node *l, *r;
	int v;
}; 
node* build(int depth, int v, node* root) {
	maxdepth = max(maxdepth, depth); //找到最深处
	if(root == NULL) {
		level[depth]++;
		root = new node();
		root->l = root->r = NULL;
		root->v = v;
		return root;
	}
	if(root->v >= v) root->l = build(depth + 1, v, root->l);
	else root->r = build(depth + 1, v, root->r);
	return root;
}
int main() {
	scanf("%d", &n);
	int v;
	node* root = NULL;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v);
		root = build(1, v, root);
	}
	printf("%d + %d = %d\n", level[maxdepth], level[maxdepth - 1], level[maxdepth] + level[maxdepth - 1]);
	return 0;
}
