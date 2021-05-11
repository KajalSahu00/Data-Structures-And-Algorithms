#include<iostream>
#include<cmath>
using namespace std;

bool check(int a[][9], int num, int r, int c, int n) {
	for (int i=0; i<n; i++) {
		if (a[i][c] == num || a[r][i] == num)
			return false;
	}
	int s = sqrt(n);
	int x = (r/s) * s;
	int y = (c/s) * s;
	for (int i=x; i<x+s; i++) {
		for (int j=y; j<y+s; j++) {
			if (a[i][j] == num)
				return false;
		}
	}
	return true;
}

void sudoku_solver(int a[][9], int r, int c, int n) {
	if (r == n) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		return;
	}
	if (c == n)
		sudoku_solver(a, r+1, 0, n);
	if (a[r][c] != 0)
		sudoku_solver(a, r, c+1, n);
	else {
		for (int i=1; i<=n; i++) {
			if (check(a, i, r, c, n)) {
				a[r][c] = i;
				sudoku_solver(a, r, c+1, n);
			}
		}
		a[r][c] = 0;
		return;
	}
}

int main() {
	int n;
	cin >> n;
	int a[9][9]; 
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) 
			cin >> a[i][j];
	}
	sudoku_solver(a, 0, 0, n);
	return 0;
}