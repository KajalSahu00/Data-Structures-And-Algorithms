// Take as input N, the size of an integer array. Take one more input, which is a list of N integers separated by a space, and store that in an array. 
// Write a recursive function which prints true if the array is sorted in Increasing Order, and false otherwise.

#include<iostream>
using namespace std;

bool sorted_array(int a[], int i, int n) {
	if (i == n)
		return true;
	if (i != n-1 && a[i] > a[i+1])
		return false;
	return sorted_array(a, i+1, n);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	sorted_array(a, 0, n) ? cout << "true" : cout << "false";
	return 0;
}