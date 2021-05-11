#include<iostream>
using namespace std;

int pivot(int a[], int s, int e) {
	int i = s-1;
	int j = s;
	int p = a[e];
	while (j <= e-1) {
		if (a[j] <= p) {
			i++;
			swap(a[i], a[j]);
		}
		j++;
	}
	swap(a[i+1], a[e]);
	return i+1;
}

void quicksort(int a[], int s, int e) {
	if (s >= e)
		return;
	int p = pivot(a, s, e);
	quicksort(a, s, p-1);
	quicksort(a, p+1, e);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	quicksort(a, 0, n-1);
	for (auto x: a)
		cout << x << " ";
	return 0;
}