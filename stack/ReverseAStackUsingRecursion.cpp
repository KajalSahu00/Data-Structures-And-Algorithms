#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &s, int x) {
	if (s.empty()) {
		s.push(x);
		return;
	}
	int y = s.top();
	s.pop();
	insert(s, x);
	s.push(y);
}

void reverse(stack<int> &s) {
	if (s.empty())
		return;
	int x = s.top();
	s.pop();
	reverse(s);
	insert(s, x);
}

int main() {
	int n, x;
	cin >> n;
	stack<int> s;
	while (n--) {
		cin >> x;
		s.push(x);
	}
	reverse(s);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}