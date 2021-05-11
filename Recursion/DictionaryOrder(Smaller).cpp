// Take as input str, a string. Write a recursive function which returns all the words possible by rearranging the characters 
// of this string which are in dictionary order smaller than the given string. The output strings must be lexicographically sorted.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;

void permute(string s, int i) {
	if (i == s.length()) {
		v.push_back(s);
		return;
	}
	for (int j=i; j<s.length(); j++) {
		swap(s[i], s[j]);
		permute(s, i+1);
		swap(s[i], s[j]);
	}
}

void print(string s) {
	for (auto word: v) {
		if (word < s)
			cout << word << endl;
	}
}

int main() {
	string s;
	cin >> s;
	permute(s, 0);
	sort(v.begin(), v.end());
	print(s);
	return 0;
}