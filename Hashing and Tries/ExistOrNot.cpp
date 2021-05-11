#include<iostream>
#include<map>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;
		map<int, int> m;
		for (int i=0; i<n; i++) {
			cin >> x;
			m[x] = 0;
		}
		int q;
		cin >> q;
		while (q--) {
			cin >> x;
			if (m.find(x) != m.end())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}