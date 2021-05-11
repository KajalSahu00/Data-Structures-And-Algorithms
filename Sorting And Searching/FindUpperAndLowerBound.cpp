#include<iostream>
using namespace std;
int a[1000000];

int first_occurence(int n, int key) {
	int s = 0, e = n-1, ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			e = mid - 1;
		}else if (a[mid] > key) 
			e = mid - 1;
		else 
			s = mid + 1;
	}
	return ans;
}

int last_occurence(int n, int key) {
	int s = 0, e = n-1, ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			s = mid + 1;
		}else if (a[mid] > key) 
			e = mid - 1;
		else 
			s = mid + 1;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int q, key;
	cin >> q;
	while (q--) {
		cin >> key;
		cout << first_occurence(n, key) << " ";
		cout << last_occurence(n, key) << endl;
	}
	return 0;
}