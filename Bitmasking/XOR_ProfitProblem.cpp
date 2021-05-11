// find the maximum of value of a XOR b where x <= a <= b <= y.

#include<iostream>
using namespace std;

int main () {
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i=a; i<=b; i++) {
		for (int j=i+1; j<=b; j++)
			ans = max(ans, i^j);
	}
	cout << ans << endl;
	return 0;
}