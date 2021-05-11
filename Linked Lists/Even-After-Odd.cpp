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

node* evenAfterOdd(node* head) {
	node* temp = NULL;
	node* res = NULL;
	node* curr = head;
	while (curr != NULL) {
		if (curr->data % 2) {
			if (temp == NULL) {
				temp = new node(curr->data);
				res = temp;
			}else {
				temp->next = new node(curr->data);
				temp = temp->next;
			}
		}
		curr = curr->next;
	}
	curr = head;
	while (curr != NULL) {
		if (curr->data % 2 == 0) {
			temp->next = new node(curr->data);
			temp = temp->next;
		}
		curr = curr->next;
	}
	temp->next = NULL;
	return res;
}

void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

int main() {
	int n;
	cin >> n;
	node* head = NULL;
	buildList(head, n);
	node* temp = evenAfterOdd(head);
	print(temp);
	return 0;
}