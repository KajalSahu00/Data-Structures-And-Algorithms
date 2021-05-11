// Take as input str, a string. Write a recursive function which returns a new string in which all duplicate consecutive characters are separated by a ‘ * ’. E.g. for “hello” return “hel*lo”. Print the value returned

#include<bits/stdc++.h>
using namespace std;

void separate_duplicates(string in, string &out, int i, int n) {
	if (i == n) {
		return;
	}
	if (i != n-1 && in[i] == in[i+1]) {
		out += in[i];
		out += '*';
	}else {
		out += in[i];
	}
	separate_duplicates(in, out, i+1, n);
}

int main() {
	string s;
	cin >> s;
	string out = "";
	separate_duplicates(s, out, 0, s.length());
	cout << out << endl;
	return 0;
}