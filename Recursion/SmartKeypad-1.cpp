// You will be given a numeric string S. Print all the possible codes for S.
// Following vector contains the codes corresponding to the digits mapped.
// string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

#include<iostream>
using namespace std;
string a[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void possible_codes(string s, string out, int i) {
	if (i == s.length()) {
		cout << out << endl;
		return;
	}
	int digit = s[i] - '0';
	for (auto ch: a[digit]) 
		possible_codes(s, out+ch, i+1);
}

int main() {
	string s;
	cin >> s;
	possible_codes(s, "", 0);
	return 0;
}