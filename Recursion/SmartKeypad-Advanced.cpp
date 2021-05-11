#include<iostream>
#include<string>
#include<vector>
using namespace std;
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
vector<string> v;

void possible_codes(string s, string out, int i) {
	if (i == s.length()) {
		v.push_back(out);
		return;
	}
	int digit = s[i] - '0';
	for (auto ch: table[digit])
		possible_codes(s, out + ch, i+1);
}

int main() {
	string s;
	cin >> s;
	possible_codes(s, "", 0);
	int n = s.length();
	for (auto word: searchIn) {
		bool flag = false;
		for (auto code: v) {
			for (int i=0; i<word.length()-n; i++) {
				if (word.substr(i, n) == code) {
					cout << word << endl;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
	}
	return 0;
}