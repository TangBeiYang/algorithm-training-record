/*
Problem: P3146 248
Source: https://www.luogu.com.cn/problem/P3146
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Interval DP
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, best = 0; cin >> n;
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
	vector<int> a(2 * n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) dp[i][i] = a[i], best = max(best, a[i]);
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				if (dp[l][k] != 0 && dp[l][k] == dp[k + 1][r]) {
					dp[l][r] = max(dp[l][k] + 1, dp[l][r]);
				}
			}
			best = max(best, dp[l][r]);
		}
	}
	cout << best;
	return 0;
}

