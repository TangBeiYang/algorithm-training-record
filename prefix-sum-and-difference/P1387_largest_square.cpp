/*
Problem: P1387 Largest Square
Source: https://www.luogu.com.cn/problem/P1387
Training List: https://www.luogu.com.cn/training/9391
Topic: Prefix Sum and Difference
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout << ans;
	return 0;
}

