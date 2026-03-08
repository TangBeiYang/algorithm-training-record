/*
Problem: P1048 Herb Gathering
Source: https://www.luogu.com.cn/problem/P1048
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Knapsack DP
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, m; cin >> t >> m;
	vector<int>dp(t + 1, 0);
	vector<pair<int, int>>a(m);
	for (int i = 0; i < m; i++) {
		int ti, val; cin >> ti >> val;
		a[i] = { ti,val };
	}
	for (int i = 0; i < m; i++) {
		for (int j = t; j > 0; j--) {
			auto [ti, val] = a[i];
			if (ti <= j)dp[j] = max(dp[j - ti] + val, dp[j]);
			else dp[j] = dp[j];
		}
	}
	cout << dp[t];
	return 0;
}

