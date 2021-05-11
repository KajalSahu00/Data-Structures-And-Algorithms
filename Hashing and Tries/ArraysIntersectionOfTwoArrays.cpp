#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	map<int, int> m;
	vector<int> v;
	for (int i=0; i<n; i++) {
		cin >> x;
		m[x]++;
	}
	for (int i=0; i<n; i++) {
		cin >> x;
		if (m.find(x) != m.end()) {
			if (m[x] > 0) {
				v.push_back(x);
				m[x]--;
			}
		}
	}
	cout << '[';
	sort(v.begin(), v.end());
	cout << v.front();
	for (int i=1; i<v.size(); i++) {
		cout << ", " << v[i];
	}	
	cout << ']' << endl;
	return 0;
}