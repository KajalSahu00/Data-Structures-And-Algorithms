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

node* build(string s) {
	if (s == "true") {
		int d;
		cin >> d;
		node* root = new node(d);
		string l;
		cin >> l;
		if (l == "true") {
			root->left = build(l);
		}
		string r;
		cin >> r;
		if (r == "true") {
			root->right = build(r);
		}
		return root;
	}
	return NULL;
}

void print(node* root) {
	if (root == NULL)
		return;
	print(root->left);
	cout << root->data << endl;
	print(root->right);
}

bool isIdentical(node* root1, node* root2) {
	if (root1 == NULL && root2 == NULL)
		return true;
	if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL))
		return false;
	bool lr = isIdentical(root1->left, root2->left);
	bool rr = isIdentical(root1->right, root2->right);
	if (lr && rr)
		return true;
	return false;
}

int main() {
	node* root1 = build("true");
	node* root2 = build("true");
	if (isIdentical(root1, root2))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}