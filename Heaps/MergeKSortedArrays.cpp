#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define node pair<int, pair<int, int>>

int main() {
	int k, n;
	cin >> k >> n;
	int a[k][n];
	for (int i=0; i<k; i++) {
		for (int j=0; j<n; j++)
			cin >> a[i][j];
	}
	vector<int> res;
	priority_queue<node, vector<node>, greater<node>> pq;
	for (int i=0; i<k; i++) 
		pq.push({a[i][0], {i, 0}});
	while (!pq.empty()) {
		node temp = pq.top();
		pq.pop();
		res.push_back(temp.first);
		int x = temp.second.first;
		int y = temp.second.second;
		if (y+1 < n)
			pq.push({a[x][y+1], {x, y+1}});
	}
	for(auto x: res)
		cout << x << " ";
	return 0;
}