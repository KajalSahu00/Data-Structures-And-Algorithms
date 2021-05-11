// count number of 1s in binary representation of an integer

#include<iostream>
using namespace std;

int count_set_bits(int n) {
	int ans = 0;
	while (n) {
		n = n & (n-1);
		ans++;
	}
	return ans;
}

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << count_set_bits(n) << endl;
	}
	return 0;
}