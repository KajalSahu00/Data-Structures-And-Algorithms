// We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. 
// Given a number, you have to print all the possible strings.

#include<iostream>
using namespace std;
char a[] = {'0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 
'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void possible_strings(string s, int i, string out) {
	if (i == s.length()) {
		cout << out << endl;
		return;
	}
	int first = s[i]-'0';
	possible_strings(s, i+1, out + a[first]);
	if (i+1 != s.length()) {
		int second = s[i+1]-'0';
		int num = first*10+second;
		if (num <= 26)
			possible_strings(s, i+2, out + a[num]);
	}
}

int main() {
	string s;
	cin >> s;
	possible_strings(s, 0, "");
	return 0;
}