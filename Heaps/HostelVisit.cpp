#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
#define ll long long

int main() {
	ll q, k;
	cin >> q >> k;
	priority_queue<ll> pq;
	while (q--) {
		ll type;
		cin >> type;
		if (type == 1) {
			ll x, y;
			cin >> x >> y;
			ll dist = pow(x, 2) + pow(y, 2);
			if (pq.size() < k) 
				pq.push(dist);
			else {
				if (dist < pq.top()) {
					pq.pop();
					pq.push(dist);
				}
			}
		}else {
			cout << pq.top() << endl;
		}
	}
	return 0;
}