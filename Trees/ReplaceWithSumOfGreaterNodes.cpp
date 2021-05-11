#include<iostream>
using namespace std;

class node {
	public:
		int data;
		node* left;
		node* right;
		node(int d) {
			data = d;
			left = NULL;
			right = NULL;
		}
};

node* build(int a[], int s, int e) {
	if (s > e)
		return NULL;
	int mid = (s + e) / 2;
	node* root = new node(a[mid]);
	root->left = build(a, s, mid-1);
	root->right = build(a, mid+1, e);
	return root;
}

void print(node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

node* replaceWithSum(node* root, int &sum) {
	if (root == NULL)
		return NULL;
	replaceWithSum(root->right, sum);
	sum += root->data;
	root->data = sum;
	replaceWithSum(root->left, sum);
	return root;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	node* root = build(a, 0, n-1);
	int sum = 0;
	root = replaceWithSum(root, sum);
	print(root);
	return 0;
}