// Find the unique number without taking any extra spaces and in linear time.

#include<iostream>
using namespace std;

int main() {
	int n, temp;
	cin >> n;
	int ans = 0;
	while (n--) {
		cin >> temp;
		ans ^= temp;
	}
	cout << ans << endl;
	return 0;
}