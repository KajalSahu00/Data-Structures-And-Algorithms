#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	stack<int> s;
	for (int i=0; i<n; i++) {
		while (!s.empty() && a[i] >= a[s.top()]) {
			s.pop();
		}
		if (!s.empty()) {
			int temp = i - s.top();
			cout << temp << " ";
		}else {
			cout << i+1 << " ";
		}
		s.push(i);
	}
	cout << "END" << endl;
	return 0;
}