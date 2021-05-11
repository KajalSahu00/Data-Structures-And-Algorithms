#include<iostream>
#include<queue>
#include<map>
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

node* buildTree() {
	int x;
	cin >> x;
	node* root = new node(x);
	queue<node*> q;
	q.push(root);
	while (!q.empty()) {
		node* temp = q.front();
		q.pop();
		cin >> x;
		if (x != -1) {
			temp->left = new node(x);
			q.push(temp->left);
		}
		cin >> x;
		if (x != -1) {
			temp->right = new node(x);
			q.push(temp->right);
		}
	}
	return root;
}

void print(node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	print(root->left);
	print(root->right);
}
map<int, pair<int, int>> m;
void printBottom(node* root, int d, int h) {
	if (root == NULL)
		return;
	if (m[d].second <= h) {
		m[d].second = h;
		m[d].first = root->data;
	}
	printBottom(root->left, d-1, h+1);
	printBottom(root->right, d+1, h+1);
}

int main() {
	node* root = buildTree();
	printBottom(root, 0, 0);
	for (auto p: m) {
		cout << p.second.first << " ";
	}
	return 0;
}