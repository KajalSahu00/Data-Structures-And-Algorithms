#include<iostream>
using namespace std;

class node {
	public:
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtTail(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}
	node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new node(data);
}

void buildList(node* &head, int n) {
	while (n--) {
		int data;
		cin >> data;
		insertAtTail(head, data);
	}
}

void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

node* reverse(node* head, int k) {
	int n = k;
	node* prev = NULL;
	node* curr = head, *next = NULL;
	while (curr != NULL && n--) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	if (next != NULL)
		head->next = reverse(next, k);
	return prev;
}

int main() {
	int n, k;
	cin >> n >> k;
	node* head = NULL;
	buildList(head, n);
	head = reverse(head, k);
	print(head);
	return 0;
}