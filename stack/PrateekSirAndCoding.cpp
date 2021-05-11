#include<iostream>
#include<stack>
using namespace std;

int main () {
	int n;
	cin >> n;
	int q, c;
	stack<int> s;
	for (int i=0; i<n; i++) {
		cin >> q;
		if (q == 1) {
			if (!s.empty()) {
				cout << s.top() << endl;
				s.pop();
			}else
				cout << "No Code" << endl;
		}else {
			cin >> c;
			s.push(c);
		}
	}
	return 0;
}