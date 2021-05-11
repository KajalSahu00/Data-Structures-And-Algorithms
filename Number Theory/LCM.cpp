// Write a function which returns the LCM of N1 and N2. Print the value returned.

#include<iostream>
using namespace std;
#define ll long long int 

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	ll a, b;
	cin >> a >> b;
	ll hcf = gcd(a, b);
	ll lcm = (a * b) / hcf;
	cout << lcm << endl;
	return 0;
}