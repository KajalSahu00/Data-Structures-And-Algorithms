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

void print(node* root) {
	if (root == NULL)
		return;
	if (root->left != NULL)
		cout << root->left->data << " => ";
	else
		cout << "END => ";
	cout << root->data;
	if (root->right != NULL)
		cout << " <= " << root->right->data << endl;
	else
		cout << " <= END" << endl;
	print(root->left);
	print(root->right);
}

int main() {
	int n;
	cin >> n;
	int pre[n];
	for (int i=0; i<n; i++)
		cin >> pre[i];
	cin >> n;
	int in[n];
	for (int i=0; i<n; i++)
		cin >> in[i];
	node* root = build(pre, in, 0, n-1);
	print(root);
	return 0;
}