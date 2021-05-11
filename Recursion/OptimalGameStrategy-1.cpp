// Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn where 'n' is always even. 
// They take alternate terms. In each turn, a player picks either the first coin or the last coin from the row and removes 
// it from the row. The value of coin is received by that player. Determine the maximum value that Piyush can win with if he 
// moves first. Both the players play optimally.

#include<iostream>
#include<cstring>
using namespace std;

int piyush_coins_count(int a[], int n) {
	int table[n][n];
	memset(table, 0, sizeof(table));
	for (int gap=0; gap<n; gap++) {
		for (int i=0, j=gap; j<n; j++, i++) {
			if (gap == 0)
				table[i][j] = a[j];
			else if (gap == 1)
				table[i][j] = max(a[i], a[j]);
			else {
				int x = a[i] + min(table[i+2][j], table[i+1][j-1]);
				int y = a[j] + min(table[i+1][j-1], table[i][j-2]);
				table[i][j] = max(x, y);
			}
		}
	}
	return table[0][n-1];
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
		cin >> a[i];
	cout << piyush_coins_count(a, n) << endl;
	return 0;
}