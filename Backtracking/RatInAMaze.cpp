#include<iostream>
using namespace std;
int sol[1000][1000] = {0};
char mat[1000][1000];

bool rat_maze(int r, int c, int n, int m) {
	if (r == n-1 && c == m-1) {
		sol[r][c] = 1;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cout << sol[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}
	if (r >= n || c >= m)
		return false;
	if (mat[r][c] == 'X')
		return false;
	sol[r][c] = 1;
	bool rightSuccess = rat_maze(r, c+1, n, m);
	bool downSuccess = false;
	if (!rightSuccess)
		downSuccess = rat_maze(r+1, c, n, m);
	sol[r][c] = 0;
	if (rightSuccess || downSuccess) {
		return true;
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			cin >> mat[i][j];
	}
	if (!rat_maze(0, 0, n, m))
		cout << "-1" << endl;
	return 0;
}