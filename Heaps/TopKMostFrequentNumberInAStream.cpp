#include<bits/stdc++.h>
using namespace std;
#define p pair<int, int>

class mycmp {
	public:
		bool operator()(p a, p b) {
			if (a.second == b.second)
				return a.first > b.first;
			else
				return a.second < b.second;
		}
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int x;
		unordered_map<int, int> m;
		for (int i=0; i<n; i++) {
			cin >> x;
			m[x]++;
			priority_queue<p, vector<p>, mycmp> pq(m.begin(), m.end());
			int cnt = 0;
			while (!pq.empty() && cnt < k) {
				cout << pq.top().first << " ";
				pq.pop();
				cnt++;
			}
		}
		cout << endl;
	}
	return 0;
}