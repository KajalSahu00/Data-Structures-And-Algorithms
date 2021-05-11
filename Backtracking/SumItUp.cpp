#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
set<vector<int>> s;

void possible_combination(int a[], int i, int n, vector<int> v, int sum, int target) {
	if (i == n) 
		return;
	if (sum == target) {
		s.insert(v);
		return;
	}
	if (sum > target)
		return;
	possible_combination(a, i+1, n, v, sum, target);
	v.push_back(a[i]);
	possible_combination(a, i+1, n, v, sum+a[i], target);
	v.pop_back();
	return;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) 
		cin >> a[i];
	int target;
	cin >> target;
	vector<int> v;
	sort(a, a+n);
	possible_combination(a, 0, n, v, 0, target);
	for (auto it=s.begin(); it != s.end(); it++) {
		for (auto x: *it) 
			cout << x << " ";
		cout << endl;
	}
	return 0;
}