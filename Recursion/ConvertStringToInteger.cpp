// Take as input str, a number in form of a string. Write a recursive function to convert the number in string form to number in integer form. 
// E.g. for “1234” return 1234. Print the value returned.

#include<iostream>
#include<cmath>
using namespace std;

int convert_to_int(string s, int i, int power, int n, int ans) {
	if (i < 0)
		return ans;
	int last_digit = s[i] -'0';
	ans = ans + (last_digit * pow(10, power));
	return convert_to_int(s, i-1, power+1, n, ans);
}

int main() {
	string s;
	cin >> s;
	cout << convert_to_int(s, s.length()-1, 0, s.length(), 0) << endl;
	return 0;
}