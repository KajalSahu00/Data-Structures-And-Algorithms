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

node* build() {
	int d, n;
	cin >> d >> n;
	node* root = new node(d);
	if (n == 0) {
		return root;
	}else if (n == 1) {
		root->left = build();
		return root;
	}else {
		root->left = build();
		root->right = build();
		return root;
	}
}

void print(node* root) {
	if (root == NULL)
		return;
	cout << root->data << endl;
	print(root->left);
	print(root->right);
}

void findSum(node* root, int level, int &sum) {
	if (root == NULL || level < 0)
		return;
	if (level == 0) 
		sum += root->data;
	findSum(root->left, level-1, sum);
	findSum(root->right, level-1, sum);
}

int main() {
	node* root = build();
	int level;
	cin >> level;
	int sum = 0;
	findSum(root, level, sum);
	cout << sum << endl;
	return 0;
}