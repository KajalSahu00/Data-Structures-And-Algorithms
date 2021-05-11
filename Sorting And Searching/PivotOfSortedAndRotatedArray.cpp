#include<iostream>
using namespace std;
int a[100000];

int pivot_element(int n) {
	int s = 0, e = n-1, ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (mid != n-1 && a[mid] > a[mid+1]) {
			ans = mid;
			break;
		}else if (a[s] <= a[mid]) {
			s = mid + 1;
		}else {
			e = mid - 1;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cout << pivot_element(n) << endl;
	return 0;
}