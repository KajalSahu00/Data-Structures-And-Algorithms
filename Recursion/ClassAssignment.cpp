#include<iostream>
using namespace std;

int assignment(int n) {
	if (n == 1 || n == 2)
		return n+1;
	return assignment(n-1) + assignment(n-2);
}

int main() {
	int t;
	cin >> t;
	int temp = 1;
	while (t--) {
		int n;
		cin >> n;
		int ans = assignment(n);
		cout << "#" << temp << " : " << ans << endl;
		temp++;
	}
	return 0;
}