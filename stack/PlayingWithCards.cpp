#include<iostream>
#include<bitset>
#include<vector>
#include<stack>
using namespace std;
bitset<1000005> b;
vector<int> primes;
int n = 1000000;

void prime_sieve() {
	b.set();
	b[0] = b[1] = 0;
	for (int i=2; i*i<=n; i++) {
		if (b[i]) {
			primes.push_back(i);
			for (int j=i*i; j<=n; j+=i) 
				b[j] = 0;
		}
	}
}

int main() {
	prime_sieve();
	int n, q, i = 0, temp;pla
	cin >> n >> q;
	stack<int> s1, s2, s3;
	while (i++ < n) {
		cin >> temp;
		s1.push(temp);
	}
	for (int i=0; i<q; i++) {
		if (s1.empty())
			break;
		while (!s1.empty()) {
			int x = s1.top();
			s1.pop();
			if (x % primes[i] == 0) {
				s2.push(x);
			}else {
				s3.push(x);
			}
		}
		while (!s2.empty()) {
			cout << s2.top() << endl;
			s2.pop();
	    }
		s1 = s3;
		while (!s3.empty()) 
			s3.pop();
	}
	while (!s1.empty()) {
		cout << s1.top() << endl;
		s1.pop();
	}
	return 0;
}