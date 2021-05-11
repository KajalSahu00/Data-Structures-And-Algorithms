#include<iostream>
#include<algorithm>
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
	int mid = (s+e)/2;
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

node* deleteNode(node* root, int data) {
	if (root == NULL)
		return NULL;
	else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	}else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	}else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}else if (root->left != NULL && root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}else if (root->left == NULL && root->right != NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}else {
			node* temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++)
			cin >> a[i];
		sort(a, a+n);
		node* root = build(a, 0, n-1);
		int m, data;
		cin >> m;
		for (int i=0; i<m; i++) {
			cin >> data;
			root = deleteNode(root, data);
		}
		print(root);
	}
	return 0;
}