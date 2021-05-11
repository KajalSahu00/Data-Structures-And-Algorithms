// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. 
// Write a recursive function which returns the last index at which M is found in the array and -1 if M is not found anywhere. 
// Print the value returned.

#include<iostream>
using namespace std;

int binary_search(int a[], int s, int e, int ans, int key) {
	if (s > e) {
		if (ans != -1)
			return ans;
		return -1;
	}
	int mid = (s + e) / 2;
	if (a[mid] == key) 
		return binary_search(a, mid+1, e, mid, key);
	else if (a[mid] < key)
		return binary_search(a, mid+1, e, ans, key);
	else
		return binary_search(a, s, mid-1, ans, key);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	int key;
	cin >> key;
	cout << binary_search(a, 0, n-1, -1, key) << endl;
	return 0;
}