/*
Problem: P1757 Group Knapsack
Source: https://www.luogu.com.cn/problem/P1757
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Knapsack DP
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m; cin >> m >> n;
	vector<vector<pair<int, int>>> grp(10001);
	int t = 0;
	for (int i = 0; i < n; i++) {
		int w, v, c;
		cin >> w >> v >> c;
		t = max(t, c);
		grp[c].push_back({ w,v });
	}
	vector<int> dp(m + 1, 0);
	for (int c = 1; c <= t; c++) {
		for (int j = m; j >= 0; j--) {
			for (auto [w, v] : grp[c]) {
				if (j >= w) dp[j] = max(dp[j], dp[j - w] + v);
			}
		}
	}
	cout << dp[m];
	return 0;
}

