/*
Problem: P5020 Currency System
Source: https://www.luogu.com.cn/problem/P5020
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
	int T; cin >> T;
	for (int o = 0; o < T; o++) {
		int n; cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a.begin(), a.end());
		vector<int>currency;
		vector<bool>dp(a[n - 1] + 1, 0);
		currency.push_back(a[0]); dp[a[0]] = 1;
		for (int i = 1; i < n; i++) {
			int price = a[i];
			for (int j = a[i - 1] + 1; j <= price; j++) {
				for (int p : currency) {
					dp[j] = dp[j] || dp[j - p];
					if (dp[j])break;
				}
			}
			if (dp[price])continue;
			currency.push_back(price); dp[price] = 1;
		}
		cout << currency.size() << endl;
	}
	return 0;
}

