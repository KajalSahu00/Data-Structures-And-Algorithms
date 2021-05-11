#include<iostream>
#include<set>
using namespace std;

void tricky_permutations(string s, int i, set<string> &us) {
	if (i == s.length()) {
		us.insert(s);
		return;
	}
	for (int j=i; j<s.length(); j++) {
		swap(s[i], s[j]);
		tricky_permutations(s, i+1, us);
		swap(s[i], s[j]);
	}
}

int main() {
	string s;
	cin >> s;
	set<string> us;
	tricky_permutations(s, 0, us);
	for (auto it: us) 
		cout << it << endl;
	return 0;
}