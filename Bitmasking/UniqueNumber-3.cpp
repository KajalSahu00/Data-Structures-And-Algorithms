// We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once. Find the unique number. Only use - bitwise operators, and no extra space.

#include<iostream>
#include<cmath>
using namespace std;
int cnt[64] = {0};

int main() {
	int n, no, last_bit;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> no;
		int j = 0;
		while (no) {
			last_bit = no & 1;
			no = no >> 1;
			if (last_bit)
				cnt[j]++;
			j++;
		}
	}
	int ans = 0;
	for (int i=0; i<64; i++) {
		if (cnt[i] % 3) 
			ans += pow(2, i);
	}
	cout << ans << endl;
	return 0;
}