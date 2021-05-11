// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which 
// returns an array containing indices of all items in the array which have value equal to M. Print all the values in the returned array.

#include<iostream>
using namespace std;

void all_indices(int a[], int i, int n, int key) {
	if (i == n)
		return;
	if (a[i] == key)
		cout << i << " ";
	all_indices(a, i+1, n, key);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	int key;
	cin >> key;
	all_indices(a, 0, n, key);
	return 0;
}