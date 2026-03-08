/*
Problem: P1219 Checker Challenge
Source: https://www.luogu.com.cn/problem/P1219
Training List: https://www.luogu.com.cn/training/9391
Topic: Search
*/
#include<iostream>
#include<vector>
using namespace std;
int res = 0;
int printed = 0;
vector<int>pos;
vector<int>colused;
vector<int>diag1;
vector<int>diag2;
void find(int n,int row) {
	if (row == n + 1) {
		res++;
		if (printed < 3) {
			for (int i = 0; i < n; i++)cout << pos[i+1] << " ";
			cout << endl;
			printed++;
		}
		return;
	}
	for (int col = 1; col <= n; col++) {
		int d1 = row - col + n;
		int d2 = row + col;
		if (colused[col] || diag1[d1] || diag2[d2]) continue;
		pos[row] = col;
		colused[col] = diag1[d1] = diag2[d2] = 1;
		find(n, row + 1);
		colused[col] = diag1[d1] = diag2[d2] = 0;
	}
}
int main() {
	int n; cin >> n;
	pos.assign(n + 1, 0);
	colused.assign(n + 1, 0);
	diag1.assign(2 * n + 1, 0);
	diag2.assign(2 * n + 1, 0);
	find(n, 1);
	cout << res;
	return 0;
}

