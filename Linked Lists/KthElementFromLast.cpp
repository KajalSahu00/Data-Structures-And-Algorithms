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

void buildList(node* &head) {
	int data;
	while (cin >> data) {
		if (data == -1)
			break;
		insertAtTail(head, data);
	}
}

void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

node* kth_element(node* head, int k) {
	node* slow = head, *fast = head;
	while (k--) {
		fast = fast->next;
	}
	while (fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main() {
	int k;
	node* head = NULL;
	buildList(head);
	// print(head);
	cin >> k;
	node* temp = kth_element(head, k);
	cout << temp->data << endl;
	return 0;
}