#include<iostream>
using namespace std;

void move_all_x_at_end(char a[], int i) {
	if (a[i] == '\0')
		return;
	if (a[i] == 'x') {
		int j = i;
		while (a[j+1] != '\0')
			j++;
		int temp = i;
		while (temp <= j) {
			a[temp] = a[temp+1];
			temp++; 
		}
		a[j] = 'x';
	}
	move_all_x_at_end(a, i+1);
}

int main() {
	char a[1000];
	cin >> a;
	move_all_x_at_end(a, 0);
	cout << a << endl;
	return 0;
}