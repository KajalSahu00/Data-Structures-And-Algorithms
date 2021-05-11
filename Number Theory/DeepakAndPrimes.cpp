// Deepak is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

#include<iostream>
using namespace std;
int a[1000005] = {0};

void primeSieve() {
	a[2] = 1;
	for (int i=3; i<=1000000; i+=2)
		a[i] = 1;
	for (int i=2; i*i<=1000000; i++) {
		if (i) {
			for (int j=i*i; j<=1000000; j+=i) 
				a[j] = 0;
		}
	}
}

int main() {
	primeSieve();
	int n;
	cin >> n;
	int cnt = 0;
	for (int i=0; i<=1000000; i++) {
		if (a[i])
			cnt++;
		if (cnt == n) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}