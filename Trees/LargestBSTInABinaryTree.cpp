#include<iostream>
#include<climits>
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

int i = 0;
node* build(int pre[], int in[], int s, int e) {
	if (s > e) 
		return NULL;
	int j;
	for (j=s; j<=e; j++) {
		if (pre[i] == in[j])
			break;
	}
	i++;
	node* root = new node(in[j]);
	root->left = build(pre, in, s, j-1);
	root->right = build(pre, in, j+1, e);
	return root;
}

bool isBST(node* root, int min_val, int max_val) {
	if (root == NULL)
		return true;
	if (root->data >= min_val && root->data < max_val && isBST(root->left, min_val, root->data) && isBST(root->right, root->data, max_val))
		return true;
	return false;
}

int numberOfNodes(node* root) {
	if (root == NULL)
		return 0;
	return numberOfNodes(root->left) + numberOfNodes(root->right) + 1;
}

int largestBST(node* root) {
	if (isBST(root, INT_MIN, INT_MAX)) 
		return numberOfNodes(root);
	return max(largestBST(root->left), largestBST(root->right));
}

int main() {
	int n;
	cin >> n;
	int pre[n], in[n];
	for (int i=0; i<n; i++)
		cin >> pre[i];
	for (int i=0; i<n; i++)
		cin >> in[i];
	node* root = build(pre, in, 0, n-1);
	int size = largestBST(root);
	cout << size << endl;
	return 0;
}