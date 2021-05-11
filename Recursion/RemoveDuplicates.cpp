// Take as input S, a string. Write a function that removes all consecutive duplicates. Print the value returned.

#include<iostream>
using namespace std;

void remove_duplicates(char s[], int i) {
	if (s[i] == '\0')
		return;
	if (s[i] == s[i+1]) {
		int j = i+1;
		while (s[j] != '\0') {
			s[j] = s[j+1];
			j++;
		}
		remove_duplicates(s, i);
	}else
		remove_duplicates(s, i+1);
}

int main() {
	char s[1000];
	cin >> s;
	remove_duplicates(s, 0);
	cout << s << endl;
}