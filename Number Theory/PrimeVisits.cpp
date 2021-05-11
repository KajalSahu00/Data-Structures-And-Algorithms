// find the number of primes in between a and b(inclusive) for t test cases.

#include<iostream>
using namespace std;
int a[1000005] = {0};
int p[1000005] = {0};

void primeSieve() {
	a[2] = 1;
	for (int i=3; i<=1000000; i+=2)
		a[i] = 1;
	for (int i=2; i*i<=1000000; i++) {
		if (a[i]) {
			for (int j=i*i; j<=1000000; j+=i)
				a[j] = 0;
		}
	}
	int cnt = 0;
	for (int i=0; i<=1000000; i++) {
		if (a[i])
			cnt++;
		p[i] = cnt;
	}
}

int main() {
	primeSieve();
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << p[b] - p[a-1] << endl;
	}
	return 0;
}