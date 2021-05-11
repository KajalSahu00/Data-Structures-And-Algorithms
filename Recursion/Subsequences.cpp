// Print all the subsequences in a space separated manner and isplay the total no. of subsequences.

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void subsequences(string s, string out, int i) {
	if (i == s.length()) {
		cout << out << " ";
		return;
	}
	subsequences(s, out, i+1);
	subsequences(s, out+s[i], i+1);
	return;
}

int main() {
	string s;
	cin >> s;
	int cnt = pow(2, s.length());
	subsequences(s, "", 0);
	cout << endl << cnt << endl;
	return 0;
}