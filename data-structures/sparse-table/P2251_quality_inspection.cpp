/*
Problem: P2251 Quality Inspection
Source: https://www.luogu.com.cn/problem/P2251
Training List: https://www.luogu.com.cn/training/9391
Topic: Data Structures
Subtopic: sparse-table
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	const int LOG = 21;
	vector<vector<int>>st(n + 1, vector<int>(LOG));
	vector<int>lg(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> st[i][0];
	lg[1] = 0;
	for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
	for (int k = 1; k <= lg[n]; k++) {
		for (int i = 1; i + (1 << k) - 1 <= n; i++) {
			st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
		}
	}
	int lg_len = lg[m];
	for (int i = 1; i + m - 1 <= n; i++) {
		cout << min(st[i][lg_len], st[i + m - (1 << lg_len)][lg_len]) << "\n";
	}
	return 0;
}

