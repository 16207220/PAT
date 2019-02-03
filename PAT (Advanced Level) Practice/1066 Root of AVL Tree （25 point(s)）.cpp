#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
	int v;
	node *left, *right;
};
node *rotateLeft(node* root) {
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
} 
node* rotateRight(node* root) {
	node* t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node* rotateLeftRight(node* root) {
	root->left = rotateLeft(root->left);
	root = rotateRight(root);
	return root;
}
node* rotateRightLeft(node* root) {
	root->right = rotateRight(root->right);
	root = rotateLeft(root);
	return root;
}
int getHeight(node* root) {
	if(root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node* insert(node* root, int v) {
	if(root == NULL) {
		root = new node();
		root->v = v;
		root->left = root->right = NULL;
		return root;
	}
	if(root->v > v) {
		root->left = insert(root->left, v);
		int l = getHeight(root->left);
		int r = getHeight(root->right);
		if(l - r >= 2) {
			if(root->left->v > v) {
				root = rotateRight(root);
			} else {
				root = rotateLeftRight(root);
			}
		}
	} else {
		root->right = insert(root->right, v);
		int l = getHeight(root->left);
		int r = getHeight(root->right);
		if(r - l >= 2) root = v < root->right->v ? rotateRightLeft(root) : rotateLeft(root);
	}
	return root;
}
int main() {
	int n, v;
	scanf("%d", &n);
	node* root = NULL;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v);
		root = insert(root, v);
	}
	printf("%d\n", root->v);
	return 0;
}
