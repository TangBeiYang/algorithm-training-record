/*
Problem: P1868 Hungry Cows
Source: https://www.luogu.com.cn/problem/P1868
Training List: https://www.luogu.com.cn/training/9391
Topic: Dynamic Programming - Linear DP
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n; cin >> n;
	vector<pair<int, int>>a(n, { 0,0 });
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		s = max(s, a[i].second);
	}
	vector<vector<int>>endy(s + 2);
	for (int i = 0; i < n; i++)endy[a[i].second + 1].push_back(a[i].first);
	vector<int>dp(s + 2, 0);
	dp[0] = 0;
	for (int i = 1; i < s + 2; i++) {
		int k = endy[i].size();
		int best = dp[i - 1];
		for (int j = 0; j < k; j++) {
			int x = endy[i][j], y = i - 1;
			best = max(best, dp[x] + y - x + 1);
		}
		dp[i] = best;
	}
	cout << dp[s + 1];
	return 0;
}

