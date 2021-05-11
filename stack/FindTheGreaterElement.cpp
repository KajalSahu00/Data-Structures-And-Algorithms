#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[2*n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=n; i<2*n; i++)
		a[i] = a[i-n];
	int nge[2*n];
	stack<int> st;
	for (int i=2*n-1; i>=0; i--) {
		while (!st.empty() && a[i] >= st.top()) {
			st.pop();
		}
		if (st.empty())
			nge[i] = -1;
		else 
			nge[i] = st.top();
		st.push(a[i]);
	}
	for (int i=0; i<n; i++)
		cout << nge[i] << " ";
	return 0;
}