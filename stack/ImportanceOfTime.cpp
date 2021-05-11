#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q1;
	queue<int> q2;
	int a[n], x;
	for (int i=0; i<n; i++) {
		cin >> x;
		q1.push(x);
	}
	for (int i=0; i<n; i++) {
		cin >> x;
		q2.push(x);
	}
	int time = 0;
	while (!q2.empty()) {
		if (q1.front() == q2.front()) {
			time += 1;
			q1.pop();
			q2.pop();
		}else {
			while (q2.front() != q1.front()) {
				int temp = q1.front();
				q1.pop();
				q1.push(temp);
				time += 1;
			}
			time += 1;
			q1.pop();
			q2.pop();
		}
	}
	cout << time << endl;
	return 0;
}