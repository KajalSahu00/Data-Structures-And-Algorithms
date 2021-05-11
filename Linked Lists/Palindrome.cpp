#include<iostream>
using namespace std;

class node {
	public:
	int data;
	node* next;
	node* prev;
	node(int d) {
		data = d;
		next = NULL;
		prev = NULL;
	}
};

void insertAtTail(node* &tail, int data, node* &head) {
	if (tail == NULL) {
		head = tail = new node(data);
		return;
	}
	node* lastNode = new node(data);
	tail->next = lastNode;
	lastNode->prev = tail;
	tail = lastNode;
}

void buildList(node* &head, node* &tail) {
	int data;
	while (cin >> data) {
		insertAtTail(tail, data, head);
	}
}

void print(node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	print(head->next);
}

void printReverse(node* tail, node* head) {
	if (tail == head) {
		cout << tail->data << " ";
		return;
	}
	cout << tail->data << " ";
	printReverse(tail->prev, head);
}

bool palindrome(node* head, node* tail) {
	if (tail == head || tail->next == head || head->prev == tail) 
		return true;
	if (head->data != tail->data) 
		return false;
	return palindrome(head->next, tail->prev);
}

int main() {
	int n;
	cin >> n;
	node* head = NULL;
	node* tail = NULL;
	buildList(head, tail);
	if (palindrome(head, tail))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}