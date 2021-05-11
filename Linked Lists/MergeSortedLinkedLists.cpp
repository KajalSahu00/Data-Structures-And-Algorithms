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
	int n, i = 0;
	cin >> n;
	while (i < n) {
		int data;
		cin >> data;
		insertAtTail(head, data);
		i++;
	}
	return n;
}

void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

node* mergeList(node* head1, node* head2) {
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	node* temp = NULL;
	if (head1->data <= head2->data) {
		temp = new node(head1->data);
		temp->next = mergeList(head1->next, head2);
	}
	else {
		temp = new node(head2->data);
		temp->next = mergeList(head1, head2->next);
	}
	return temp;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		node* head1 = NULL;
		node* head2 = NULL;
		int n = buildList(head1);
		int m = buildList(head2);
		node* temp = mergeList(head1, head2);
		print(temp);
		cout << endl;
	}
	return 0;
}