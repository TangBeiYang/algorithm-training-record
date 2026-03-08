/*
Problem: P4170 Painting
Source: https://www.luogu.com.cn/problem/P4170
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Interval DP
*/
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
int main() {
	string s; cin >> s;
	int n = 0;
	for (; s[n] != '\0'; n++);
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)dp[i][i] = 1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			dp[l][r] = dp[l][r - 1] + 1;
			for (int k = l; k < r; k++) {
				if (s[k - 1] == s[r - 1]) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r - 1]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}

