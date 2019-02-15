#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node {
	node *l, *r;
	int v;
};
node* rotateLeft(node* root) {
	node* t = root->r;
	root->r = t->l;
	t->l = root;
	return t; 
}
node* rotateRight(node* root) {
	node* t = root->l;
	root->l = t->r;
	t->r = root;
	return t;
}
node* rotateLeftRight(node* root) {
	root->l = rotateLeft(root->l);
	root = rotateRight(root);
	return root;
}
node* rotateRightLeft(node* root) {
	root->r = rotateRight(root->r);
	root = rotateLeft(root);
	return root;
}
int getHeight(node* root) {
	if(root == NULL) return 0;
	return max(getHeight(root->l), getHeight(root->r)) + 1;
}
node* insert(node* root, int v) {
	if(root == NULL) {
		root = new node();
		root->v = v;
		root->l = root->r = NULL;
		return root;
	}
	if(root->v > v) {
		root->l = insert(root->l, v);
		int l = getHeight(root->l);
		int r = getHeight(root->r);
		if(l - r >= 2) {
			if(v < root->l->v) root = rotateRight(root);
			else root = rotateLeftRight(root);
		}
 	}else {
 		root->r = insert(root->r, v);
 		int l = getHeight(root->l);
		int r = getHeight(root->r);
		if(r - l >= 2) {
			if(v < root->r->v) root = rotateRightLeft(root);
			else root = rotateLeft(root); 
		}
	}
	return root; 
}
bool complete = true;
vector<int> getlevel(node* root) {
	queue<node*> q;
	vector<int> ret;
	q.push(root);
	bool flag = false;
	while(!q.empty()) {
		root = q.front(); q.pop();
		ret.push_back(root->v);
		if(root->l != NULL) {
			if(flag) complete = false;
			q.push(root->l);
		} else flag = true;
		if(root->r != NULL) {
			if(flag) complete = false;
			q.push(root->r);
		} else flag = true;
	}
	return ret;
}
int n, v;
int main() {
	scanf("%d", &n);
	node *root = NULL;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v);
		root = insert(root, v); 
	}
	vector<int> res = getlevel(root);
	for(int i = 0; i < res.size(); ++i) printf("%d%c", res[i], i == res.size() - 1 ? '\n' : ' ');
	if(complete) printf("YES\n");
	else printf("NO\n");
	return 0;
}
