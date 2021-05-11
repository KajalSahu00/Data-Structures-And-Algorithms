#include<iostream>
using namespace std;
int a[1000000];

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int key;
	cin >> key;
	int s = 0, e = n-1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			cout << mid << endl;
			break;
		}
		else if (a[s] <= a[mid]) {
			if (key >= a[s] && key <= a[mid])
				e = mid - 1;
			else
				s = mid + 1;
		}else {
			if (key >= a[mid] && key <= a[e])
				s = mid + 1;
			else
				e = mid - 1;
		}
	}
	return 0;
}