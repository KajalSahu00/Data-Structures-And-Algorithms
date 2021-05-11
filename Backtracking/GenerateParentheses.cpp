#include<iostream>
using namespace std;

void generate_brackets(int n, int open, int close, string out) {
	if (open == n && close == n) {
		cout << out << endl;
		return;
	}
	if (open > close && close < n)
		generate_brackets(n, open, close+1, out+')');
	if (open < n)
		generate_brackets(n, open+1, close, out+'(');
	return;
}

int main() {
	int n;
	cin >> n;
	generate_brackets(n, 0, 0, "");
	return 0;
}