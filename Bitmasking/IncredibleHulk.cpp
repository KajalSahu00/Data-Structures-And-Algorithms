#include<iostream>
using namespace std;

int count_set_bits(int n) {
	int ans = 0;
	while(n) {
		n = n & (n-1);
		ans++;
	}
	return ans;
}

int main() {
	int t, n, ans;
	cin >> t;
	while(t--) {
		cin >> n;
		ans = count_set_bits(n);
		cout << ans << endl;
	}
	return 0;
}