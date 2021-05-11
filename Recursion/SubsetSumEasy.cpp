// find whether if the sum of any of the non-empty subsets of the set A is zero.

#include<iostream>
using namespace std;

bool subset_sum_zero(int a[], int i, int sum, int n, int cnt) {
	if (i == n) {
		if (sum == 0 && cnt > 0)
			return true;
		return false;
	}
	if (subset_sum_zero(a, i+1, sum, n, cnt) || subset_sum_zero(a, i+1, sum+a[i], n, cnt+1))
		return true;
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++)
			cin >> a[i];
		if (subset_sum_zero(a, 0, 0, n, 0))
			cout << "Yes" << endl;
		else 
			cout << "No" << endl; 
	}
	return 0;
}