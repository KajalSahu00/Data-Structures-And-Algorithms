// We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. Find the unique numbers in linear time without using any extra space.

#include<iostream>
using namespace std;
int a[100000];

int main() {
	int n;
	cin >> n;
	int x = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		x ^= a[i];
	}
	int i = 0, temp = x;
	while (temp) {
		int last_bit = temp & 1;
		if (last_bit) 
			break;
		i++;
	} 
	int mask = 1 << i;
	int p = 0, q = 0;
	for (int i=0; i<n; i++) {
		if (mask & a[i])
			p ^= a[i];
	}
	q = x ^ p;
	cout << min(p, q) << " " << max(p, q) << endl;
	return 0;
}