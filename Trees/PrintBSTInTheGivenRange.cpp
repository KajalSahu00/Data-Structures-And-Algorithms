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

node* buildBST(node* root, int data) {
	if (root == NULL)
		return new node(data);
	if (data < root->data) 
		root->left = buildBST(root->left, data);
	else
		root->right = buildBST(root->right, data);
	return root;
}

void print(node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}

void printInRange(node* root, int k1, int k2) {
	if (root == NULL)
		return;
	printInRange(root->left, k1, k2);
	if (root->data >= k1 && root->data <= k2)
		cout << root->data << " ";
	printInRange(root->right, k1, k2);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, data;
		cin >> n;
		node* root = NULL;
		for (int i=0; i<n; i++) {
			cin >> data;
			root = buildBST(root, data);
		}
		int k1, k2;
		cin >> k1 >> k2;
		cout << "# Preorder : ";
		print(root);
		cout << endl << "# Nodes within range are : ";
		printInRange(root, k1, k2);
		cout << endl;
	}
	return 0;
}