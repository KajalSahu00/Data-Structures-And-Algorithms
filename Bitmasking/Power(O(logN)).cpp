// Take as input x and n, two numbers. Write a function to calculate x raise to power n. Target complexity is O(logn). Try bitmasking approach.

#include<iostream>
using namespace std;
#define ll long long int

int main() {
	ll x, n;
	cin >> x >> n;
	ll ans = 1;
	while (n) {
		int last_bit = n & 1;
		if (last_bit)
			ans *= x;
		x *= x;
		n = n>>1;
	}
	cout << ans << endl;
	return 0;
}