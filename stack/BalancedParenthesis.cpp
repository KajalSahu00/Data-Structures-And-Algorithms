#include<iostream>
#include<stack>
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> st;
	bool balanced = true;
	for (auto ch: s) {
		if (ch == '(')
			st.push(ch);
		else {
			if (!st.empty() && st.top() == '(')
				st.pop();
			else {
				balanced = false;
				break;
			}
		}
	}
	if (balanced)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}