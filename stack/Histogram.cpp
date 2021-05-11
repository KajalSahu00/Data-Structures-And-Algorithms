#include<iostream>
#include<stack>
#include<climits>
using namespace std;
#define ll long long int

int main() {
	ll n;
	cin >> n;
	ll a[n];
	for (ll i=0; i<n; i++)
		cin >> a[i];
	stack<ll> s;
	ll area = INT_MIN, temp, x;
	for (ll i=0; i<n; i++) {
		while (!s.empty() && a[i] < a[s.top()]) {
			x = s.top();
			s.pop();
			if (s.empty()) 
				temp = a[x] * i;
			else 
				temp = a[x] * (i - s.top() - 1);
			area = max(area, temp);
		}
		s.push(i);
	}
	while (!s.empty()) {
		x = s.top();
		s.pop();
		if (s.empty()) 
			temp = a[x] * (n);
		else
			temp = a[x] * (n - s.top() - 1);
		area = max(temp, area);
	}
	cout << area << endl;
	return 0;
}