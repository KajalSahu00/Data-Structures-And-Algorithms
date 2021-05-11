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

int buildList(node* &head) {
	int n;
	cin >> n;
	int i = 0;
	while (i < n) {
		int data;
		cin >> data;
		insertAtTail(head, data);
		i++;
	}
	return n;
}

void print(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

node* buildNewList(node* head, int x) {
	node* temp = head;
	while (x-- && temp != NULL) 
		temp = temp->next;
	node* second = temp->next;
	temp->next = NULL;
	return second;
}

int main() {
	int k;
	node* head = NULL;
	int n = buildList(head);
	cin >> k;
	k = k%n;
	int x = n-k-1;
	node* temp = buildNewList(head, x);
	print(temp);
	print(head);
	return 0;
}