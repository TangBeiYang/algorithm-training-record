/*
Problem: P3865 ST Table RMQ
Source: https://www.luogu.com.cn/problem/P3865
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: sparse-table
*/
#include <iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	const int LOG = 20;
	vector<int>arr(n + 1);
	vector<int>lg(n + 1);
	vector<vector<int>>st(n + 1, vector<int>(LOG));
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		st[i][0] = arr[i];
	}
	lg[1] = 0;
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

	for (int k = 1; k <= lg[n]; k++) {
		for (int i = 1; i + (1 << k) - 1 <= n; i++) {
			st[i][k] = max(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
		}
	}
	while (m--) {
		int l, r; cin >> l >> r;
		int lg_len = lg[r - l + 1];
		cout << max(st[l][lg_len], st[r - (1 << lg_len) + 1][lg_len]) << "\n";
	}
	return 0;
}

