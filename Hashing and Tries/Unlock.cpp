#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	unordered_map<int, int> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		m[a[i]] = i;
	}
	int temp = n, i = 0;
	while (k && i<n) {
		if (a[i] != temp) {
			m[a[i]] = m[temp];
			swap(a[i], a[m[a[i]]]);
			k--;
		}
		i++;
		temp--;
	}
	for (auto x: a)
		cout << x << " ";
	return 0;
}