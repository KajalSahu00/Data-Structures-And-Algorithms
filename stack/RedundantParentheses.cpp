#include<iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	string s;
	bool duplicate = false;
	while (t--) {
		duplicate = false;
		cin >> s;
		stack<char> st;
		for (auto ch: s) {
			if (ch == ')') {
				if (st.top() == '(') {
					duplicate = true;
					break;
				}
				while (!st.empty() && st.top() != '(') {
					st.pop();
				}
				if (!st.empty() && st.top() == '(') 
					st.pop();
			}else {
				st.push(ch);
			}
		}
		if (duplicate)
			cout << "Duplicate" << endl;
		else
			cout << "Not Duplicates" << endl;
	}
	return 0;
}