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

node* build() {
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

map<int, int> m;
void topRightView(node* root, int level) {
	if (root == NULL)
		return;
	if (m.find(level) == m.end()) 
		m[level] = root->data;
	topRightView(root->right, level+1);
	topRightView(root->left, level+1);
}

int main() {
	node* root = build();
	topRightView(root, 0);
	for (auto p: m) 
		cout << p.second << " ";
	return 0;
}