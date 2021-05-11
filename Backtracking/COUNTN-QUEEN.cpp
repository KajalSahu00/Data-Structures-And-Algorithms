#include<iostream>
#include<bitset>
using namespace std;
bitset <11> col, ld, rd;

void n_queen(int i, int n, int &ans) {
	if (i == n) {
		ans++;
		return;
	}
	for (int j=0; j<n; j++) {
		if (!col[j] && !ld[i+j] && !rd[i-j+n-1]) {
			col[j] = ld[i+j] = rd[i-j+n-1] = 1;
			n_queen(i+1, n, ans);
			col[j] = ld[i+j] = rd[i-j+n-1] = 0;
		}
	}
	return;
}

int main() {
	int n;
	cin >> n;
	int ans = 0;
	n_queen(0, n, ans);
	cout << ans << endl;
	return 0;
}