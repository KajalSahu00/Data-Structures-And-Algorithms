// Assume the following alphabets on the keys: 1 -> abc , 2 -> def , 3 -> ghi , 4 -> jkl , 5 -> mno , 6 -> pqrs , 7 -> tuv , 8 -> wx , 9 -> yz
// E.g. “12” can produce following words “ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf”
// a. Write a recursive function which returns the count of words for a given keypad string. Print the value returned.
// b.Write a recursive function which prints all possible words for a given keypad string (void is the return type for function).

#include<iostream>
using namespace std;
string a[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void keypad_codes(string s, int i, string out) {
	if (i == s.length()) {
		cout << out << " ";
		return;
	}
	int digit = s[i] - '0';
	for (auto ch: a[digit])
		keypad_codes(s, i+1, out + ch);
}

int main() {
	string s;
	cin >> s;
	keypad_codes(s, 0, "");
	cout << endl;
	int ans = 1;
	for (int i=0; i<s.length(); i++) {
		int digit = s[i] - '0';
		ans *= a[digit].length();
	}
	cout << ans << endl;
	return 0;
}