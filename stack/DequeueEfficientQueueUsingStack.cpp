#include<iostream>
#include<stack>
using namespace std;

class queue {
	stack<int> s1;
	stack<int> s2;
	public:
		void enqueue(const int i) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(i);
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
		void dequeue() {
			s1.pop();
		}
		int front() const {
			return s1.top();
		}
		bool empty() const {
			return s1.size() == 0;
		}
		int size() const {
			return s1.size();
		} 
};

int main() {
	int n;
	cin >> n;
	queue q;
	for (int i=0; i<n; i++) 
		q.enqueue(i);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.dequeue();
	}
	return 0;
}