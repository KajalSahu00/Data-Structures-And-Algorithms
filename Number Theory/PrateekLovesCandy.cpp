// Find the nth prime number for q queries.

#include<iostream>
using namespace std;
int a[1000005] = {0};
int b[1000005] = {0};

void primes() {
	a[2] = 1;
	for (int i=3; i<=1000000; i+=2)
		a[i] = 1;
	for (int i=2; i*i<=1000000; i++) {
		if (a[i]) {
			for (int j=i*i; j<=1000000; j+=i) 
				a[j] = 0;
		}
	}
	int k = 0;
	for (int i=2; i<=1000000; i++) {
		if (a[i]) {
			b[k] = i;
			k++;
		}
	}
}

int main() {
	primes();
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << b[n-1] << endl;
	}
	return 0;
}
