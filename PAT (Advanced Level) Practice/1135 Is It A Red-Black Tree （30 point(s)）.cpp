#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> pre;
int n, k;
struct node {
	node *l, *r;
	int v;
};
node* build(node* root, int v) {
	if(root == NULL) {
		root = new node();
		root->l = root->r = NULL;
		root->v = v;
		return root;
	}
	if(abs(v) < abs(root->v)) root->l = build(root->l, v);
	else root->r = build(root->r, v);
	return root;
} 
int getBlackNum(node* root) {
	if(root == NULL) return 0;
	int l = getBlackNum(root->l);
	int r = getBlackNum(root->r);
	return root->v > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge4(node* root) {
	if(root == NULL) return true;
	if(root->v < 0) {
		if(root->l != NULL && root->l->v < 0) return false;
		if(root->r != NULL && root->r->v < 0) return false;
	}
	return judge4(root->l) && judge4(root->r);
}
bool judge5(node* root) {
	if(root == NULL) return true;
	int l = getBlackNum(root->l);
	int r = getBlackNum(root->r);
	if(l != r) return false;
	return judge5(root->l) && judge5(root->r);
}
int main() {
	scanf("%d", &k);
	for(int i = 0; i < k; ++i) {
		scanf("%d", &n); pre.resize(n);
		node* root = NULL;
		for(int j = 0; j < n; ++j) {
			scanf("%d", &pre[j]);
			root = build(root, pre[j]);
		}
		if(pre[0] < 0 || !judge4(root) || !judge5(root)) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
