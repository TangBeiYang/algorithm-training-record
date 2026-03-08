/*
Problem: P1063 Energy Necklace
Source: https://www.luogu.com.cn/problem/P1063
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Interval DP
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	vector<pair<int, int>>node(2 * n + 1);
	vector<vector<int>>dp(2 * n + 1, vector<int>(2 * n + 1,0));
	node[0] = { a[n - 1],a[0] };
	for (int i = 1; i <= 2 * n; i++) node[i] = { node[i - 1].second,a[i % n] };
	for (int i = 1; i <= 2 * n; i++) dp[i][i] = 0;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= 2 * n; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				int cost = node[k].second * node[l].first * node[r].second;
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + cost);
			}
		}
	}
	int best = 0;
	for (int i = 0; i < n; i++) best = max(dp[i + 1][i + n], best);
	cout << best;
	return 0;
}

