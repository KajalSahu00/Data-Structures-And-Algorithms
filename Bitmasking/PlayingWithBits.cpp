// task is to count the no of set-bits in for all numbers between a and b (both inclusive)

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
	int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		int set_bits = 0;
		for (int i=a; i<=b; i++)
			set_bits += count_set_bits(i);
		cout << set_bits << endl;
	}
	return 0;
}