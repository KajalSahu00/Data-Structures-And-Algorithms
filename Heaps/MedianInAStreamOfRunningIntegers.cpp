#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        cin >> x;
        pq1.push(x);
        int med = x;
        cout << med << " ";
        for (int i=1; i<n; i++) {
            cin >> x;
            if (pq1.size() > pq2.size()) {
                if (x > med) 
                    pq2.push(x);
                else {
                    pq2.push(pq1.top());
                    pq1.pop();
                    pq1.push(x);
                }
                med = (pq1.top() + pq2.top()) / 2;
            }
            else if (pq1.size() == pq2.size()) {
                if (x < med) {
                    pq1.push(x);
                    med = pq1.top();
                }
                else {
                    pq2.push(x);
                    med = pq2.top();
                }
            }
            else {
                if (x < med)
                    pq1.push(x);
                else {
                    pq1.push(pq2.top());
                    pq2.pop();
                    pq2.push(x);
                }
                med = (pq1.top() + pq2.top()) / 2;
            }
            cout << med << " ";
        }
        cout << endl;
    }
    return 0;
}