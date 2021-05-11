// Given three numbers a,b,c. Calculate (a^b)mod c.

#include<iostream>
using namespace std;
#define ll long long int 

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = 1;
	for (int i=0; i<b; i++) {
		ans = (ans * a) % c;
	}
	cout << ans << endl;
	return 0;
}