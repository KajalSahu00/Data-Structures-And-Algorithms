#include<iostream>
using namespace std;
int a[10];

int binary_search(int s, int e, int key) {
	if (s > e)
		return -1;
	int mid = (s+e) / 2;
	if (a[mid] == key)
		return mid;
	if (a[mid] > key)
		return binary_search(s, mid-1, key);
	return binary_search(mid+1, e, key);
} 

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int key;
	cin >> key;
	cout << binary_search(0, n-1, key) << endl;
	return 0;
}