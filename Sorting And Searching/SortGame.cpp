#include<iostream>
#include<algorithm>
using namespace std;
pair<string, int> a[100];

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		return (a.first < b.first) ? true: false;
	}
	return (a.second > b.second) ? true: false;
}
 
int main() {
	int x, n;
	cin >> x >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a, a+n, compare);
	for (int i=0; i<n; i++) {
		if (a[i].second < x)
			break;
		cout << a[i].first << " " << a[i].second << endl;
	}
	return 0;
}