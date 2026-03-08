//P3131 [USACO16JAN] Subsequences Summing to Sevens S
/*#include<iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int id[50000];
	for (int i = 0; i < n; i++) cin >> id[i];
	long long sum[50001];
	sum[0] = 0;
	int modl[7], modr[7];
	for (int i = 1; i <= n; i++)sum[i] = (sum[i - 1] + id[i - 1]) % 7;
	int first[7], last[7];
	for (int k = 0; k < 7; k++) first[k] = -1, last[k] = -1;
	for (int i = 0; i <= n; i++) {
		int mod = sum[i];
		if (first[mod] == -1) first[mod] = i;
		last[mod] = i;
	}
	int res = 0;
	for (int mod = 0; mod < 7; mod++) {
		if (first[mod] != -1) res = max(res, last[mod] - first[mod]);
	}
	cout << res;
	return 0;
}*/
//P1387 最大正方形
/*#include <iostream>
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
}*/